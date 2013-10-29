cmake_minimum_required(VERSION 2.4.6)
include($ENV{ROS_ROOT}/core/rosbuild/rosbuild.cmake)

# Set the build type.  Options are:
#  Coverage       : w/ debug symbols, w/o optimization, w/ code-coverage
#  Debug          : w/ debug symbols, w/o optimization
#  Release        : w/o debug symbols, w/ optimization
#  RelWithDebInfo : w/ debug symbols, w/ optimization
#  MinSizeRel     : w/o debug symbols, w/ optimization, stripped binaries
#set(ROS_BUILD_TYPE RelWithDebInfo)

rosbuild_init()

#set the default path for built executables to the "bin" directory
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)
#set the default path for built libraries to the "lib" directory
set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/lib)

#uncomment if you have defined messages
#rosbuild_genmsg()
#uncomment if you have defined services
#rosbuild_gensrv()

#common commands for building c++ executables and libraries
#rosbuild_add_library(${PROJECT_NAME} src/example.cpp)
#target_link_libraries(${PROJECT_NAME} another_library)
#rosbuild_add_boost_directories()
#rosbuild_link_boost(${PROJECT_NAME} thread)
#rosbuild_add_executable(example examples/example.cpp)
#target_link_libraries(example ${PROJECT_NAME})

#Find PCL 1.7
find_package(PCL 1.7 REQUIRED)
include_directories(BEFORE ${PCL_INCLUDE_DIRS})
link_directories(${PCL_LIBRARY_DIRS})
add_definitions(${PCL_DEFINITIONS})

#Just for debug
MESSAGE("PCL_INCLUDE_DIRS\n${PCL_INCLUDE_DIRS}\n")
MESSAGE("PCL_LIBRARY_DIRS\n${PCL_LIBRARY_DIRS}\n")
MESSAGE("PCL_DEFINITIONS\n${PCL_DEFINITIONS}\n")
MESSAGE("PCL_COMMON_LIBRARIES\n${PCL_COMMON_LIBRARIES}\n")

#use boost
rosbuild_add_boost_directories()

#Library
rosbuild_add_library(test_library src/test_library.cpp)

#Binary
rosbuild_add_executable(test_binary src/test_binary.cpp)
rosbuild_link_boost(test_binary system)
SET_TARGET_PROPERTIES(test_binary PROPERTIES LINK_FLAGS -L${PCL_LIBRARY_DIRS}) 
target_link_libraries(test_binary ${PCL_COMMON_LIBRARIES} ${PCL_IO_LIBRARIES})

