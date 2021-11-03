#include "ros/ros.h"
#include "st9051/cmd_vel_tutorial.h"
#include "geometry_msgs/Twist.h"

void msgCallback(const geometry_msgs::Twist::ConstPtr& val) {
  ROS_INFO("receive msg = %f", val->linear.x);
  ROS_INFO("receive msg = %f", val->angular.z);
}

int main(int argc, char** argv) {
  ros::init(argc, argv, "cmd_vel_subscriber");
  ros::NodeHandle nh;

  ros::Subscriber sub = nh.subscribe("/cmd_vel", 1, msgCallback);

  ros::spin();
  return 0;
}