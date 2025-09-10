import rclpy
from rclpy.node import Node
from std_msgs.msg import String

class FastDDSSubscriber(Node):
    def __init__(self):
        super().__init__('fastdds_subscriber')
        
        # Create subscriber (uses Fast DDS underneath)
        self.subscription = self.create_subscription(
            String,
            'fastdds_topic',
            self.listener_callback,
            10)
        
        self.get_logger().info('Fast DDS Subscriber started! Waiting for messages...')
    
    def listener_callback(self, msg):
        """Callback when message is received"""
        self.get_logger().info(f'Received: "{msg.data}"')

def main(args=None):
    rclpy.init(args=args)
    subscriber = FastDDSSubscriber()
    
    try:
        rclpy.spin(subscriber)
    except KeyboardInterrupt:
        pass
    finally:
        subscriber.destroy_node()
        rclpy.shutdown()

if __name__ == '__main__':
    main()