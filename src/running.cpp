#include "st9051/running.h"


running::running(float val_x, float val_z) : loop_rate(1)
{
    nh = ros::NodeHandle();
    pub = nh.advertise<geometry_msgs::Twist>("/cmd_vel", 1);
    
    count = 0;
    set_val(val_x, val_z);
    task();
}

void running::task()
{
  while(ros::ok() && count<10)
  {
    runmotor();
    ros::spinOnce();
    loop_rate.sleep();
  }
}


void running::runmotor()
{
    ROS_INFO("send msg linear velocity = %f", val.linear.x);
    ROS_INFO("send msg angular velocity = %f", val.angular.z);
    ROS_INFO("count = %d", count++);
    pub.publish(val);
}

void running::set_val(float linear_vel_x, float angular_vel_z)
{

  val.linear.x = linear_vel_x;
  val.angular.z = angular_vel_z;
}