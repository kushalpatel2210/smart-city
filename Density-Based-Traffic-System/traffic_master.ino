

// Include the required Wire library for I2C
#include <Wire.h>
#include "Arduino.h"
int k;
int ls1;
int ls2;
int z = 0;
int x ;
int road[4]; 
int stats[4];
int top = -1;


  void setup() {
  Wire.begin(); 
  Serial.begin(9600);
 // Wire.onReceive(receiveEvent);
  //Wire.onRequest(requestEvent);
  pinMode(11, INPUT);
  pinMode(10, INPUT);
  pinMode(9, INPUT);
  pinMode(8, INPUT);
  pinMode(5 ,INPUT);
  pinMode(4, INPUT);
  pinMode(3, INPUT);
  pinMode(2, INPUT);
  /*pinMode(ledg, OUTPUT);
  pinMode(ledg2, OUTPUT);
  pinMode(ledr, OUTPUT);
  pinMode(ledr2, OUTPUT);
*/
  }

void loop() {
  if(top != 3)
  {
 startAnalyze();
  }
  else
  {
    LightRemaining();
    top = -1;
  }
}

void startAnalyze()
{
   //digitalWrite(ledr, HIGH);
  //digitalWrite(ledr2, HIGH);
IRcheck1();
IRcheck2();
IRcheck3();
IRcheck4();
int highVal;
highVal = road[0];  // just to start it off
for (int n = 0; n < 4; n++) {
   if (road[n] >= highVal) {
        highVal = road[n];
         k=n+1;
   }
}

Wire.beginTransmission(9);
Wire.write(k);
Wire.endTransmission();
push(k);
delay(5000);
}
void LightRemaining()
{
  int a[] = {1,1,1,1};
  int b[] = {2,2,2,2};
  int c[] = {3,3,3,3};
  int d[] = {4,4,4,4};
  int flaga = 0;
  int flagb = 0;
  int flagc = 0;
  int flagd = 0;
  for(int i=0;i<4;i++)
  {
    if(a[i] == stats[i])
    {
      a[i] = 0;
    }
    if(b[i] == stats[i])
    {
      b[i] = 1;
    }
    if(c[i] == stats[i])
    {
      c[i] = 2;
    }
    if(d[i] == stats[i])
    {
      d[i] = 3;
    }
  }
  for(int i=0;i<4;i++)
  {
    if(a[i] != 1)
    {
      flaga = 1;
    }if(b[i] != 2)
    {
      flagb = 1;
    }
    if(c[i] != 3)
    {
      flagc = 1;
    }
    if(d[i] != 4)
    {
      flagd = 1;
    }
  }
  if(flaga == 0)
  {
Wire.beginTransmission(9);
Wire.write(a[0]);
Wire.endTransmission();
delay(5000);
  }
    if(flagb == 0)
  {
Wire.beginTransmission(9);
Wire.write(b[0]);
Wire.endTransmission();
delay(3000);
  }
    if(flagc == 0)
  {
Wire.beginTransmission(9);
Wire.write(c[0]);
Wire.endTransmission();
delay(5000);
  }
    if(flagd == 0)
  {
Wire.beginTransmission(9);
Wire.write(d[0]);
Wire.endTransmission();
delay(5000);
  }
}
void push(int x)
{
  top = top+1;
  stats[top] = x;
  Serial.print(top);
}
  
  /* void requestEvent()
   {

    IRcheck1();
    IRcheck2();
    Wire.write(road1);
    Wire.write(road2);
 
   }
   void receiveEvent()
   {

    receivedata();
   

 
  }*/

void IRcheck1(){
  int count = 0;
  int detect1 = digitalRead(2);
  int detect2 = digitalRead(3);
  if(detect1 == LOW)
  {
    count++;
  }
  if(detect2 == LOW)
  {
    count++;
  }
  road[0] = count;
}

void IRcheck2(){
  int count = 0;
  int detect3 = digitalRead(4);
  int detect4 = digitalRead(5);
  if(detect3 == LOW)
  {
    count++;
  }
  if(detect4 == LOW)
  {
    count++;
  }
  road[1] = count;
}

void IRcheck3(){
  int count = 0;
  int detect5 = digitalRead(8);
  int detect6 = digitalRead(9);
  if(detect5 == LOW)
  {
    count++;
  }
  if(detect6 == LOW)
  {
    count++;
  }
  road[2] = count;
}
void IRcheck4(){
  int count = 0;
  int detect7 = digitalRead(10);
  int detect8 = digitalRead(11);
  if(detect7 == LOW)
  {
    count++;
  }
  if(detect8 == LOW)
  {
    count++;
  }
  road[3] = count;
}
/*void changeled1(int x)
{
  if(x == 1)
  {
    digitalWrite(ledg, HIGH);
  }
  else
  {
    digitalWrite(ledr, HIGH);
  }
 
}
void changeled2(int y)
{
  if(y == 1)
  {
    digitalWrite(ledg2, HIGH);
  }
  else
  {
    digitalWrite(ledr2, HIGH);
  }
}
/*void receivedata()
{
 if(z=0)
 {
      ls1 = Wire.read();
     Serial.print(ls1);

    changeled1(ls1);
     z++;
 }
 else
 {
  ls2 = Wire.read();
  Serial.print(ls2);
  changeled2(ls2);
  z = 0;
 }
}*/
