#include "ros/ros.h"
#include "idmind_tabletop_msgs/MotorCommand.h"

int main(int argc, char **argv){

  ros::init(argc, argv, "eye_roll_test");

  ros::NodeHandle n;

  ros::Publisher test_pub = n.advertise<idmind_tabletop_msgs::MotorCommand>("/idmind_tabletop/cmd_eyes_roll_pos", 1000);


  float time, position;
  uint play_time;
  position = 0.5;
  play_time = 300;

  time =5 ; //delay for changing movement
  int count = 0; //A count of how many cycles we have complete

  ros::Rate loop_rate(1/time);
  while (ros::ok())
  {
    idmind_tabletop_msgs::MotorCommand roll_command; 
    roll_command.motor = 0;
    roll_command.position = position;
    roll_command.play_time = play_time;
    roll_command.relative = false;
    roll_command.disable_eyes_roll_sync = false;

    test_pub.publish(roll_command);

    position *=-1;

    ros::spinOnce();
    loop_rate.sleep();
    ++count;
  }


  return 0;
}