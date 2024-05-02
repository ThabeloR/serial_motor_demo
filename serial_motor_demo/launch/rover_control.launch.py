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

    # Add other nodes if needed ...

    return launch.LaunchDescription([
        joy_node,
        teleop_node,
        motor_driver_node,
        # ... other nodes
    ])