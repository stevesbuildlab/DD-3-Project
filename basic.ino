#include <ESP32Servo.h>

// Servo setup
Servo myservo;
const int servoPin = 0; // GPIO0 for the servo signal

void setup() {
  Serial.begin(115200);

  // Initialize servo
  myservo.attach(servoPin);

}

void loop() {
  // SG90 servos have 180 degrees of turn in an ideal situation
  // Most servos will not reach the full 180 degrees and it varies by individual servo
  // 90 being staight ahead (center)
  // Animation will start by moving the head to center position, then move in one direction, center itself, then the other direction

  //Set random angles

  int randomPos1 = random(30, 60); // generates random angle between 30 and 60 {default (30, 60)}
  int randomPos2 = random(110, 150); //generates random angle between 110 and 150 {default (110, 150)}

  //Begin movement loop

  myservo.write(90); // sets servo to center
  delay(3500); // Wait for the servo to move
  myservo.write(randomPos1); // moves servo to randomPos1
  delay(2000); // Wait for the servo to move
  myservo.write(90); // returns to center
  delay(3000); // Wait for the servo to move
  myservo.write(randomPos2); // moves servo to randomPos2
  delay(2000); // Wait for the servo to move
  
  // finished loop will repeat until power is removed (servo resets to center at beginning of next loop)
}
