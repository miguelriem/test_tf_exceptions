#ifndef _TEST_LIBRARY_H_
#define _TEST_LIBRARY_H_

/* _________________________________
   |                                 |
   |           INCLUDES              |
   |_________________________________| */

//boost includes
#include <boost/lexical_cast.hpp>

//ROS includes
#include <ros/ros.h>
#include <ros/package.h>

//PCL includes
#include <pcl/tracking/kld_adaptive_particle_filter_omp.h>
#include <pcl/tracking/distance_coherence.h>
#include <pcl/tracking/hsv_color_coherence.h>
#include <pcl/tracking/approx_nearest_pair_point_cloud_coherence.h>
#include <pcl/tracking/nearest_pair_point_cloud_coherence.h>
#include <pcl/point_cloud.h>
#include <pcl/point_types.h>
#include <pcl/common/centroid.h>
#include <pcl/common/pca.h>
#include <pcl/filters/passthrough.h>
#include <pcl/filters/project_inliers.h>
#include <pcl/filters/voxel_grid.h>
#include <pcl/common/transforms.h>
#include <pcl/filters/conditional_removal.h>
#include <pcl/io/pcd_io.h>
#include <pcl/common/transforms.h>

#include <pcl_conversions/pcl_conversions.h>
//race includes


/* _________________________________
  |                                 |
  |           Namespaces            |
  |_________________________________| */


	/* _________________________________
	   |                                 |
	   |        Class definition         |
	   |_________________________________| */

	class test_class
	{
        public:

        test_class(){};
        ~test_class(){};

        void test_function(void)
        {
            pcl::PointCloud<pcl::PointXYZRGB> pc;
        
        }

    };

#endif
