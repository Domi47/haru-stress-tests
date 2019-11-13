#include "ros/ros.h"
#include "idmind_tabletop_msgs/MotorCommand.h"

int main(int argc, char **argv){

  ros::init(argc, argv, "neck_test");

  ros::NodeHandle n;

  ros::Publisher test_pub = n.advertise<idmind_tabletop_msgs::MotorCommand>("/idmind_tabletop/cmd_neck_pos", 1000);


  float time, position;
  uint play_time;
  position = 0.4;
  play_time = 150;

  time = 3 ; //delay for changing movement
  int count = 0; //A count of how many cycles we have complete

  ros::Rate loop_rate(1/time);
  while (ros::ok())
  {
    idmind_tabletop_msgs::MotorCommand neck_command; 
    neck_command.motor = 0;
    neck_command.position = position;
    neck_command.play_time = play_time;
    neck_command.relative = false;
    neck_command.disable_eyes_roll_sync = false;

    test_pub.publish(neck_command);

    position *=-1;

    ros::spinOnce();
    loop_rate.sleep();
    ++count;
  }


  return 0;
}