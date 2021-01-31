#include<Wire.h>
const int trigPin[] = {8,11};
const int echoPin[] = {9,12};
int led[] = {6,7};
long int cm[2];
int flag=0;
int stat[2];
void setup(){
  Serial.begin(9600);
  Wire.begin(8);
  pinMode(trigPin[0], OUTPUT);
  pinMode(echoPin[0], INPUT);
  pinMode(trigPin[1], OUTPUT);
  pinMode(echoPin[1], INPUT);;
  pinMode(led[0], OUTPUT);
  pinMode(led[1], OUTPUT);
  Wire.onRequest(sendSignals);
  }
void loop()
{
  for(int i=0;i<2;i++)
  {
checkDistance(i);
}
for(int j=0;j<2;j++)
{
  Serial.print(cm[j]);
  Serial.print("             ");
}
for(int y=0;y<2;y++)
{
  if(cm[y] <= 10)
  {
    digitalWrite(led[y], HIGH);
    stat[y] = 1;
  }
  else
  {
    digitalWrite(led[y], LOW);
    stat[y] = 0;
  }
  
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
void sendSignals()
{
  signals();
}
void signals()
{
  if(flag>1)
  {
    flag = 0;
  }
  Wire.write(stat[flag]);
}
