#include "ros/ros.h"
#include "std_msgs/String.h"
#include "performance_test/SuperAwesome.h"


ros::Subscriber sub;
int messageCount=0,measuredLoopRate=0,epochInterval=5,latency=0;


void chatterCallback(const performance_test::SuperAwesomeConstPtr &msg) {

    latency = abs(ros::Time::now().toSec() - msg->time);
    //ROS_INFO("Received: [%s] PublishingTime [%f] Latency %d", msg->message.c_str(), msg->time,latency);
    messageCount++;


}


void epochCallback(const ros::TimerEvent &event)
{
        measuredLoopRate  = messageCount/epochInterval;
        ROS_INFO("Measured Loop rate = %d", measuredLoopRate);
        messageCount = 0;
}

int main(int argc, char **argv)
{

    ros::init(argc, argv, "listener");

    ros::NodeHandle n;
    n.param("interval",epochInterval,1);

    sub = n.subscribe("chatter", 1000, chatterCallback);
    ros::Timer epoch = n.createTimer(ros::Duration(epochInterval), epochCallback);
    ros::spin();

    return 0;
}