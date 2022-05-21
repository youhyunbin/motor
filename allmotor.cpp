#include <stdio.h>
#include "allmotor.h"
#include <ros/ros.h>
#include <std_msgs/Int16.h>

using namespace std;

class ALLMOTOR{
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
  ALLMOTOR(){
    pub = nh.advertise<std_msgs::Int16>("/fin2", 1);
    sub = nh.subscribe("/motor", 5, &ALLMOTOR::msgCallback,this);
  }

  void msgCallback(const std_msgs::Int16::ConstPtr& msg){
    switch(msg -> data){
      case 101:
        ROS_INFO("First floor is activating");
        forward1(10);
        fin.data = 3;
        pub.publish(fin);
        break;

      case 102:
        ROS_INFO("Second floor is activating");
        forward2(48);
        fin.data = 3;
        pub.publish(fin);
        break;

      case 103:
        ROS_INFO("Third floor is activating");
        forward3(48);
        fin.data = 3;
        pub.publish(fin);
        break;
    }
  }
};

int main(int argc, char **argv){
  ros::init(argc, argv, "allmotor"); // node name
  ros::NodeHandle nh; // NodeHandle reset
  ROS_INFO("All MOTORS ON!");
  wiringPiSetupGpio();
  ALLMOTOR allmotor;
  ros::spin();
  return 0;
}
