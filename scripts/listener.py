#!/usr/bin/env python
import rospy
from performance_test.msg import SuperAwesome

messageCount=0
measuredLoopRate=0
epochInterval=1
latency=0


def callback(data):

    global messageCount
    latency=abs(rospy.get_time()-data.time)
    # rospy.loginfo(' Received %s  PublishingTime %d Latency %d',data.message,data.time,latency)
    messageCount+=1



def epochCallback(event):
    global messageCount, measuredLoopRate,epochInterval
    measuredLoopRate  = messageCount/epochInterval
    rospy.loginfo("Measured Loop Rate:  %d",measuredLoopRate)
    messageCount = 0


def listener():

    global epochInterval
    rospy.init_node('pysub', anonymous=True)

    epochInterval = rospy.get_param('interval')
    rospy.Timer(rospy.Duration(epochInterval), epochCallback)

    rospy.Subscriber('chatter', SuperAwesome, callback)

    rospy.spin()

if __name__ == '__main__':
    listener()


