#include <ros/ros.h>

int main(int argc, char **argv){

    ros::init(argc, argv, "my_first_cpp_node"); // initialize a ros node name: "my_first_cpp_node"
    ros::NodeHandle nh; // for ros cpp ! we need always Nodehandle!

    ROS_INFO("Node has been started"); // like cout<<

    ros::Duration(1.0).sleep(); // Duration time 1s sleep methode for 1 sec

    ROS_INFO("Exit");
} 