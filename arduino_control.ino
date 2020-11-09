
// Pin 13 is the indicator of running, as it is a LED on board.
int led = 13;


// Pin 12 controls motor and Pin 10 controls the switch on the head of sucker.
int switch_motor = 12;
int switch_reverse = 10;


void setup() {                
  pinMode(led, OUTPUT);     
  pinMode(switch_motor, OUTPUT);
  pinMode(switch_reverse, OUTPUT);
}



void loop() {
  // If get message from ROS
  // Then do something
  // Now independentent, halt for 1 second after switching
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
