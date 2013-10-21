
#include <ros/ros.h>
#include <tf/transform_listener.h>

using namespace std;
boost::shared_ptr<tf::TransformListener> p_tf_listener;

int main(int argc, char *argv[])
{
	ros::init(argc, argv, "test_print"); // Initialize ROS coms
	ros::NodeHandle* n = (ros::NodeHandle*) new ros::NodeHandle("~"); //The node handle

	//init tf listener
	p_tf_listener = (boost::shared_ptr<tf::TransformListener>) new tf::TransformListener;

	//the transformation to be queried


	//Query time (using ros::time::now() and wait until time is different from
	//zero, since this is what causes the problem
	ros::Rate loop_rate(20);
	bool flag=true;
	while (flag)
	{
		ros::Time now = ros::Time::now();
		if (now.toSec()!=0)
		{
			flag=false;
		}
		else
		{
			loop_rate.sleep(); //sleep
			ROS_INFO("Waiting for propper ros::Time:::now() call");
		}
	}

	//now wait for first transform, weird that first call never works, I guess
	//some old fashion sleep is needed, probably because the first
	//ros::Time::now() (although not zero) is still very early and the publisher
	//had not started yet
	bool got_transform=false;
	ros::Time t = ros::Time::now();
	while (ros::ok() && !got_transform)
	{
		try
		{
			ros::Time now = ros::Time::now();
			tf::StampedTransform transf;
			ROS_INFO_STREAM("Waiting for transform at time " << now);
			got_transform = p_tf_listener->waitForTransform("/world1" , "/world2", now, ros::Duration(0.5), ros::Duration(0.1));
		}
		catch (tf::TransformException ex)
		{
			ROS_ERROR("%s", ex.what());
		}

		loop_rate.sleep(); //sleep
		ros::spinOnce(); // Handle ROS events
	}
	ROS_INFO("Got transform after waiting %f secs", (ros::Time::now() - t).toSec());

	//Finally now we can lookup transforms without fearing exceptions
	//To test for expections you can comment any of the two cycles above and you
	//should start to see some of the exceptions
	while (ros::ok())
	{
		try
		{
			ros::Time now = ros::Time::now();
			tf::StampedTransform transf;
			ROS_INFO_STREAM("Looking up transform at time " << now);
			p_tf_listener->lookupTransform("/world1" , "/world2", now, transf);
		}
		catch (tf::TransformException ex)
		{
			ROS_ERROR("%s", ex.what());
		}

		loop_rate.sleep(); //sleep
		ros::spinOnce(); // Handle ROS events
	}


}
