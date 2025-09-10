import sys
if sys.prefix == '/usr':
    sys.real_prefix = sys.prefix
    sys.prefix = sys.exec_prefix = '/home/peiwu/work/pythonros2/ros2_ws/install/my_ros2_package'
