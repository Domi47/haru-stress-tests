#include "ros/ros.h"
#include "idmind_tabletop_msgs/MotorCommand.h"

int main(int argc, char **argv){

  ros::init(argc, argv, "eye_stroke_test");

  ros::NodeHandle n;

  ros::Publisher test_pub = n.advertise<idmind_tabletop_msgs::MotorCommand>("/idmind_tabletop/cmd_eyes_stroke_pos", 1000);


  float time, position;
  uint play_time;
  position = 0.015;
  play_time = 150;

  time = 3 ; //delay for changing movement
  int count = 0; //A count of how many cycles we have complete

  ros::Rate loop_rate(1/time);
  while (ros::ok())
  {
    idmind_tabletop_msgs::MotorCommand stroke_command; 
    stroke_command.motor = 0;
    stroke_command.position = position;
    stroke_command.play_time = play_time;
    stroke_command.relative = false;
    stroke_command.disable_eyes_roll_sync = false;

    test_pub.publish(stroke_command);

    position *=-1;

    ros::spinOnce();
    loop_rate.sleep();
    ++count;
  }


  return 0;
}