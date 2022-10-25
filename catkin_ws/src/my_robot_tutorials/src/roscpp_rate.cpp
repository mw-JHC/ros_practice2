#include <ros/ros.h>

int main(int argc, char **argv){

    ros::init(argc, argv, "my_first_cpp_node"); // initialize a ros node name: "my_first_cpp_node"
    ros::NodeHandle nh; // for ros cpp ! we need always Nodehandle!

    ROS_INFO("Node has been started"); // like cout<<

    ros::Rate rate(10); // 10hz!
    
    while(ros::ok){ // if ros node is not shut downed, it work
        ROS_INFO("Hello");
        rate.sleep();
    }
} 