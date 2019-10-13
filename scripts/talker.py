#!/usr/bin/env python
import rospy
from performance_test.msg import SuperAwesome

def talker():
    pub = rospy.Publisher('chatter', SuperAwesome, queue_size=10000)
    rospy.init_node('pypub', anonymous=True)

    rate=rospy.get_param("rate")
    looprate = rospy.Rate(rate) # 10hz

    msg=SuperAwesome()
    while not rospy.is_shutdown():
        msg.message="Publishing Rate %d" %rate
        msg.time=rospy.get_time()

        #hello_str = "Publishing Rate %d" %looprate
        rospy.loginfo("%s %s",msg.message,msg.time)
        pub.publish(msg)
        looprate.sleep()

if __name__ == '__main__':
    try:
        talker()
    except rospy.ROSInterruptException:
        pass
