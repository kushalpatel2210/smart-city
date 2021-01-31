#include "Arduino.h"
#include "Servo.h"
//#include <LiquidCrystal_I2C.h>
#include <Wire.h> 

//LiquidCrystal_I2C lcd(0x27, 16, 2);
#define SERVO9G_PIN_SIG  2

int flag2=0;
int flag1=1;
int flag3=1;
const int trigPin[] = {8,11};
const int echoPin[] = {9,12};
int parkStatus[5];
long int cm[2];// Global variables and defines
const int servo9gRestPosition   = 0;  //Starting position
const int servo9gTargetPosition = 120; //Position when event is detected
// object initialization
Servo servo9g;
void setup(){
  Serial.begin(9600);
  Wire.begin(7);
//  lcd.begin();
 // lcd.backlight();
   servo9g.attach(SERVO9G_PIN_SIG);
    servo9g.write(servo9gRestPosition);
    delay(100);
    servo9g.detach();
  pinMode(trigPin[0], OUTPUT);
  pinMode(echoPin[0], INPUT);
  pinMode(trigPin[1], OUTPUT);
  pinMode(echoPin[1], INPUT);
  Wire.onReceive(rec);
  
  Wire.onRequest(req);
  /*lcd.clear();
  lcd.setCursor(0,0);
 lcd.print("-----Welcome----");
  lcd.setCursor(0,1);
   lcd.print("Slots Available");*/
}
void loop()
{
int count=0;
  for(int i=0;i<2;i++)
  {
checkDistance(i);
}
for(int j=0;j<2;j++)
{
  //Serial.print(cm[j]);
  //Serial.print("             ");
  
}

Wire.requestFrom(9,6);
parkStatus[0]=Wire.read();
Wire.requestFrom(9,6);
parkStatus[1]=Wire.read();
Wire.requestFrom(9,6);
parkStatus[2]=Wire.read();
Wire.requestFrom(8,6);
parkStatus[3]=Wire.read();
Wire.requestFrom(8,6);
parkStatus[4]=Wire.read();
for(int j=0;j<5;j++)
{
  //Serial.print(parkStatus[j]);
  
}
//Serial.print("\n");
/*for(int k=0;k<5;k++)
    {
      if(parkStatus[k]==0)
      {
        count++;
     }
    }
    if(count==0)
    {*/

    
  
  
   /* else if(count==1)
    {
       lcd.clear();
  lcd.setCursor(0,0);
 lcd.print("-----Welcome----");
  lcd.setCursor(0,1);
   lcd.print("Avail. Slots: 1");
  
    }
      else if(count==2)
    {
       lcd.clear();
  lcd.setCursor(0,0);
 lcd.print("-----Welcome----");
  lcd.setCursor(0,1);
   lcd.print("Avail. Slots: 2");
  
    }
      else if(count==3)
    {
       lcd.clear();
  lcd.setCursor(0,0);
 lcd.print("-----Welcome----");
  lcd.setCursor(0,1);
   lcd.print("Avail. Slots: 3");
  
    }
      else if(count==4)
    {
       lcd.clear();
  lcd.setCursor(0,0);
 lcd.print("-----Welcome----");
  lcd.setCursor(0,1);
   lcd.print("Avail. Slots: 4");
  
    }*/
    //  else
    
    
  
    
if(cm[0] <=10)
  {
    
     
    
    
    servo9g.attach(SERVO9G_PIN_SIG);         // 1. attach the servo to correct pin to control it.
    servo9g.write(servo9gTargetPosition);  // 2. turns servo to target position. Modify target position by modifying the 'ServoTargetPosition' definition above.
    delay(3000);                              // 3. waits 500 milliseconds (0.5 sec). change the value in the brackets (500) for a longer or shorter delay in milliseconds.
                               // 5. waits 500 milliseconds (0.5 sec). change the value in the brackets (500) for a longer or shorter delay in milliseconds.
    //servo9g.detach(); 

       
  }
  else if(cm[1] <=10)
  {
    servo9g.attach(SERVO9G_PIN_SIG);         // 1. attach the servo to correct pin to control it.
    servo9g.write(servo9gTargetPosition);  // 2. turns servo to target position. Modify target position by modifying the 'ServoTargetPosition' definition above.
    delay(3000);                              // 3. waits 500 milliseconds (0.5 sec). change the value in the brackets (500) for a longer or shorter delay in milliseconds.
                               // 5. waits 500 milliseconds (0.5 sec). change the value in the brackets (500) for a longer or shorter delay in milliseconds.
    //servo9g.detach(); 

   
    
  }else{

    servo9g.write(servo9gRestPosition);
  }
}
long microsecondsToCentimeters(long microseconds){
return microseconds / 29 / 2;
}
long checkDistance(int x){
    long duration;
  digitalWrite(trigPin[x], LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin[x], HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin[x], LOW);
  duration = pulseIn(echoPin[x], HIGH);
  cm[x] = microsecondsToCentimeters(duration);
  delay(100);
}
void rec()
{
  int a;
  a=Wire.read();
   Serial.print("----------------------------------------------");
    Serial.print(a);
  if(a==0)
  {
   
/*         lcd.clear();
  lcd.setCursor(0,0);
 lcd.print("-----Welcome----");
  lcd.setCursor(0,1);
   lcd.print("Parking Full");  
   */
   Serial.print("parking full");
  }
  else if(a==1)
  {
    /*   lcd.clear();
  lcd.setCursor(0,0);
 lcd.print("-----Welcome----");
  lcd.setCursor(0,1);
   lcd.print("Slots Available");
  */Serial.print("Slot availible");
  }
  else if(a==2)
  {
     if(cm[1] <=10)
  {
    servo9g.attach(SERVO9G_PIN_SIG);         // 1. attach the servo to correct pin to control it.
    servo9g.write(servo9gTargetPosition);  // 2. turns servo to target position. Modify target position by modifying the 'ServoTargetPosition' definition above.
    delay(3000);                              // 3. waits 500 milliseconds (0.5 sec). change the value in the brackets (500) for a longer or shorter delay in milliseconds.
     flag1=0;                          // 5. waits 500 milliseconds (0.5 sec). change the value in the brackets (500) for a longer or shorter delay in milliseconds.
    //servo9g.detach(); 

   
    
  }
  else 
  {
    servo9g.attach(SERVO9G_PIN_SIG);
    servo9g.write(servo9gRestPosition);
    flag1=1;
    
  }

  
  } else if(a==3)
  {
     if(cm[0] <=10)
  {
    servo9g.attach(SERVO9G_PIN_SIG);         // 1. attach the servo to correct pin to control it.
    servo9g.write(servo9gTargetPosition);  // 2. turns servo to target position. Modify target position by modifying the 'ServoTargetPosition' definition above.
    delay(3000);                              // 3. waits 500 milliseconds (0.5 sec). change the value in the brackets (500) for a longer or shorter delay in milliseconds.
     flag3=0;                          // 5. waits 500 milliseconds (0.5 sec). change the value in the brackets (500) for a longer or shorter delay in milliseconds.
    //servo9g.detach(); 

   
    
  }
  else 
  {
    servo9g.attach(SERVO9G_PIN_SIG);
    servo9g.write(servo9gRestPosition);
    flag3=1;
    
  }

  
  }
  
  
}  

void req()
{
// Serial.print("123");
int a,b;  
a=(parkStatus[2]*100)+(parkStatus[1]*10)+(parkStatus[0]*1);
b=(parkStatus[3]*1)+(parkStatus[4]*10);
//String s = parkStatus[0]+"!"+parkStatus[1]+"!"+parkStatus[2]+"!"+parkStatus[3]+"!"+parkStatus[4]
if(flag2==0)
{
 // Serial.print(a);
  //delay(1000);
  Serial.print("\n");
Wire.write(a);
flag2=1;
}
else if(flag2==1)
{
 // Serial.print(b);
 // delay(1000);
 // Serial.print("\n");
  Wire.write(b);
  flag2=0;
  
}
}
