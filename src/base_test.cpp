#include "ros/ros.h"
#include "idmind_tabletop_msgs/MotorCommand.h"

int main(int argc, char **argv){

  ros::init(argc, argv, "base_test");

  ros::NodeHandle n;

  ros::Publisher test_pub = n.advertise<idmind_tabletop_msgs::MotorCommand>("/idmind_tabletop/cmd_base_pos", 1000);


  float time, position;
  uint play_time;
  position = 0.5;
  play_time = 300;

  time = 4 ; //delay for changing movement
  int count = 0; //A count of how many cycles we have complete

  ros::Rate loop_rate(1/time);
  while (ros::ok())
  {
    idmind_tabletop_msgs::MotorCommand base_command; 
    base_command.motor = 0;
    base_command.position = position;
    base_command.play_time = play_time;
    base_command.relative = false;
    base_command.disable_eyes_roll_sync = false;

    test_pub.publish(base_command);

    position *=-1;

    ros::spinOnce();
    loop_rate.sleep();
    ++count;
  }


  return 0;
}