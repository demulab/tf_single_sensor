/**
 * @file   tf_hokuyo3d.cpp
 * @brief  transform broadcaster for hokuyo3d
 * @author Kosei Demura
 * @date   2016.6.16
 *
 * @par Update Information
 * - 2016.6.16
 *  # Initial Version
 *
 */

#include <ros/ros.h>
#include <tf/transform_broadcaster.h>

int main(int argc, char** argv){
  ros::init(argc, argv, "tf_hokuyo3d");
  ros::NodeHandle node;

  tf::TransformBroadcaster br;
  tf::Transform transform;

  ros::Rate rate(10.0);
  while (node.ok()){
    transform.setOrigin( tf::Vector3(0.0, 0.0, 0.0) );
    transform.setRotation( tf::Quaternion(0, 0, 0, 1) );
    br.sendTransform(tf::StampedTransform(transform, ros::Time::now(), "world", "hokuyo3d"));
    rate.sleep();
  }
  return 0;
};







