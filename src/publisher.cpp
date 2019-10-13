#include "ros/ros.h"
#include "std_msgs/String.h"

#include <sstream>
#include <chrono>
#include "performance_test/SuperAwesome.h"

int main(int argc, char **argv)
{

    ros::init(argc, argv, "talker");


    int rate;
    ros::NodeHandle n;
    n.param("rate",rate,5);

    ros::Publisher chatter_pub = n.advertise<performance_test::SuperAwesome>("chatter", 100);

    performance_test::SuperAwesome msg;


    ros::Rate loop_rate(rate);


    while (ros::ok())
    {

        std::stringstream ss;
        ss << "Publishing rate:" << rate;
        msg.message= ss.str() ;
        msg.time =ros::Time::now().toSec();


//        ROS_INFO("%s", msg.data.c_str(),ros::Time::now());
//        std::cout<<msg.message<<" "<<ros::Time::now().toSec()<<std::endl;

        chatter_pub.publish(msg);

        ros::spinOnce();

        loop_rate.sleep();

    }


    return 0;
}