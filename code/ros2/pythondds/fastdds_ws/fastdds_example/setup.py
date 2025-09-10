from setuptools import find_packages, setup

package_name = 'fastdds_example'

setup(
    name=package_name,
    version='0.0.0',
    packages=find_packages(exclude=['test']),
    data_files=[
        ('share/ament_index/resource_index/packages',
            ['resource/' + package_name]),
        ('share/' + package_name, ['package.xml']),
    ],
    install_requires=['setuptools'],
    zip_safe=True,
    maintainer='peiwu',
    maintainer_email='manon2012@126.com',
    description='TODO: Package description',
    license='TODO: License declaration',
    tests_require=['pytest'],
    entry_points={
        'console_scripts': [
            'publisher = fastdds_example.publisher_node:main',
            'subscriber = fastdds_example.subscriber_node:main',
        ],
    },
)
