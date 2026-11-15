// ============================================================================
// PROJECT: DD-3 Droid — Extension 3: Unpredictable Behavior & Double-Takes
// HARDWARE: ESP32-C3 Super Mini + SG90 Micro Servo + 3.7V Lithium Battery
// DESCRIPTION: Uses "if / else" logic so DD-3 randomly decides whether to look
//              left, right, center, or do a quick "double-take" when it spots
//              something interesting!
// ============================================================================

#include <ESP32Servo.h>

// HARDWARE WIRING (Unplug battery or turn switch OFF before plugging in USB!)
const int SERVO_PIN = 0;

// DROID HEAD ANGLE SETTINGS (Degrees)
const int CENTER_ANGLE    = 90;
const int LEFT_MIN_ANGLE  = 30;
const int LEFT_MAX_ANGLE  = 60;
const int RIGHT_MIN_ANGLE = 110;
const int RIGHT_MAX_ANGLE = 150;

// PAUSE TIME SETTINGS (Milliseconds)
const unsigned long PAUSE_MIN = 1000;
const unsigned long PAUSE_MAX = 3500;

// DOUBLE-TAKE CHANCE (Percentage from 0 to 100)
// 25 means there is a 25% chance DD-3 will glance away and quickly look back!
const int DOUBLE_TAKE_CHANCE = 25;

Servo headServo;

void moveAndWait(int angle, unsigned long minWait, unsigned long maxWait) {
  headServo.write(angle);
  delay(random(minWait, maxWait + 1));
}

void setup() {
  Serial.begin(115200);
  randomSeed(esp_random());

  headServo.attach(SERVO_PIN);
  headServo.write(CENTER_ANGLE);
}

void loop() {
  // Step 1: Roll a 3-sided virtual die (picks 0, 1, or 2) to choose a direction
  int choice = random(0, 3);
  int chosenAngle = CENTER_ANGLE;

  if (choice == 0) {
    // Look Left
    chosenAngle = random(LEFT_MIN_ANGLE, LEFT_MAX_ANGLE + 1);
  } 
  else if (choice == 1) {
    // Look Right
    chosenAngle = random(RIGHT_MIN_ANGLE, RIGHT_MAX_ANGLE + 1);
  } 
  else {
    // Look Straight Ahead
    chosenAngle = CENTER_ANGLE;
  }

  // Move to the chosen direction and pause
  moveAndWait(chosenAngle, PAUSE_MIN, PAUSE_MAX);

  // Step 2: Roll a 100-sided virtual die to see if DD-3 does a "double-take"
  int roll = random(1, 101);  // Picks a number from 1 to 100

  if (roll <= DOUBLE_TAKE_CHANCE && chosenAngle != CENTER_ANGLE) {
    // Glance back toward center briefly...
    moveAndWait(CENTER_ANGLE, 250, 450);
    // ...then snap back to the exact same spot to double-check what it saw!
    moveAndWait(chosenAngle, 1200, 2200);
  }
}
