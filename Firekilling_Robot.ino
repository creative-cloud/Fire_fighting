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
int pd1=30,pd2=0; 
int c,c1,c2;
int rno=0;
int fan=13;
int distance;  int distance1;
NewPing sonar(TP,EP,MD);
NewPing sonar1(TP1,EP1,MD1);
NewPing sonar2(TP2,EP2,MD2);
Servo left;
Servo right;
int i=1;
int flagg=0;

void setup() {
// put your setup code here, to run once:
Serial.begin(9600);
left.attach(9);
right.attach(10);
digitalWrite(13,LOW); 
left.write(180);
right.write(120);         //rcorr
delay(200);
 
   
left.write(90);
right.write(90);
delay(50);

    //right.write(180);           
    //left.write(180);     //turn 90 right
    //delay(1000);
    //left.write(180);      //go straight in the beginning
    //right.write(0);
    //delay(500);
    //right.write(0);     //left
    //left.write(0);
    //delay(950);
    

}

void loop() 
{
// put your main code here, to run repeatedly:
  pd=distance;
  delay(100);
  distance = sonar.ping_cm();
  distance1 = sonar1.ping_cm();
  if(flagg==1)
  {
    fire();
  }
  //Serial.println(c1);   //Printing Change in Distance
  left.write(180);      //go straight in the beginning
  right.write(0);
  c1=distance1-pd1;
  pd1=distance1;
  if(distance<0)
  {
    distance=sonar.ping_cm();
  } 
 //Serial.println(distance);
 //Serial.print("c: ");
 //Serial.println(distance);
 Left(); 
 Right();  //Turning right (around edge)
 //  //Corrections.
 lcor();//correction to the left
 rcor();//correction to the right
 fire();
 //left.write(90);
 //right.write(90);  
 //  Serial.println(analogRead(1));
 //  Serial.println(analogRead(2));
 //  Serial.println(analogRead(3));
}

void Right()
{ Serial.print("right");
  
  //Turning right (around edge)
  if(c1>10 )              
  { delay(700);         //avoid the edge
    
    //Serial.println("RIGHT");
    right.write(180);           
    left.write(180);     //turn 90 1
    delay(950);
    left.write(180);        //st
    right.write(0);
    delay(2300);
    //second
     right.write(180);           
    left.write(180);     //turn 90
    delay(950);
    distance = sonar.ping_cm();
  if(distance<7)
  {
    Left();
  }
    left.write(180);        //st
    right.write(0);
    delay(500);
    distance = sonar.ping_cm();
  if(distance<7)
  {
    Left();
  }
    
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
    //delay(1500);          //chk if needed
  }
}

void Left()
{
  if( distance<13 && distance>0)
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

/*
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
*/

void fire()
{
    flagg=1;
  //Serial.println();
  //Serial.print(digitalRead(2));
  
  
  if(analogRead(2)>950&&analogRead(1)>950&&analogRead(4)>950)
  {
    left.write(89);
    right.write(91);      //stop
    digitalWrite(13,HIGH);
    delay(2000);
    
  }
  
  
  if(analogRead(2)>970)
  {
    

   
      left.write(180);     //front
    right.write(0);
    delay(250);
      left.write(90);     //stop
    right.write(90);
    delay(100);
      digitalWrite(13,HIGH);              //FAN ON
      delay(2500);
    digitalWrite(13,LOW);
   
    fire();
  }
  if(analogRead(5)>700||analogRead(4)>700)
  {
    if(analogRead(2)>960)

   {
    digitalWrite(13,HIGH);              //FAN ON
      delay(2500);
    digitalWrite(13,LOW); 
   }
   else
   {
  left.write(180);            //stright
  right.write(0);
  delay(300);
  left.write(0);
  right.write(0);     //right
  delay(300);
  left.write(90);     //stop
    right.write(90);
    delay(100);
   }
    fire();
  
  }
  if(analogRead(0)>700||analogRead(1)>700)
  {

    if(analogRead(2)>960)

   {
    digitalWrite(13,HIGH);              //FAN ON
      delay(2500);
    digitalWrite(13,LOW); 
   }
   else
   {
    left.write(180);              //stright 
    right.write(0);
    delay(300);
    left.write(0);              //left
    right.write(0);
    delay(300);
    left.write(0);
    right.write(0);
    left.write(90);     //stop
    right.write(90);
    delay(100);
   }
    fire();
  }
  
  
}  
  


  
  
  
                                                                                                                                    

