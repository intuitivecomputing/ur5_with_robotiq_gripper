cmake_minimum_required(VERSION 2.8.3)
project(icl_robotiq_2f_gripper_action_server)

find_package(catkin REQUIRED COMPONENTS
  actionlib
  actionlib_msgs
  message_generation
  robotiq_2f_gripper_control
  roscpp
  control_msgs
)

catkin_package(
  INCLUDE_DIRS include
  CATKIN_DEPENDS actionlib actionlib_msgs robotiq_2f_gripper_control roscpp
)

include_directories(include)
include_directories(
  ${catkin_INCLUDE_DIRS}
  ${icl_robotiq_2f_gripper_action_server_INCLUDE_DIRS}
)

# The action server
add_executable(icl_robotiq_2f_gripper_action_server_node
    src/robotiq_2f_gripper_action_server_node.cpp
    src/robotiq_2f_gripper_action_server.cpp
    include/icl_robotiq_2f_gripper_action_server/robotiq_2f_gripper_action_server.h)

add_dependencies(icl_robotiq_2f_gripper_action_server_node
  robotiq_2f_gripper_action_server_generate_messages_cpp
  ${icl_robotiq_2f_gripper_action_server_EXPORTED_TARGETS}
  ${icl_robotiq_2f_gripper_control_EXPORTED_TARGETS})

 target_link_libraries(icl_robotiq_2f_gripper_action_server_node
   ${catkin_LIBRARIES}
 )

install(TARGETS icl_robotiq_2f_gripper_action_server_node
  ARCHIVE DESTINATION ${CATKIN_PACKAGE_LIB_DESTINATION}
  LIBRARY DESTINATION ${CATKIN_PACKAGE_LIB_DESTINATION}
  RUNTIME DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION}
 )

install(DIRECTORY include/${PROJECT_NAME}/
   DESTINATION ${CATKIN_PACKAGE_INCLUDE_DESTINATION}
   FILES_MATCHING PATTERN "*.h"
 )
