#include<Servo.h>

Servo myservo;
int flame_in = 4;
int curr_state = 0;
int prev_state = 0;

void setup(){
  
  myservo.attach(5);
  pinMode(flame_in,INPUT);
  Serial.begin(9600);
  myservo.write(0);
  pinMode(13,OUTPUT);
}

void loop(){
  Serial.println("servo");
  if(digitalRead(flame_in)){
    curr_state = 1;
  }else{
    curr_state = 0;
  }

  if(prev_state != curr_state){
    prev_state = curr_state;
    if(prev_state == 0){
      myservo.write(0);
      digitalWrite(13,HIGH);
    }else {
      myservo.write(150);
      digitalWrite(13,LOW);
    }
  }
}