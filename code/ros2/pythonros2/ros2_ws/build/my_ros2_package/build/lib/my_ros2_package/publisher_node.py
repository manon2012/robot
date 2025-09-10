#!/usr/bin/env python3

import rclpy
from rclpy.node import Node
from std_msgs.msg import String
import time

class SimplePublisher(Node):
    """
    A simple ROS2 publisher node that sends messages periodically
    """
    def __init__(self):
        super().__init__('simple_publisher')  # Node name
        
        # Create publisher for String messages on topic 'chatter'
        self.publisher_ = self.create_publisher(String, 'chatter', 10)
        
        # Create timer to publish messages every 1 second
        timer_period = 1.0  # seconds
        self.timer = self.create_timer(timer_period, self.timer_callback)
        
        self.counter = 0
        self.get_logger().info('Publisher node started!')

    def timer_callback(self):
        """
        Callback function called by the timer
        """
        # Create a new message
        msg = String()
        msg.data = f'Hello ROS2! Message #{self.counter}'
        
        # Publish the message
        self.publisher_.publish(msg)
        
        # Log the publication
        self.get_logger().info(f'Publishing: "{msg.data}"')
        
        self.counter += 1

def main(args=None):
    """
    Main function to initialize and run the publisher node
    """
    # Initialize ROS2 Python client library
    rclpy.init(args=args)
    
    # Create the publisher node
    publisher_node = SimplePublisher()
    
    try:
        # Keep the node running until interrupted
        rclpy.spin(publisher_node)
    except KeyboardInterrupt:
        # Handle Ctrl+C gracefully
        pass
    finally:
        # Cleanup
        publisher_node.destroy_node()
        rclpy.shutdown()

if __name__ == '__main__':
    main()