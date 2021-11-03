#include "ros/ros.h"
#include "st9051/cmd_vel_tutorial.h"
#include "st9051/running.h"
#include "geometry_msgs/Twist.h"


int main(int argc, char** argv) {
  ros::init(argc, argv, "cmd_vel_publisher");

  running motor_speed(1,3);
  
  // ros::Rate loop_rate(1);

  // while(ros::ok() && motor_speed.count < 10)
  // {
  //   motor_speed.runmotor();
  //   ros::spinOnce();
  //   loop_rate.sleep();
  // }
  return 0;
}