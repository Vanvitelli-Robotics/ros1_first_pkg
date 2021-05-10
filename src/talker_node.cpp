#include "ros/ros.h"
#include "std_msgs/String.h"

int main(int argc, char *argv[])
{
    
    ros::init(argc, argv, "talker");

    ros::NodeHandle nh;
    
    ros::Publisher chatter_pub = nh.advertise<std_msgs::String>("chatter", 1000);

    ros::Rate loop_rate(10);

    int count = 0;
    while(ros::ok()) //keep spinning loop
    {
        std_msgs::String msg;
        msg.data = "hello world " + std::to_string(count);
        
        ROS_INFO_STREAM(msg.data);

        chatter_pub.publish(msg);

        ros::spinOnce(); // Allow ROS to process incoming messages
        loop_rate.sleep(); // Sleep for the rest of the cycle
        count++;
    }

    return 0;
}
