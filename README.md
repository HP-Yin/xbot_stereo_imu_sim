# xbot_stereo_imu_sim 
Gazebo simulation for mobile robot with stereo camera and IMU  
Reference: https://github.com/DroidAITech/ROS-Academy-for-Beginners 
## Usage
```sh
$ mkdir catkin_sim  
$ cd catkin_sim  
$ mkdir src  
$ catkin_make  
$ cd src  
$ git clone https://github.com/HP-Yin/xbot_stereo_imu_sim.git  
$ cd ..  
$ source devel/setup.bash  
```
A museum environment:  
```sh
$ roslaunch xbot_stereo_imu_sim xbot_museum.launch  
```
An empty environment:  
```sh
$ roslaunch xbot_stereo_imu_sim xbot_empty.launch  
```
new terminal  
```sh
$ source devel/setup.bash  
$ roslaunch xbot_stereo_imu_sim stereo_imu_node.launch  
```
If you want to control the robot by keyboard:  
new terminal  
```sh
$ source devel/setup.bash  
$ roslaunch xbot_stereo_imu_sim keyboard_teleop.launch 
```
