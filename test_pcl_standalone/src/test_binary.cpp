/**
 * @file
 * @brief 
 */
#ifndef _WRITE_OBJECT_PCD_CPP_
#define _WRITE_OBJECT_PCD_CPP_

/* _________________________________
   |                                 |
   |           INCLUDES              |
   |_________________________________| */

//ros includes
#include <ros/ros.h>
#include <ros/package.h>

//pstreams includes
#include <pstreams/pstream.h>

//pcl includes
#include <pcl/io/pcd_io.h>
#include <pcl/point_types.h>

//pcl_conversions
#include <pcl_conversions/pcl_conversions.h>

//test_library
#include <test_pcl_standalone/test_library.h>


/* _________________________________
   |                                 |
   |           Namespaces            |
   |_________________________________| */


//Global vars

int main (int argc, char** argv)
{
	ros::init(argc, argv, "write_object_pcd"); // Initialize ROS coms

	ros::NodeHandle* n = (ros::NodeHandle*) new ros::NodeHandle("~"); //The node handle

    //TEST1: use pcl_conversions
    sensor_msgs::PointCloud2 msg;
    pcl::PointCloud<pcl::PointXYZRGB> pc;
	pcl::fromROSMsg<pcl::PointXYZRGB>( msg, pc);

    //TEST2: use pcl io functions a (I think this one is only present in pcl1.7)
    pcl::io::savePCDFileASCII ("pcd_out.pcd", pc);

    //TEST3: instantiate the test library and call test function
    test_class tc;
    tc.test_function();
	return 1;
}

#endif
