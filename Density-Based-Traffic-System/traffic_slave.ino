#include<Wire.h>

int ledg1 =8;
int ledg2 =9;
int ledg3 =10;
int ledg4 =11;
int ledr1 =3;
int ledr2 =4;
int ledr3 =5;
int ledr4 =6;
int ledno;
void setup() {
  Serial.begin(9600);
 Wire.begin(9);
 Wire.onReceive(LedChange);  
 pinMode(ledg1, OUTPUT);
 pinMode(ledg2, OUTPUT);
 pinMode(ledg3, OUTPUT);
 pinMode(ledg4, OUTPUT);
 pinMode(ledr1, OUTPUT);
 pinMode(ledr2, OUTPUT);
 pinMode(ledr3, OUTPUT);
 pinMode(ledr4, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:

}

void LedChange()
{
  ledno = Wire.read();
  Serial.print(ledno);
  if(ledno == 1)
  {
    digitalWrite(ledg1, HIGH);
    digitalWrite(ledr2, HIGH);
    digitalWrite(ledr3, HIGH);
    digitalWrite(ledr4, HIGH);
    digitalWrite(ledr1, LOW);
    digitalWrite(ledg2, LOW);
    digitalWrite(ledg3, LOW);
    digitalWrite(ledg4, LOW);
  }
  else if(ledno == 2)
  {
    digitalWrite(ledr1, HIGH);
    digitalWrite(ledg2, HIGH);
    digitalWrite(ledr3, HIGH);
    digitalWrite(ledr4, HIGH);
    digitalWrite(ledg1, LOW);
    digitalWrite(ledr2, LOW);
    digitalWrite(ledg3, LOW);
    digitalWrite(ledg4, LOW);
  }
  else if(ledno == 3)
  {
    digitalWrite(ledr1, HIGH);
    digitalWrite(ledr2, HIGH);
    digitalWrite(ledg3, HIGH);
    digitalWrite(ledr4, HIGH);
    digitalWrite(ledg1, LOW);
    digitalWrite(ledg2, LOW);
    digitalWrite(ledr3, LOW);
    digitalWrite(ledg4, LOW);
  }
  else
  {
    digitalWrite(ledr1, HIGH);
    digitalWrite(ledr2, HIGH);
    digitalWrite(ledr3, HIGH);
    digitalWrite(ledg4, HIGH);
    digitalWrite(ledg1, LOW);
    digitalWrite(ledg2, LOW);
    digitalWrite(ledg3, LOW);
    digitalWrite(ledr4, LOW);
  }
}
