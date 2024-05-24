import rclpy
from rclpy.node import Node
from geometry_msgs.msg import Twist  # Import Twist for velocity commands
from serial_motor_demo_msgs.msg import MotorCommand
from serial_motor_demo_msgs.msg import SteeringCommand 
import time
import math
import serial
from threading import Lock


class MotorDriver(Node):

    def __init__(self):
        super().__init__('motor_driver')

        # Setup parameters (remove encoder-related parameters)
        self.declare_parameter('loop_rate', value=30)
        if (self.get_parameter('loop_rate').value == 0):
            print("WARNING! LOOP RATE SET TO 0!!")

        self.declare_parameter('serial_port', value="/dev/ttyACM0")
        self.serial_port = self.get_parameter('serial_port').value

        self.declare_parameter('baud_rate', value=57600)
        self.baud_rate = self.get_parameter('baud_rate').value

        self.declare_parameter('serial_debug', value=False)
        self.debug_serial_cmds = self.get_parameter('serial_debug').value
        if (self.debug_serial_cmds):
            print("Serial debug enabled")

        # Setup topics & services
        self.subscription = self.create_subscription(
            MotorCommand,
            'motor_command',
            self.motor_command_callback,
            10)
        
        self.subscription = self.create_subscription(
            SteeringCommand,
            'steer_commands',  
            self.servo_command_callback,
            10)
        
                # Joy Subscription
        self.joy_sub = self.create_subscription(
            Twist,
            'cmd_vel',  # Use the standard 'cmd_vel' topic
            self.joy_callback,
            10 
        )

        # Member Variables
        self.mutex = Lock()

        # Open serial comms
        print(f"Connecting to port {self.serial_port} at {self.baud_rate}.")
        self.conn = serial.Serial(self.serial_port, self.baud_rate, timeout=1.0)
        print(f"Connected to {self.conn}")

    
        # Parameters for steering geometry and limits
        self.declare_parameter('wheelbase', 65) 
        self.wheelbase = self.get_parameter('wheelbase').get_parameter_value().double_value  
        self.declare_parameter('track_width', 63.5)
        self.track_width = self.get_parameter('track_width').get_parameter_value().double_value  
        self.declare_parameter('max_steering_angle', 45.0)
        self.max_steering_angle = self.get_parameter('max_steering_angle').get_parameter_value().double_value   
        self.declare_parameter('servo_zero_offset', 90.0)
        self.servo_zero_offset = self.get_parameter('servo_zero_offset').get_parameter_value().double_value          

    # Raw serial commands 
    def send_pwm_motor_command(self, mot_1_pwm, mot_2_pwm):
        self.send_command(f"o {int(mot_1_pwm)} {int(mot_2_pwm)}")

    # More user-friendly functions
    def motor_command_callback(self, command):  
        if isinstance(command, SteeringCommand): 
            self.process_steering(command)
        elif isinstance(command, MotorCommand):
            if command.is_pwm:
                self.process_motor_command(command)  
            else:
                print("Warning: feedback control mode requested, but not supported")
        else:
            pass  # Handle unexpected message type if needed

    def process_motor_command(self, motor_command):
        mot1_pwm = motor_command.mot_1_req_rad_sec # or extract desired PWM value
        mot2_pwm = motor_command.mot_2_req_rad_sec # or extract desired PWM value
        self.send_pwm_motor_command(mot1_pwm, mot2_pwm) 

    def process_steering(self, steer_commands):  
        steering_angle = steer_commands.steering_angle
        turning_radius = steer_commands.turning_radius

        # Add parameters for vehicle dimensions
        self.wheelbase = 0.5  # Replace with your actual wheelbase
        self.track_width = 0.4  # Replace with your actual track width

        front_wheel_angle, rear_wheel_angle = calculate_ackermann(steering_angle, turning_radius)

        # Servo Configuration
        servo_min_pwm = 1000  # PWM for 0 degrees
        servo_max_pwm = 2000  # PWM for 180 degrees
        servo_angle_range = 180  

        # Linearly map steering angle to PWM for front and rear servos
        front_pwm = int(servo_min_pwm + (front_wheel_angle / servo_angle_range) * (servo_max_pwm - servo_min_pwm))
        rear_pwm = int(servo_min_pwm + (rear_wheel_angle / servo_angle_range) * (servo_max_pwm - servo_min_pwm))

 
        


        def calculate_ackermann(steering_angle, turning_radius):
            if turning_radius == 0: 
            # Handle the special case of driving straight
                return 90, 90  # Both front and rear wheels at 0 degrees

            inner_angle = math.atan2(self.wheelbase, (turning_radius - self.track_width/2)) 
            outer_angle = math.atan2(self.wheelbase, (turning_radius + self.track_width/2))
            return inner_angle, outer_angle

        
        command_string = f"h {steer_commands.steering_angle} {steer_commands.turning_radius}" # Example 
        self.send_command(command_string)  

    def servo_command_callback(self, steer_commands):  
        steering_angle = steer_commands.steering_angle
        turning_radius = steer_commands.turning_radius

        command_string = f"h {steering_angle} {turning_radius}" 
        self.send_command(command_string)

    def joy_callback(self, twist_msg):
        linear_x = twist_msg.linear.x
        angular_z = twist_msg.angular.z

        # Scale linear_x for motor PWM range (adjust max_pwm based on your setup)
        max_pwm = 255*2  # Adjust this value based on your motor PWM range
        motor_pwm = int(linear_x * max_pwm / 2.0)  # Scale and handle direction

        self.send_pwm_motor_command(motor_pwm, motor_pwm)  # Send to both motors
        # Assuming positive angular_z is right turn, negative is left
        if angular_z == 0:
            turn_direction = 0
        elif angular_z < 0:
            turn_direction = 1
        else:
            turn_direction = -1
        #turn_direction = -1 if angular_z > 0 else 1 
        JOYSTICK_RANGE = 1.0  # Assumes joystick values between -1 to 1
        SERVO_RANGE = 400  # 500 - 100 
        SERVO_MAX = 500  # Maximum servo value

        # Mapping joystick to servo range
        scaled_servo_value = SERVO_MAX - abs(angular_z) * JOYSTICK_RANGE * SERVO_RANGE 


            # Ensure value stays within the desired range
        servo_value = max(50, min(500, scaled_servo_value)) 

        # Construct servo command string
        servo_command = f"h {turn_direction} {servo_value}"

        # Send motor and servo commands using your existing functions
        
        self.send_command(servo_command)  # Send servo command




    # Utility functions
    def send_command(self, cmd_string):
        self.mutex.acquire()
        try:
            cmd_string += "\r"
            self.conn.write(cmd_string.encode("utf-8"))
            if (self.debug_serial_cmds):
                print("Sent: " + cmd_string)

            ## Adapted from original
            c = ''
            value = ''
            while c != '\r':
                c = self.conn.read(1).decode("utf-8")
                if (c == ''):
                    print("Error: Serial timeout on command: " + cmd_string)
                    return ''
                value += c

            value = value.strip('\r')

            if (self.debug_serial_cmds):
                print("Received: " + value)
            return value
        finally:
            self.mutex.release()

    def close_conn(self):
        self.conn.close()

def main(args=None):
    rclpy.init(args=args)
    motor_driver = MotorDriver()
    rclpy.spin(motor_driver)  # No more rate or encoder checks needed 
    motor_driver.close_conn()
    motor_driver.destroy_node()
    rclpy.shutdown()