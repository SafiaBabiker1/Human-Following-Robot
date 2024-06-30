#include <NewPing.h>
#include <AFMotor.h>
//////////////////////////////////////
#define RIGHT A3
#define LEFT A2
#define TRIGGER_PIN A1
#define ECHO_PIN A0
#define MAX_DISTANCE 100
//////////////////////////////////////
NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE);

AF_DCMotor Motor1(1, MOTOR12_1KHZ);
AF_DCMotor Motor2(2, MOTOR12_1KHZ);
AF_DCMotor Motor3(3, MOTOR34_1KHZ);
AF_DCMotor Motor4(4, MOTOR34_1KHZ);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(RIGHT, INPUT);
  pinMode(LEFT, INPUT);
}

void loop() {
  delay(50);
  unsigned int distance = sonar.ping_cm();
  Serial.print("distance");
  Serial.println(distance);


  int Right_Value = digitalRead(RIGHT);
  int Left_Value = digitalRead(LEFT);

  Serial.print("RIGHT");
  Serial.println(Right_Value);
  Serial.print("LEFT");
  Serial.println(Left_Value);

  if ((Right_Value == 1) && (distance >= 10 && distance <= 30) && (Left_Value == 1)) {

    Motor1.setSpeed(150);  //define motor1 speed:
    Motor1.run(FORWARD);   //rotate motor1 clockwise:
    Motor2.setSpeed(150);  //define motor2 speed:
    Motor2.run(FORWARD);   //rotate motor2 clockwise:
    Motor3.setSpeed(150);  //define motor3 speed:
    Motor3.run(FORWARD);   //rotate motor3 clockwise:
    Motor4.setSpeed(150);  //define motor4 speed:
    Motor4.run(FORWARD);   //rotate motor4 clockwise:

  } else if ((Right_Value == 1) && (Left_Value == 0)) {

    Motor1.setSpeed(150);
    Motor1.run(FORWARD);
    Motor2.setSpeed(150);  //define motor2 speed:
    Motor2.run(FORWARD);   //rotate motor2 clockwise:
    Motor4.setSpeed(150);
    Motor4.run(BACKWARD);
    Motor3.setSpeed(150);
    Motor3.run(BACKWARD);


  } else if ((Right_Value == 0) && (Left_Value == 1)) {

    Motor1.setSpeed(150);
    Motor1.run(BACKWARD);
    Motor2.setSpeed(150);  //define motor2 speed:
    Motor2.run(BACKWARD);  //rotate motor2 clockwise:
    Motor4.setSpeed(150);
    Motor4.run(FORWARD);
    Motor3.setSpeed(150);
    Motor3.run(FORWARD);

  } else if ((Right_Value == 1) && (Left_Value == 1)) {
    Motor1.setSpeed(0);
    Motor1.run(RELEASE);
    Motor2.setSpeed(0);
    Motor2.run(RELEASE);
    Motor4.setSpeed(0);
    Motor4.run(RELEASE);
    Motor3.setSpeed(0);
    Motor3.run(RELEASE);

  } else if (distance > 1 && distance < 10) {
    Motor1.setSpeed(0);
    Motor1.run(RELEASE);
    Motor4.setSpeed(0);
    Motor4.run(RELEASE);
    Motor3.setSpeed(0);
    Motor3.run(RELEASE);
    Motor4.setSpeed(0);
    Motor4.run(RELEASE);
  }
}
