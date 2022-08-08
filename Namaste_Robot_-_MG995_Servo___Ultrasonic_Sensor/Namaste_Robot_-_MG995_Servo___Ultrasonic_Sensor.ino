/* This example Arduino Sketch controls the complete rotation of
 *  SG995 Servo motor by using its PWM and Pulse width modulation technique
 */

#include <Servo.h> // include servo library to use its related functions
#define Servo_PWM 6 // A descriptive name for D6 pin of Arduino to provide PWM signal
#define Servo_PWM2 9
Servo MG995_Servo;  // Define an instance of of Servo with the name of "MG995_Servo"
Servo MG995_Servo1;

#define echoPin 8 // attach pin D2 Arduino to pin Echo of HC-SR04
#define trigPin 5 //attach pin D3 Arduino to pin Trig of HC-SR04
// defines variables
long duration; // variable for the duration of sound wave travel
int distance; // variable for the distance measurement

void setup() {
  Serial.begin(9600); // Initialize UART with 9600 Baud rate
  MG995_Servo.attach(Servo_PWM);  // Connect D6 of Arduino with PWM signal pin of servo motor
  MG995_Servo1.attach(Servo_PWM2);
  pinMode(trigPin, OUTPUT); // Sets the trigPin as an OUTPUT
  pinMode(echoPin, INPUT); // Sets the echoPin as an INPUT
  Serial.begin(9600); // // Serial Communication is starting with 9600 of baudrate speed
}

void loop() {
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
      Serial.print(distance);
      Serial.println("motor - 0");// You can display on the serial the signal value
      MG995_Servo.write(30); //Turn clockwise at high speed
      MG995_Servo1.write(70);
      delay(3000);
      MG995_Servo.detach();//Stop. You can use deatch function or use write(x), as x is the middle of 0-180 which is 90, but some lack of precision may ch
      MG995_Servo.attach(Servo_PWM);
      MG995_Servo1.attach(Servo_PWM2);ange this value
      MG995_Servo1.detach();
      delay(2000);
      MG995_Servo.attach(Servo_PWM);//Always use attach function after detach to re-connect your servo with the board
      MG995_Servo1.attach(Servo_PWM2);
      Serial.println("motor - 1");//Turn left high speed
      MG995_Servo.write(85);
      MG995_Servo1.write(20);
      delay(3000);
      MG995_Servo.detach();//Stop
      MG995_Servo1.detach();
      delay(2000);
      }
    }
}
