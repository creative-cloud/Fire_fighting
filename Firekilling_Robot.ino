#include<Servo.h>
#include<NewPing.h>
const int button=5;
const int TP =6;
const int EP =7;
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
int rno=0;
int fan=13;
int distance;  int distance1;
NewPing sonar(TP,EP,MD);
NewPing sonar1(TP1,EP1,MD1);
NewPing sonar2(TP2,EP2,MD2);
Servo left;
Servo right;
int count=0;


void setup() {
// put your setup code here, to run once:
Serial.begin(9600);
left.attach(9);
right.attach(10);
digitalWrite(13,LOW); 
}

void loop() 
{
// put your main code here, to run repeatedly:
  pd=distance;
  delay(100);
  distance = sonar.ping_cm();
  distance1 = sonar1.ping_cm();
  //Serial.println(c1);   //Printing Change in Distance
  left.write(180);      //go straight in the beginning
  right.write(0);
  c1=distance1-pd1;
  pd1=distance1;
  if(distance<0)
  {
    distance=sonar.ping_cm();
  }

 digitalWrite(13,LOW);
//  //Serial.println(distance);
//  //Serial.print("c: ");
//  //Serial.println(distance);

   
  if(analogRead(5)>500||analogRead(4)>500)
  {
    fire();
  }
   if(analogRead(0)>500||analogRead(1)>500)
  {
    fire();
  }
 
 Right();  //Turning right (around edge)
  Left();
 
 //Corrections.
  lcor();//correction to the left
 
 rcor();//correction to the right
 // fire();



 
}

void Right()
{
  //Turning right (around edge)
  if(c1>10 )              
  { delay(600);         //avoid the edge
    
    //Serial.println("RIGHT");
    right.write(180);           
    left.write(180);     //turn 90
    delay(1000);
    left.write(180);     //go straight 
    right.write(0);
    Right2();
    /*rno++;
    if(rno==2)
    {
      rno=0;
      delay(2200);
      right.write(180);           
      left.write(180);     //turn 90
      delay(1000);
      left.write(180);     //go straight 
      right.write(0);
    }*/
    delay(1500);          //chk if needed
  }
}

void Left()
{
  if( distance<10 && distance>0)
  {
    right.write(0);     //left
    left.write(0);
    delay(950);
    left.write(180);     //go straight 
    right.write(0);
    delay(500);
    //Serial.println("Left Turn");
    
  }
}
void lcor()
{
  //Corrections.
  if(c1==-1||c1==-2)   //correction to the left
  {  //Serial.println("turning left");
     left.write(99);       
     right.write(0);
     delay(500);
   }  
}
void rcor()
{
  
   if(c1>0&&c1<4)     //correction to the right
  {
   //Serial.println("turning right");
  left.write(180);
  right.write(80);
  delay(500);
  }
}
void Right2()
{ 
  int flag=0,temp=0,count=0;  
  for(int i=0;i<5;i++)
  {
    distance1 = sonar1.ping_cm();   //check distance from the wall
    //Serial.println(distance1);
    delay(75);
    if(distance1<8)         //make sure there is actually a wall
    {
      flag=1;
      temp=distance1;       //save that distance
      break;
    }
  }
  if(flag==0)           //if edge
  {
    for(int i=0;i<8;i++)
    { distance1 = sonar1.ping_cm();
      if(temp-distance1>-4&&temp-distance<4)      //check if the wall is still there
      {
        continue;
        count=0;
      }
      else                      //if no wall, then edge
      {
        count++;               
      }
      delay(75);
    }
    if(count>=2)               //make sure it's an edge
    {
      delay(1200);
      //Serial.println("Right 2");      
      right.write(180);           
      left.write(180);     //turn 90
      delay(950);
      left.write(180);     //go straight 
      right.write(0);
    }
  }   
}


void fire()
{
  /*
  if(count==2)
  {
    count=0;
    loop();
  }
  count++;
  //Serial.println();
  //Serial.print(digitalRead(2));                                                     
 */
  /*
  if(analogRead(2)>900 && analogRead(1)>800 && analogRead(4)>800)
  {
    
    digitalWrite(13,HIGH);
  }
   if((analogRead(5)>700||analogRead(4)>700)&&analogRead(0)<600)
  {
    left.write(150);
    right.write(150);         //right
    delay(350);
    left.write(180);
    right.write(0);
    delay(100);
  }
  
   if((analogRead(1)>700||analogRead(2)>700)&&analogRead(5)<600)
  {
    left.write(0);
    right.write(50);            //left
    delay(300);
    left.write(180);
    right.write(0);
    delay(100);
  }
  
fire();
  
  /*
  left.write(90);
  right.write(90);    //stop
  Serial.print("start");
  digitalWrite(13,HIGH);
  left.write(90);
  right.write(100);      //turn right w right
  Serial.print("1");
  delay(350);
  
  left.write(110);
  right.write(90);      //turn right w left
  Serial.print("2");
  delay(400);
  
   left.write(90);        //stop
  right.write(90);    
  Serial.print("break");
  delay(1500);
  
  left.write(60);
  right.write(90);      //turn left w left
  Serial.print("3");
  delay(500);
  
  left.write(90);
  right.write(25);      //turn left w right
  Serial.print("4");
  delay(400);
  Serial.print("done");
   left.write(90);    //stop
  right.write(90);    
  delay(1500);
  }
  */
   
//  if(analogRead(5)>700||analogRead(4)>700)
//  {
//    left.write(110);
//    right.write(100);
//    delay(350);
//    fire();
//  }
//
//if(analogRead(0)>700||analogRead(1)>700)
//  {
//    
//   left.write(60);
//    right.write(50);
//    delay(350);
//    fire();
//  }
  }  
  */

   if(analogRead(5)>700||analogRead(4)>700)
    {
      left.write(110);
      right.write(110);
      delay(100);
      left.write(180);
      right.write(0);
      delay(100);
      
    }
  if(analogRead(2)<900&&analogRead(2)>500)
  {
    while(analogRead(2)>=950)
    {
      left.write(180);
      right.write(0);
      delay(100);
    }
  }
  
    }
  }


  
  
  
                                                                                                                                    
