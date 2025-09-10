import rclpy
from rclpy.node import Node
from std_msgs.msg import String
import time

class FastDDSPublisher(Node):
    def __init__(self):
        super().__init__('fastdds_publisher')
        
        # Create publisher (uses Fast DDS underneath)
        self.publisher = self.create_publisher(String, 'fastdds_topic', 10)
        
        # Timer to publish messages
        self.timer = self.create_timer(1.0, self.timer_callback)
        self.count = 0
        
        self.get_logger().info('Fast DDS Publisher started!')
    
    def timer_callback(self):
        """Publish message every second"""
        msg = String()
        msg.data = f'Hello from Fast DDS! Message #{self.count}'
        
        self.publisher.publish(msg)
        self.get_logger().info(f'Published: "{msg.data}"')
        self.count += 1

def main(args=None):
    rclpy.init(args=args)
    publisher = FastDDSPublisher()
    
    try:
        rclpy.spin(publisher)
    except KeyboardInterrupt:
        pass
    finally:
        publisher.destroy_node()
        rclpy.shutdown()

if __name__ == '__main__':
    main()