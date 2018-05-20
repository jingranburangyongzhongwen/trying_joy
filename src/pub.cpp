#include <ros/ros.h>
#include <std_msgs/String.h>
#include <sensor_msgs/Joy.h>
#include <sstream>
#include <string>

class Pub
{
public:
  Pub();

private:
  void joyCallback(const sensor_msgs::Joy::ConstPtr& joy);

  ros::NodeHandle n;

  ros::Publisher my_pub;
  ros::Subscriber joy_sub;

};


Pub::Pub()
{
  my_pub = n.advertise<std_msgs::String>("joy_chatter", 1);


  joy_sub = n.subscribe<sensor_msgs::Joy>("joy", 10, &Pub::joyCallback, this);

}

void Pub::joyCallback(const sensor_msgs::Joy::ConstPtr& joy)
{
  std_msgs::String msg;

  /*
   * 查看手柄axes信息
   */
  std::stringstream ss;

  if(joy->axes[0]>0.3)
      ss<<"LS--left ";
  if(joy->axes[0]<-0.3)
      ss<<"LS--right ";
  if(joy->axes[1]>0.3)
      ss<<"LS--up ";
  if(joy->axes[1]<-0.3)
      ss<<"LS--down ";
  if(joy->axes[2]<0.7)
      ss<<"LT--down ";
  if(joy->axes[3]>0.3)
      ss<<"RS--left ";
  if(joy->axes[3]<-0.3)
      ss<<"RS--right ";
  if(joy->axes[4]>0.3)
      ss<<"RS--up ";
  if(joy->axes[4]<-0.3)
      ss<<"RS--down ";
  if(joy->axes[5]<0.7)
      ss<<"RT--down ";
  if(joy->axes[6]>0.3)
      ss<<"CK--left ";
  if(joy->axes[6]<-0.3)
      ss<<"CK--right ";
  if(joy->axes[7]>0.3)
      ss<<"CK--up ";
  if(joy->axes[7]<-0.3)
      ss<<"CK--down ";

  /*
   * 查看手柄buttons信息
   */
  std::string buttons[11]={"A","B","X","Y","LB","RB","LFK","RFK","Xbox","LSC","RSC"};
  for(int i=0;i<11;i++){
      if(joy->buttons[i]>0.3)
          ss<<buttons[i]<<" ";
  }

  /*
   * 发送消息
   */
  msg.data = ss.str();
  std::string s=msg.data.c_str();
  int len=s.length();
  for(int i=0;i<len;i++){
      if(isalpha(s[i]))
          my_pub.publish(msg);
  }

}


int main(int argc, char** argv)
{
  ros::init(argc, argv, "pub");
  Pub pub;

  ros::spin();
}
