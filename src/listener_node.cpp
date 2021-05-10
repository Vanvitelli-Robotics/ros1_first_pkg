#include "ros/ros.h"
#include "std_msgs/String.h"

void chatterCallback(const std_msgs::String::ConstPtr &msg)
{
  ROS_INFO_STREAM("I heard: [" << msg->data << "]");
}

int main(int argc, char *argv[])
{
  ros::init(argc, argv, "listener");

  ros::NodeHandle nh;

  ros::Subscriber chatter_sub = nh.subscribe("chatter", 1000, chatterCallback);

  ros::spin();

  return 0;
}
