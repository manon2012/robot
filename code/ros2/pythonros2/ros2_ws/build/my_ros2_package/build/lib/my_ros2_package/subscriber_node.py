#!/usr/bin/env python3

import rclpy
from rclpy.node import Node
from std_msgs.msg import String

class SimpleSubscriber(Node):
    """
    A simple ROS2 subscriber node that receives messages
    """
    def __init__(self):
        super().__init__('simple_subscriber')  # Node name
        
        # Create subscriber for String messages on topic 'chatter'
        self.subscription = self.create_subscription(
            String,
            'chatter',
            self.listener_callback,
            10  # Queue size
        )
        
        # Prevent unused variable warning
        self.subscription
        
        self.get_logger().info('Subscriber node started! Waiting for messages...')

    def listener_callback(self, msg):
        """
        Callback function called when a message is received
        """
        self.get_logger().info(f'I heard: "{msg.data}"')

def main(args=None):
    """
    Main function to initialize and run the subscriber node
    """
    # Initialize ROS2 Python client library
    rclpy.init(args=args)
    
    # Create the subscriber node
    subscriber_node = SimpleSubscriber()
    
    try:
        # Keep the node running until interrupted
        rclpy.spin(subscriber_node)
    except KeyboardInterrupt:
        # Handle Ctrl+C gracefully
        pass
    finally:
        # Cleanup
        subscriber_node.destroy_node()
        rclpy.shutdown()

if __name__ == '__main__':
    main()