import rclpy
from rclpy.node import Node
from sensor_msgs.msg import Range ,Joy
from geometry_msgs.msg import Twist  
from std_msgs.msg import String

import serial

class ObjectAvoidanceNode(Node):
    def __init__(self):
        super().__init__('object_avoidance_node')

        # Serial communication setup (from MotorDriver)
        self.declare_parameter('serial_port', value="/dev/ttyACM0")
        self.serial_port = self.get_parameter('serial_port').value
        self.declare_parameter('baud_rate', value=57600)
        self.baud_rate = self.get_parameter('baud_rate').value
        self.conn = serial.Serial(self.serial_port, self.baud_rate, timeout=1.0)  

        # Sonar subscriptions (assuming 3 sonars as in SonarArrayNode)
        self.sonar_ranges = [None, None, None]  # Center, Left, Right
        for i in range(3):
            self.create_subscription(
                Range,
                f'sonar_{i}_range',
                lambda msg, idx=i: self.sonar_callback(msg, idx),
                10)
        # Joy subscription to monitor button 5
        self.joy_sub = self.create_subscription(Joy, 'joy', self.joy_callback, 10)

        # State tracking (add enabled flag)
        self.state = "FORWARD"
        self.turn_time = 0.0
        self.enabled = False  # Start disabled
        
    def joy_callback(self, msg):
        if len(msg.buttons) >= 5:  # Ensure button 5 exists
            if msg.buttons[5] == 1 and not self.enabled:  # Button 5 pressed
                self.enabled = True
                self.get_logger().info("Object avoidance ENABLED")
            elif msg.buttons[5] == 0 and self.enabled:
                self.enabled = False
                self.get_logger().info("Object avoidance DISABLED")

        # State tracking
        self.state = "FORWARD"
        self.turn_time = 0.0  # Time spent turning in AVOID state
        

        # Publisher for debugging output
        self.debug_pub = self.create_publisher(String, 'object_avoidance_debug', 10)

        # Timer to control the avoidance behavior
        self.create_timer(0.5, self.control_loop)  # 10Hz loop

    def sonar_callback(self, msg, idx):
        self.sonar_ranges[idx] = msg.range
        #self.get_logger().info(f'Sonar {idx} range: {msg.range:.2f} m')

    def control_loop(self):
        # Check for missing sonar data
        if not all(r is not None for r in self.sonar_ranges):
            return  # Wait until all sonars have data

        center_range, left_range, right_range = self.sonar_ranges
        sonar_data = f"Ranges: L:{left_range:.2f}m, C:{center_range:.2f}m, R:{right_range:.2f}m" # one line sonar data
        
        # Logic for the avoidance behavior
        if self.state == "FORWARD":
            if center_range < 0.5:
                self.state = "STOP"
                self.send_command("o 0 0")  # Stop the rover
                self.get_logger().info(f"STOPPED: Object too close. {sonar_data}")
            elif left_range < 1.0 or right_range < 1.0:
                self.state = "AVOID"  
                self.turn_time = 0.0 
                if right_range > left_range: 
                    self.send_command("h 1 100")  # Turn right
                    self.send_command("o 90 90") 
                    
                    self.get_logger().info(f"AVOIDING: Object detected on the LEFT. {sonar_data}")

                else:
                    self.send_command("h -1 100")  # Turn left
                    self.send_command("o 90 90")
                    self.get_logger().info(f"AVOIDING: Object detected on the RIGHT. {sonar_data}")


        elif self.state == "AVOID":
            self.turn_time += 0.1  # Increment turn time
            if self.turn_time > 2.0: 
                self.state = "FORWARD"
                self.send_command("h 0 500")
                self.send_command("o 90 90") 
                self.get_logger().info(f"MOVING FORWARD: Turn complete or path clear. {sonar_data}")

            elif center_range < 0.5:
                self.state = "STOP"
                self.send_command("o 0 0")  # Stop the rover 
                self.get_logger().info(f"STOPPED: Object too close. {sonar_data}")
            # ... (rest of the AVOID state logic for turning)
        elif self.state == "STOP":
            if center_range > 0.5:
                self.state = "FORWARD"
                self.send_command("h 0 500")
                self.send_command("o 90 90")  # Resume moving forward
                self.get_logger().info(f"MOVING FORWARD: Turn complete or path clear. {sonar_data}")


    # Serial command function (from MotorDriver)
    def send_command(self, cmd_string):
        cmd_string += "\r"
        self.conn.write(cmd_string.encode("utf-8")) 

def main(args=None):
    rclpy.init(args=args)
    object_avoidance_node = ObjectAvoidanceNode()
    rclpy.spin(object_avoidance_node)
    object_avoidance_node.conn.close()
    rclpy.shutdown()

if __name__ == '__main__':
    main()