#ifndef __running_h__
#define __running_h__
#include <ros/ros.h>
#include <geometry_msgs/Twist.h>

class running
{
  public:
  running(float val_x =0 , float val_z = 0);
  void runmotor();
  void set_val(float linear_vel_x, float angular_vel_z);
  int count;
  void task();

  private:
  ros::NodeHandle nh;
  ros::Publisher pub;
  geometry_msgs::Twist val;
  ros::Rate loop_rate;
  float val_x, val_z;

};

#endif