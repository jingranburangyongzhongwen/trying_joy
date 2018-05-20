#include <ros/ros.h>
#include <std_msgs/String.h>
#include <sensor_msgs/Joy.h>

void chatterCallback(const std_msgs::String::ConstPtr& msg)
{
    ROS_INFO("I heard: [%s]", msg->data.c_str());
}

int main(int argc, char **argv)
{
  
  ros::init(argc, argv, "sub");

  ros::NodeHandle n;

  ros::Subscriber sub = n.subscribe("joy_chatter", 1000, chatterCallback);

  ros::spin();

  return 0;
}
