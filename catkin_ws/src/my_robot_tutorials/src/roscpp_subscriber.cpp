#include <ros/ros.h>
#include <std_msgs/String.h>

//void {!callback funtion name!}(cont messeage type& name)
void call_back_radio_data(const std_msgs::String& msg){
    ROS_INFO("Message received : %s", msg.data.c_str());
}

int main(int argc, char **argv){
    
    ros::init(argc, argv, "smartphone");
    ros::NodeHandle nh;

    //Declear ros Subscriber with name sub
    //ros::Subscriber sub = nh.subscribe({!"topic_name what we want to subscribe!}, {!buffer!}, {!callback function!})
    ros::Subscriber sub = nh.subscribe("/robot_news_radio", 1000, call_back_radio_data);

    ros::spin(); // ros spin will just keep the programm here, keep the not running untile we ask ti to shut down

}