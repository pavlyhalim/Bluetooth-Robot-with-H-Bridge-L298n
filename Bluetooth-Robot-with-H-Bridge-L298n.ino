#include <SoftwareSerial.h>


int pin1=2;
int pin2=3;
int pin3=4;
int pin4=5;
int en1=9;
int en2=10;
SoftwareSerial mSerail (1,0);
char r;

void setup() {
  pinMode(2,OUTPUT);
  pinMode(3,OUTPUT);
  pinMode(4,OUTPUT);
  pinMode(5,OUTPUT);
  pinMode(9,OUTPUT);
  pinMode(10,OUTPUT);
  Serial.begin(9600);
  mSerail.begin(9600);
}

void moveBackward (){
  analogWrite(en1,255);
  analogWrite(en2,255);
  digitalWrite(pin1,HIGH);
  digitalWrite(pin2,LOW);
  digitalWrite(pin3,LOW);
  digitalWrite(pin4,HIGH);
 }
 void moveForward(){
  analogWrite(en1,255);
  analogWrite(en2,255);
  digitalWrite(pin1,LOW);
  digitalWrite(pin2,HIGH);
  digitalWrite(pin3,HIGH);
  digitalWrite(pin4,LOW);
 }
 
 void turnRight(){
  analogWrite(en1,255);
  analogWrite(en2,255);
  digitalWrite(pin1,HIGH);
  digitalWrite(pin2,LOW);
  digitalWrite(pin3,HIGH);
  digitalWrite(pin4,LOW);
 }
 void turnLeft(){
  analogWrite(en1,255);
  analogWrite(en2,255);
  digitalWrite(pin1,LOW);
  digitalWrite(pin2,HIGH);
  digitalWrite(pin3,LOW);
  digitalWrite(pin4,HIGH);
 }
  
 void forwardRight(){
  analogWrite(en1,100);
  analogWrite(en2,255);
  digitalWrite(pin1,LOW);
  digitalWrite(pin2,HIGH);
  digitalWrite(pin3,HIGH);
  digitalWrite(pin4,LOW);  
  }

  void forwardLeft(){
    analogWrite(en1,255);
    analogWrite(en2,100);
    digitalWrite(pin1,LOW);
  digitalWrite(pin2,HIGH);
  digitalWrite(pin3,HIGH);
  digitalWrite(pin4,LOW);
    }
  
 void stopNow(){
  digitalWrite(pin1, LOW);
  digitalWrite(pin2, LOW);
  digitalWrite(pin3, LOW);
  digitalWrite(pin4, LOW);
 }


void loop(){
    
  if(Serial.available()>0) {
    r=(Serial.read());
    
      if(r == 'F') {
        moveForward();
      } else if(r == 'B') {
        moveBackward();
      } else if(r == 'L') {
        turnLeft();
      } else if(r == 'R') {
        turnRight();
      } else if(r == 'S') {
        stopNow();
      }else if(r== 'I'){
        forwardRight();
      }else if(r=='G'){
        forwardLeft();
        }
  }
}





  
