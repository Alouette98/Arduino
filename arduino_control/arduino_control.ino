#include <ArduinoHardware.h>
#include <ros.h>
#include <std_msgs/String.h>
#include <std_msgs/Bool.h>

ros::NodeHandle nh;
std_msgs::String status_msg;
ros::Publisher status_publisher("suction_status", &status_msg);
void suction_action(const std_msgs::Bool& cmd);
ros::Subscriber<std_msgs::Bool> cmd_subscriber("suction_cmd", &suction_action);
// Global boolean variable
bool controller = false;


// Pin 13 is the indicator of running, as it is a LED on board.
int led = 13;


// Pin 12 controls motor and Pin 10 controls the switch on the head of sucker.
int switch_motor = 12;
int switch_reverse = 10;


void setup() {                
  pinMode(led, OUTPUT);     
  pinMode(switch_motor, OUTPUT);
  pinMode(switch_reverse, OUTPUT);

  // initialize ros
  nh.initNode();
  nh.subscribe(cmd_subscriber);
}



void loop() {
  // If get message from ROS
  // Then do something
  // Now independentent, halt for 1 second after switching
  if (controller){
  digitalWrite(led, HIGH);  
  motor_on();
  delay(1000);
  reverse_on();
  delay(1000);
  reverse_off();
  delay(1000);
  motor_off();
  digitalWrite(led, LOW);
  delay(1000);
  }else{
    
  }
  nh.spinOnce();
}


// Turn on the motor.
void motor_on(){
  digitalWrite(switch_motor,HIGH);
}


// Turn off the motor.
void motor_off(){
  digitalWrite(switch_motor,LOW);
}

// Rotate reversely.
void reverse_on(){
  digitalWrite(switch_reverse,HIGH);
}

// Rotate normally.
void reverse_off(){
  digitalWrite(switch_reverse,LOW);
}

// main entrance recieving ROS topic
void suction_action(const std_msgs::Bool& cmd) {
  if (cmd.data){
    controller = true;
  } else{
    controller = false;
    }
}
