from launch import LaunchDescription
from launch_ros.actions import Node

def generate_launch_description():
    """
    Generate a launch description that starts both publisher and subscriber nodes
    """
    return LaunchDescription([
        # Publisher node
        Node(
            package='my_ros2_package',
            executable='publisher_node',
            name='publisher',
            output='screen',
            emulate_tty=True,
        ),
        
        # Subscriber node
        Node(
            package='my_ros2_package',
            executable='subscriber_node',
            name='subscriber',
            output='screen',
            emulate_tty=True,
        ),
    ])
    