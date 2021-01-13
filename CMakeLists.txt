cmake_minimum_required(VERSION 2.8.3)
project(xbot_stereo_imu_sim)

set(CMAKE_BUILD_TYPE "Debug")
add_definitions("-DENABLE_SSE")
set(CMAKE_CXX_FLAGS "-std=c++11 ${SSE_FLAGS} -g -O3 -march=native")

find_package(OpenCV 3 REQUIRED)

find_package(catkin REQUIRED COMPONENTS
	roscpp
	rospy
	std_msgs
	message_generation
	controller_manager
	gazebo_ros
	cv_bridge
	image_transport
)

catkin_package(
   CATKIN_DEPENDS urdf xacro
)


include_directories(
  include ${catkin_INCLUDE_DIRS}
	${OpenCV_INCLUDE_DIRS}
)

add_executable(load_stereo_imu
  src/load_stereo_imu.cpp
)
add_dependencies(load_stereo_imu ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})
target_link_libraries(load_stereo_imu
  ${catkin_LIBRARIES} ${OpenCV_LIBS}
)