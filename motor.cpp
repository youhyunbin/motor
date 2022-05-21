#include <stdio.h>
#include "motor.h"
#include <ros/ros.h>
#include <std_msgs/Int16.h>

using namespace std;

class MOTOR1{
private:
  ros::NodeHandle nh;
  //퍼블리셔
  ros::Publisher pub;
  //서브스크라이버
  ros::Subscriber sub;
  //변수
  std::string name;
  std_msgs::Int16 fin2;

public:
  MOTOR1(const std::string &name_in = "motor1"): name(name_in){
    pub = nh.advertise<std_msgs::Int16>("/fin", 100);
    sub = nh.subscribe<std_msgs::Int16>("/motor1", 1000, boost::bind(&MOTOR1::msgCallback,this,_1));
  }

  void motor_forward(){
    forward3(48);
    fin2.data = 3;
    pub.publish(fin2);
    ros::spinOnce();
  }

  void msgCallback(const std_msgs::Int16::ConstPtr& msg){
    if(msg -> data == 102){
      ROS_INFO("Second floor is activating");
      this->motor_forward();
    }
  }
};

int main(int argc, char **argv){
  ros::init(argc, argv, "step2"); // node name
  ros::NodeHandle nh; // NodeHandle reset
  ROS_INFO("StepMotor2 ON!");
  wiringPiSetupGpio();
  MOTOR1 motor1;
  ros::spin();
  return 0;
}
