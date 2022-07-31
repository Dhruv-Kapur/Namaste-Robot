#include<Servo.h>
#define echoPin 8
#define trigPin 6
Servo Myservo;
Servo Myservo2;
long duration;
int distance;
int pos;

void setup()
{
  Serial.begin(9600);
  Myservo.attach(3);
  Myservo2.attach(5);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}

void loop()
{
  digitalWrite(trigPin, LOW);
  delay(2);
  
  digitalWrite(trigPin, HIGH);
  delay(10);
  
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = duration * 0.034 / 2;
  Serial.println(distance);
    
  if (distance>11)
    {
    if (distance<20) {
      for(pos=0;pos<=90;pos++){
        Myservo.write(pos);
        Myservo2.write(90 - pos);
    
        delay(5);
      }
      delay(1000);
      
      for(pos=90;pos>=0;pos--){
        Myservo.write(pos);
        Myservo2.write( 90 - pos);
        delay(5);
      }
      delay(1000);
      }
    }
  }
