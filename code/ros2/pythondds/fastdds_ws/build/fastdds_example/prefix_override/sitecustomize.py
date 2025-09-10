import sys
if sys.prefix == '/usr':
    sys.real_prefix = sys.prefix
    sys.prefix = sys.exec_prefix = '/home/peiwu/work/pythonstudio/fastdds_ws/install/fastdds_example'
