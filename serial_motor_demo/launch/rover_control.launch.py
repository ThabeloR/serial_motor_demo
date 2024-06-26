import os
import launch
from launch_ros.actions import Node
from ament_index_python.packages import get_package_share_directory
from launch import LaunchDescription
from launch.substitutions import LaunchConfiguration
from launch.actions import DeclareLaunchArgument


def generate_launch_description():
    joy_params = os.path.join(get_package_share_directory('serial_motor_demo'),'config','teleop_twist_joy.yaml')
    # Joystick Nodes
    joy_node = Node(
        package='joy',
        executable='joy_node',
        parameters=[joy_params],
        name='joy'
    )

    teleop_node = Node(
        package='teleop_twist_joy',
        executable='teleop_node',
        name='teleop_node',
        parameters=[joy_params]
    )

    # Your Motor Driver Node
    motor_driver_node = Node(
        package='serial_motor_demo',
        executable='driver',  # Assuming your executable is named 'driver'
        name='motor_driver'
    )

    # Sonar Array Node
    sonar_array_node = Node(
        package='serial_motor_demo',
        executable='sonar_array',
        name='sonar_array_node',
        parameters=[
            {'angle_min_deg': -30.0},  # Adjust if needed
            {'angle_max_deg': 30.0},
            {'range_min': 0.2},
            {'range_max': 3.5},
            {'sonar_0_trigger_pin': 5},  # GPIO pins for each sonar
            {'sonar_0_echo_pin': 6},
            {'sonar_1_trigger_pin': 4},
            {'sonar_1_echo_pin': 17},
            {'sonar_2_trigger_pin': 27},
            {'sonar_2_echo_pin': 22}
        ],
        output='screen'  # Optional: to see node output on the console
    )

    # Obstacle Avoidance Node
    obst_avoid_node = Node(
        package='serial_motor_demo',
        executable='obstacle_avoid_sonar',
        name='obst_avoid_node',
        output='screen'  # Optional: to see node output on the console
    )


    return launch.LaunchDescription([
        joy_node,
        teleop_node,
        motor_driver_node,
        sonar_array_node,
       obst_avoid_node,
    ])