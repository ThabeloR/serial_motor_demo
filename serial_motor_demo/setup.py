from setuptools import setup
from glob import glob

package_name = 'serial_motor_demo'

setup(
    name=package_name,
    version='0.0.0',
    packages=[package_name],
    data_files=[
        ('share/ament_index/resource_index/packages',
            ['resource/' + package_name]),
        ('share/' + package_name, ['package.xml']),
        ('share/' + package_name + '/config', glob('config/*.yaml')),
        ('share/' + package_name + '/launch', ['launch/rover_control.launch.py']),
        ('share/' + package_name + '/launch', ['launch/sonar_launch.py']),
    ],
    install_requires=['setuptools'],
    zip_safe=True,
    maintainer='newans',
    maintainer_email='josh.newans@gmail.com',
    description='TODO: Package description',
    license='TODO: License declaration',
    tests_require=['pytest'],
    entry_points={
        'console_scripts': [
            'gui = serial_motor_demo.gui:main',        # Start your GUI node
            'driver = serial_motor_demo.driver:main',  # Start your driver node
            'sonar = serial_motor_demo.sonar:main',
            'sonar_array = serial_motor_demo.sonar_array:main',  # Start Sonar Array Node
            'obstacle_avoid_sonar = serial_motor_demo.obstacle_avoid_sonar:main'   # Start Obstacle Avoidance Node
            
        ],
    },
    

)
