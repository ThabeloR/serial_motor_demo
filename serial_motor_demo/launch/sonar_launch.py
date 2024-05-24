import launch
from launch_ros.actions import Node
from launch.substitutions import LaunchConfiguration

def generate_launch_description():
    # Default parameter values
    default_angle_min_deg = LaunchConfiguration('angle_min_deg', default='-30.0')
    default_angle_max_deg = LaunchConfiguration('angle_max_deg', default='30.0')
    default_range_min = LaunchConfiguration('range_min', default='0.2')
    default_range_max = LaunchConfiguration('range_max', default='3.5')

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
        parameters=[
            # Topic remapping if necessary
            # You can comment these out if the default topic names are correct
            {'sonar_center_topic': '/sonar_1_range'},
            {'sonar_left_topic': '/sonar_0_range'},
            {'sonar_right_topic': '/sonar_2_range'}
        ],
        output='screen'  # Optional: to see node output on the console
    )


    return launch.LaunchDescription([
        sonar_array_node,
        obst_avoid_node,
    ])