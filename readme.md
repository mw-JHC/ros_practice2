# ros_practice
## ROS practice with C++ and Python3  
### for VScode
ctrl + alt + p
change the c_cpp_progerties.json in .vscode folder like this
```json
{
  "configurations": [
    {
      "browse": {
        "databaseFilename": "${default}",
        "limitSymbolsToIncludedHeaders": false
      },
      "includePath": [
        "/opt/ros/noetic/include/**",
        "/usr/include/**",
        "~/catkin_ws/devel/include"
      ],
      "name": "ROS",
      "intelliSenseMode": "gcc-x64",
      "compilerPath": "/usr/bin/gcc",
      "cStandard": "gnu11",
      "cppStandard": "c++14"
    }
  ],
  "version": 4
}
```

### 1. Create Catkin workspace, ROS Package and Nodes with C++ und Python3 
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
  $ cd catkin_ws/src
  $ catkin_create_pkg {name of a package} {dependencies of the package}
  ```
  for example
  ```console
  $ catkin_create_pkg robot_package roscpp rospy std_msgs
  ```
  it mean we create a ROS Package with the dependencies roscppp(for c++), rospy(for Python) and std_msgs(the basic ROS package Standard Messages
#### 1.3 ROS Node
* What is a ROS Node?(according to ROS Wiki)
  > A ROS node is a process that performs computation. Nodes are combined together into a graph and communicate with one another using streaming topic, RPC services, and the Parameter Server. 

* How to create a ros Node with CPP
  ```c++
  #include <ros/ros.h>

  int main(int argc, char **argv){

    ros::init(argc, argv, "my_first_cpp_node"); // initialize a ros node name: "my_first_cpp_node"
    ros::NodeHandle nh; // for ros cpp ! we need always Nodehandle!

    ROS_INFO("Node has been started"); // like cout<<

    ros::Duration(1.0).sleep(); // Duration time 1s sleep methode for 1 sec

    ROS_INFO("Exit");
  }
  ```
but ros cpp have to be compiled. we can do that in CMakelist.txt in the Package, what we created.  
Open the CMakelist.txt and add the this comment.
```C
//add_executable(${PROJECT_NAME}_node src/my_robot_tutorials_node.cpp)
add_executable(node_cpp src/my_first_node.cpp)
//target_link_libraries(${PROJECT_NAME}_node ${catkin_LIBRARIES})
target_link_libraries(node_cpp ${catkin_LIBRARIES})
```
And in the catkin_ws folder
```console
$ catkin_make
$ source devel/setup.bash
```
if you want to test the node, whay you created.
```console
$ cd catkin_ws/devel/lib/my_robot_tutorials
$ ./node_cpp
```
### 2 Communicate with ROS Topics
#### 2.1 Topic
* What is a ROS topic?  
According to ROS wiki a topic is named bus over which nodes exchange messages. It is a unidirectional data stream between publisher and subscriber, then What is a publisher and subscriber? Every node can be a publisher and subscriber.
A publisher is a ROS node, what publish a topic. And a subscriber is a ROS node that subscribe a topic, what publisher publish. A node can be worked as a publisher and a subscriber at the same time. For example, like our smartphone. We can think  a smartphone as a node. If someone sends to our smartphone a text, our smartphone accept a text, and we can read it(Subscriber) also we can send a text to someone(publisher).   
The small difference between smartphone SMS function and ROS Node is that publisher don't know who is subscriber and subscriber don't know too who is publisher. They just send a topic and accept it.


