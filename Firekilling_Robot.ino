#include<Servo.h>
#include<NewPing.h>
const int button=5;
const int TP =12;
const int EP =13;
const int MD=200;
const int TP1=3;
const int EP1=2;
const int MD1=200;
const int TP2=8;
const int EP2=4;
const int MD2=200;
int pd=0; 
int pd1=0,pd2=0; 
int c,c1,c2;
NewPing sonar(TP,EP,MD);
NewPing sonar1(TP1,EP1,MD1);
NewPing sonar2(TP2,EP2,MD2);
Servo left;
Servo right;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  left.attach(9);
  right.attach(10);
}

void loop() {
  // put your main code here, to run repeatedly:
  int distance; pd=distance; int distance1; 
  delay(100);
  distance = sonar.ping_cm();
  distance1 = sonar1.ping_cm();
  //Serial.println(c1);   //Printing Change in Distance
  left.write(180);      //go straight in the beginning
  right.write(0);
  c1=distance1-pd1;
  pd1=distance1;
  //Turning right (around edge)
  if(c1>10 )              
  { delay(700);         //avoid the edge
    right.write(180);           
    left.write(180);     //turn 90
    delay(1000);
    left.write(180);     //go straight 
    right.write(0);
    delay(1500);
  }
  //Corrections.
  if(c1==-1||c1==-2)   //correction to the left
  {  Serial.println("turning left");
     left.write(100);       
     right.write(0);
     delay(500);}
  if(c1>0&&c1<4)     //correction to the right
  {
   Serial.println("turning right");
  left.write(180);
  right.write(82);
  delay(500);
  }  

  /*Serial.println(digitalRead(button));
  if(digitalRead(button)==HIGH)
  {
    left.write(100);       
     right.write(0);
     delay(500);
  }
  */
  if(distance1<2)
  {
    left.write(110);       
     right.write(0);
     delay(200);
  }
  
}
