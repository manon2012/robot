from setuptools import setup
import os
from glob import glob

package_name = 'my_ros2_package'

setup(
    name=package_name,
    version='0.0.0',
    packages=[package_name],
    data_files=[
        ('share/ament_index/resource_index/packages',
            ['resource/' + package_name]),
        ('share/' + package_name, ['package.xml']),
        (os.path.join('share', package_name, 'launch'), glob('launch/*.py')),
        (os.path.join('share', package_name, 'launch'), glob(os.path.join('launch', '*.py'))),
    ],
    install_requires=['setuptools'],
    zip_safe=True,
    maintainer='wp',
    maintainer_email='your.email@example.com',
    description='A simple ROS2 Python example package',
    license='Apache License 2.0',
    tests_require=['pytest'],
    entry_points={
        'console_scripts': [
            'publisher_node = my_ros2_package.publisher_node:main',
            'subscriber_node = my_ros2_package.subscriber_node:main',
        ],
    },
)