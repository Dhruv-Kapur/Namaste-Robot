#include<Servo.h>
Servo Myservo;
int pos;
void setup()
{
  Myservo.attach(3);
}

void loop() {
myservo.write(180);
delay(1000);
myservo.write(0);
}
