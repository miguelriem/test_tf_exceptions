#!/usr/bin/env python
import roslib
roslib.load_manifest('test_tf')
import rospy
import math
import tf

if __name__ == '__main__':
    rospy.init_node('tf_test_py')

    listener = tf.TransformListener()

    rate = rospy.Rate(10)
    while not rospy.is_shutdown():

        print "waiting"
        try:
            (trans,rot) = listener.lookupTransform('/world3', '/world2', rospy.Time(0))
        except (tf.LookupException, tf.ConnectivityException, tf.ExtrapolationException):
            print "exception "
            #continue
            "this is my comment"
        #print trans
        rate.sleep()
