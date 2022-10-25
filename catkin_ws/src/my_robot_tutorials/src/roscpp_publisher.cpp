#include <ros/ros.h>
#include <std_msgs/String.h> // needed header file to use std_msgs::string

int main(int argc, char **argv){

    ros::init(argc, argv, "robot_news_radio_trainsmitter");
    ros::NodeHandle nh;


    //Declear ros Publisher
    //ros::publisher pub =nh.advertise<{!message type!}>("{!topic_name!}", {!queue size!})
    ros::Publisher pub = nh.advertise<std_msgs::String>("/robot_news_radio",10); // declear ros publisher 

    ros::Rate rate(3);

    while(ros::ok){
        
        std_msgs::String msg; //declear ros message 
        msg.data = "Hi, this is publisher test!"; //input in msg.date "hi......."
        pub.publish(msg); // "publish msg"
        rate.sleep();
    }
}