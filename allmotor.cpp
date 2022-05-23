#include <stdio.h>
#include "allmotor.h"
#include <ros/ros.h>
#include <std_msgs/Int16.h>

using namespace std;

class Allmotor{
private:
  ros::NodeHandle nh;
  //퍼블리셔
  ros::Publisher pub;
  //서브스크라이버
  ros::Subscriber sub;
  //변수
  std::string name;
  std_msgs::Int16 fin;

public:
  Allmotor(){
    pub = nh.advertise<std_msgs::Int16>("/motor_arrival", 1);
    sub = nh.subscribe("/motor", 1, &Allmotor::msgCallback,this);
  }

  void msgCallback(const std_msgs::Int16::ConstPtr& msg){
    switch(msg -> data){
      case 101:
        ROS_INFO("First floor is activating");
        forward1(10);
        break;

      case 102:
        ROS_INFO("Second floor is activating");
        forward2(48);
        break;

      case 103:
        ROS_INFO("Third floor is activating");
        forward3(48);
        break;
    }
    fin.data = 3;
    pub.publish(fin);
  }
};

int main(int argc, char **argv)
{
  ros::init(argc, argv, "allmotor");

  //Initiate ROS
  ros::NodeHandle nh;
  ROS_INFO("All MOTORS ON!");

  wiringPiSetupGpio();

  //Create an object of class allmotor
  Allmotor allmotor;

  ros::spin();

  return 0;
}
