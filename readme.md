# ros_practice
## ROS practice with C++ and Python3  
### 1. Day1: Create Catkin workspace, ROS Package and Nodes with C++ und Python3 
Enviroment: WSL, Unbuntu 20.04, ROS-Noetic, C++, Python3
This material is intended as a review of the ROS practice for my self.
#### 1.1 Catkin Workspace
* What is a catkin workspace?  
Catkin is the official bulit system for ROS  
* How to a create catkin workspace?
  ```console  
  $ mkdir catkin_ws
  $ cd catkin_ws
  $ mkdir src
  $ catkin_make
  $ source devel/setup.bash
  ```  
  Catkin_make is the command to build the ROS Workspace.
#### 1.2 ROS Package
* What is a ROS Package?  
ROS Package will allow us to separate our code into resusable block so the development and maintenance of the application will be easier
* How to create a ROS Package?
  ```console
  $ catkin_create_pkg {name of a package} {dependencies of the package}
  ```
  for example
  ```console
  $ catkin_create_pkg robot_package roscpp rospy std_msgs
  ```
  it mean we create a ROS Package with the dependencies roscppp(for c++), rospy(for Python) and std_msgs(the basic ROS package Standard Messages