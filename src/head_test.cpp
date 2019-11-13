#include "ros/ros.h"
#include "idmind_tabletop_msgs/MotorCommand.h"

int main(int argc, char **argv){

  ros::init(argc, argv, "head_test");

  ros::NodeHandle n;

  ros::Publisher test_pub = n.advertise<idmind_tabletop_msgs::MotorCommand>("/idmind_tabletop/cmd_head_pos", 1000);


  float time, position;
  uint play_time;
  position = 0.4;
  play_time = 200;

  time = 3 ; //delay for changing movement
  int count = 0; //A count of how many cycles we have complete

  ros::Rate loop_rate(1/time);
  while (ros::ok())
  {
    idmind_tabletop_msgs::MotorCommand head_command; 
    head_command.motor = 0;
    head_command.position = position;
    head_command.play_time = play_time;
    head_command.relative = false;
    head_command.disable_eyes_roll_sync = false;

    test_pub.publish(head_command);

    position *=-1;

    ros::spinOnce();
    loop_rate.sleep();
    ++count;
  }


  return 0;
}