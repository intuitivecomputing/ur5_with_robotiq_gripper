#include <moveit/planning_scene_interface/planning_scene_interface.h>
#include <moveit_msgs/CollisionObject.h>
#include <tf/transform_datatypes.h>


geometry_msgs::Pose tftoMsg(tf::Transform transform)
    {
        geometry_msgs::Pose pose;
        pose.position.x = transform.getOrigin().getX();
        pose.position.y = transform.getOrigin().getY();
        pose.position.z = transform.getOrigin().getZ();
        pose.orientation.x = transform.getRotation().getX();
        pose.orientation.y = transform.getRotation().getY();
        pose.orientation.z = transform.getRotation().getZ();
        pose.orientation.w = transform.getRotation().getW();
        return pose;
    }

geometry_msgs::Pose addPose(double x, double y, double z, double roll , double pitch , double yaw ) {
    tf2::Quaternion q;
    q.setRPY(roll,pitch, yaw);
    tf2::Transform transform(  q, tf2::Vector3(x,y,z));
    return tftoMsg(transform);
}

void addCollisionObjects()
  {
   	moveit::planning_interface::PlanningSceneInterface planning_scene_interface;
    std::vector<moveit_msgs::CollisionObject> collision_objects;
    int num_env_collision = 5;
    collision_objects.resize( num_env_collision );

    collision_objects[0].id = "table1";
    collision_objects[0].header.frame_id = "world";
    collision_objects[0].primitives.resize(1);
    collision_objects[0].primitives[0].type = collision_objects[0].primitives[0].BOX;
    collision_objects[0].primitives[0].dimensions.resize(3);
    collision_objects[0].primitives[0].dimensions[0] = 1.52;
    collision_objects[0].primitives[0].dimensions[1] = 0.6;
    collision_objects[0].primitives[0].dimensions[2] = 0.74;
    collision_objects[0].primitive_poses.resize(1);
    collision_objects[0].primitive_poses[0] = addPose(0.2, -0.5, -0.47, 0.0, 0.0, 0.0);
    collision_objects[0].operation = collision_objects[0].ADD;
    //******************
    collision_objects[1].id = "table2";
    collision_objects[1].header.frame_id = "table1";
    collision_objects[1].primitives.resize(1);
    collision_objects[1].primitives[0].type = collision_objects[1].primitives[0].BOX;
    collision_objects[1].primitives[0].dimensions.resize(3);
    collision_objects[1].primitives[0].dimensions[0] = 1.52;
    collision_objects[1].primitives[0].dimensions[1] = 0.6;
    collision_objects[1].primitives[0].dimensions[2] = 0.74;
    collision_objects[1].primitive_poses.resize(1);
    collision_objects[1].primitive_poses[0] = addPose(0.46, 1.1, 0.0, 0.0, 0.0, M_PI / 2);
    collision_objects[1].operation = collision_objects[1].ADD;
    //******************
    collision_objects[2].id = "base";
    collision_objects[2].header.frame_id = "world";
    collision_objects[2].primitives.resize(1);
    collision_objects[2].primitives[0].type = collision_objects[1].primitives[0].BOX;
    collision_objects[2].primitives[0].dimensions.resize(3);
    collision_objects[2].primitives[0].dimensions[0] = 0.61;
    collision_objects[2].primitives[0].dimensions[1] = 0.7;
    collision_objects[2].primitives[0].dimensions[2] = 0.85;
    collision_objects[2].primitive_poses.resize(1);
    collision_objects[2].primitive_poses[0] = addPose(0.0, 0.255, -0.45, 0.0, 0.0, 0.0);
    collision_objects[2].operation = collision_objects[2].ADD;
    //******************
    collision_objects[3].id = "wall1";
    collision_objects[3].header.frame_id = "world";
    collision_objects[3].primitives.resize(1);
    collision_objects[3].primitives[0].type = collision_objects[1].primitives[0].BOX;
    collision_objects[3].primitives[0].dimensions.resize(3);
    collision_objects[3].primitives[0].dimensions[0] = 0.1;
    collision_objects[3].primitives[0].dimensions[1] = 0.8;
    collision_objects[3].primitives[0].dimensions[2] = 3.0;
    collision_objects[3].primitive_poses.resize(1);
    collision_objects[3].primitive_poses[0] = addPose(-0.4, 0.23, 0, 0.0, 0.0, 0.0);
    collision_objects[3].operation = collision_objects[2].ADD;
    //******************
    collision_objects[4].id = "wall2";
    collision_objects[4].header.frame_id = "world";
    collision_objects[4].primitives.resize(1);
    collision_objects[4].primitives[0].type = collision_objects[1].primitives[0].BOX;
    collision_objects[4].primitives[0].dimensions.resize(3);
    collision_objects[4].primitives[0].dimensions[0] = 0.8;
    collision_objects[4].primitives[0].dimensions[1] = 0.1;
    collision_objects[4].primitives[0].dimensions[2] = 3.0;
    collision_objects[4].primitive_poses.resize(1);
    collision_objects[4].primitive_poses[0] = addPose(-0.05, 0.7, 0, 0.0, 0.0, 0.0);
    collision_objects[4].operation = collision_objects[2].ADD;
  
    planning_scene_interface.applyCollisionObjects(collision_objects);
}


int main(int argc, char** argv){
  	addCollisionObjects();
	return 0;
}

