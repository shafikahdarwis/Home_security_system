#include<ros.h>
#include<sensor_msgs/RegionOfInterest.h>

ros::NodeHandle nh;

int var;

void messageCb(const sensor_msgs::RegionOfInterest &roi)

{
  var=roi.x_offset;

  if (var<150)
  {
    digitalWrite(13,LOW);  //turn off LED
  }
  else
  {
    digitalWrite(13,HIGH);  //blink LED
  }
}

//ros::Subscriber<std.msgs::Int32>sub("/random_number",&messageCb);
ros::Subscriber<sensor_msgs::RegionOfInterest>sub("/roi", &messageCb);


void setup() 
{
  pinMode(13,OUTPUT);
  nh.initNode();
  nh.subscribe(sub);

}

void loop() 
{
  nh.spinOnce();
  delay(1);

}
