import rclpy
import RPi.GPIO as GPIO
from rclpy.node import Node
from sensor_msgs.msg import Range
from .sonar import Sonar  # Assuming your modified Sonar class is in this file
import math

class SonarArrayNode(Node):  # Changed class name to follow ROS 2 convention
    def __init__(self):
        super().__init__('sonar_array_node')  

        self.sonar_array = []
        self.pub_array = []
        self.num_sonar = 3  # Assuming you have 3 sonars

        # Load sonar configuration parameters
        self.declare_parameter('angle_min_deg', -30.0)
        self.declare_parameter('angle_max_deg', 30.0)
        self.declare_parameter('range_min', 0.2)
        self.declare_parameter('range_max', 3.5)

        angle_min_deg = self.get_parameter('angle_min_deg').get_parameter_value().double_value
        angle_max_deg = self.get_parameter('angle_max_deg').get_parameter_value().double_value
        range_min = self.get_parameter('range_min').get_parameter_value().double_value
        range_max = self.get_parameter('range_max').get_parameter_value().double_value

        delta_angle_deg = (angle_max_deg - angle_min_deg) / (self.num_sonar - 1)

        # Create sonars and publishers
        for i in range(self.num_sonar):
            # Get GPIO pin numbers from parameters (adjust names if needed)
            trigger_pin_name = f'sonar_{i}_trigger_pin'
            echo_pin_name = f'sonar_{i}_echo_pin'
            self.declare_parameter(trigger_pin_name, 0)  # Default to 0 if not provided
            self.declare_parameter(echo_pin_name, 0)     # Default to 0 if not provided

            trigger_pin = self.get_parameter(trigger_pin_name).get_parameter_value().integer_value
            echo_pin = self.get_parameter(echo_pin_name).get_parameter_value().integer_value

            if trigger_pin == 0 or echo_pin == 0:
                self.get_logger().error(f"Missing GPIO pin configuration for sonar {i}")
                continue  # Skip this sonar if pins are not configured

            sonar = Sonar(trigger_pin, echo_pin, range_min*100, range_max*100)
            angle_deg = angle_min_deg + delta_angle_deg * i
            sonar.angle = math.radians(angle_deg)
            self.sonar_array.append(sonar)

            topic_name = f'sonar_{i}_range'
            pub = self.create_publisher(Range, topic_name, 10)  # QoS profile set to 10
            self.pub_array.append(pub)

        # Default Range message
        self.message = Range()
        self.message.radiation_type = Range.ULTRASOUND
        self.message.min_range = range_min
        self.message.max_range = range_max

        # Timer to periodically scan the sonars
        timer_period = 0.5 # seconds
        self.timer = self.create_timer(timer_period, self.scan_and_publish)
    
    def scan_and_publish(self):
       # ranges = []
        for i, sonar in enumerate(self.sonar_array):
            range_cm = sonar.get_range()
            if range_cm > 0:  # Check for valid reading
                self.message.range = range_cm / 100.0  # Convert to meters
                self.message.field_of_view = sonar.angle
                self.message.header.stamp = self.get_clock().now().to_msg()
                self.pub_array[i].publish(self.message)

                # Store range for combined logging
                #ranges.append(range_cm / 100.0)  

        # Log all ranges in one line
        #if len(ranges) == self.num_sonar:
            #self.get_logger().info(f'Ranges (m): Center: {ranges[1]:.1f}, Left: {ranges[0]:.1f}, Right: {ranges[2]:.1f}')  

def main(args=None):
    rclpy.init(args=args)

    sonar_array_node = SonarArrayNode()

    rclpy.spin(sonar_array_node)
    
    # Clean up GPIO on shutdown
    GPIO.cleanup()

    rclpy.shutdown()

if __name__ == '__main__':
    main()