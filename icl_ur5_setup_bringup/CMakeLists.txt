cmake_minimum_required(VERSION 2.8.3)
project(icl_ur5_setup_bringup)

## Compile as C++11, supported in ROS Kinetic and newer
# add_compile_options(-std=c++11)

## Find catkin macros and libraries
## if COMPONENTS list like find_package(catkin REQUIRED COMPONENTS xyz)
## is used, also find other catkin packages
find_package(catkin REQUIRED COMPONENTS
	moveit_core
    moveit_ros_planning
	moveit_ros_planning_interface
)


catkin_package(
	LIBRARIES
	INCLUDE_DIRS 
	CATKIN_DEPENDS 
	  moveit_core
      moveit_ros_planning_interface
)

# add_executable(add_collision_in_moveit src/add_collision_in_moveit.cpp)
# target_link_libraries(add_collision_in_moveit  ${catkin_LIBRARIES} )

