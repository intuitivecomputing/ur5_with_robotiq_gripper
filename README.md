# ur5_with_robotiq_gripper

---
__Dependence__

[universal_robot](https://github.com/ros-industrial/universal_robot) : URDFs and Meshes for the UR5

[ur_modern_driver](https://github.com/ros-industrial/ur_modern_driver) : Drivers for the UR5.

[robotiq](https://github.com/ros-industrial/robotiq) : Drivers for the Robotiq gripper.

[ros_canopen](https://github.com/ros-industrial/ros_canopen)

[roboticsgroup_gazebo_plugins](https://github.com/roboticsgroup/roboticsgroup_gazebo_plugins) : For the gripper simulation in Gazebo


---

__Usage with moveit demo mode__

To start the setup without hardware, use the moveit demo mode:

```roslaunch tams_ur5_setup_moveit_config demo.launch```

This will bring up the same setup as tams_ur5_setup.launch and rviz but replaces the hardware drivers by moveits fake execution interfaces.

You can start this with a gui for the joint states of the ur5 and the gripper:

```roslaunch tams_ur5_setup_moveit_config demo.launch use_gui:=true```
__Usage with the hardware__

To bring up the whole arm configuration with all drivers, the corner urdf, moveit and the xtion camera
you can use the following command:

```roslaunch tams_ur5_setup_bringup tams_ur5_setup.launch```


To bring up just the xtion camera with the apriltags_ros node and the camera positioner, use the following launch file:

```roslaunch tams_ur5_setup_bringup camera.launch```

This launch file is included in the tams_ur5_setup.launch. You can use the use_kinect argument to bringup
the kinect drivers instead, in case the xtion is replaced by a kinect camera.

You can also use this launch file to directly bring up the setup with a kinect.

```roslaunch tams_ur5_setup_bringup tams_ur5_setup_floor_kinect.launch```

---
__Reference__

This repo learns a lot from [icl_phri_ur5](https://github.com/intuitivecomputing/icl_phri_ur5), [UR5-with-Robotiq-Gripper-and-Kinect](https://raw.githubusercontent.com/TAMS-Group/tams_ur5_setup/master/README.md) and [tams_ur5_setup](https://github.com/TAMS-Group/tams_ur5_setup)
