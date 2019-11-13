#include "ros/ros.h"
#include "idmind_tabletop_msgs/EyesPose.h"

int main(int argc, char **argv){

  ros::init(argc, argv, "eye_movement_test");

  ros::NodeHandle n;

  ros::Publisher test_pub_right = n.advertise<idmind_tabletop_msgs::EyesPose>("/idmind_tabletop/cmd_eyes_pose", 1000);
  ros::Publisher test_pub_left = n.advertise<idmind_tabletop_msgs::EyesPose>("/idmind_tabletop/cmd_eyes_pose", 1000);


  float x_zero_pos, y_zero_pos, x_add_pos, y_add_pos, time, freq;
  x_zero_pos = 360;
  y_zero_pos = 360;
  x_add_pos = 360;
  y_add_pos = 360;
  time=2; //delay for changing movement
  int count = 0; //A count of how many cycles we have complete

  ros::Rate loop_rate(1/time);
  while (ros::ok())
  {
    idmind_tabletop_msgs::EyesPose right_eye; 
    right_eye.eye = 0;
    right_eye.pos_x = x_zero_pos + x_add_pos;
    right_eye.pos_y = y_zero_pos + y_add_pos;
    
    idmind_tabletop_msgs::EyesPose left_eye;
    left_eye.eye = 1;
    left_eye.pos_x = x_zero_pos + x_add_pos;
    left_eye.pos_y = y_zero_pos + y_add_pos;

    test_pub_right.publish(right_eye);
    test_pub_left.publish(left_eye);

    x_add_pos *=-1;
    y_add_pos *=-1;

    ros::spinOnce();
    loop_rate.sleep();
    ++count;
  }


  return 0;
}