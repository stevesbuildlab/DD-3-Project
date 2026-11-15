// ============================================================================
// PROJECT: DD-3 Droid — Extension 2: Smooth Head Turning (Speed Control)
// HARDWARE: ESP32-C3 Super Mini + SG90 Micro Servo + 3.7V Lithium Battery
// DESCRIPTION: Instead of snapping instantly to a new angle, this code steps
//              1 degree at a time using a "for" loop so students can control
//              how fast or slow DD-3 turns its head.
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

// SPEED SETTING (Try changing this!)
// Controls the tiny delay (in milliseconds) between each 1-degree step.
//   - 5 ms  = Fast, snappy droid movement
//   - 15 ms = Smooth, natural scanning speed
//   - 35 ms = Very slow, dramatic or sleepy movement
const int STEP_DELAY_MS = 15;

// PAUSE TIME SETTINGS (Milliseconds)
const unsigned long CENTER_PAUSE_MIN = 2000;
const unsigned long CENTER_PAUSE_MAX = 4500;
const unsigned long SIDE_PAUSE_MIN   = 1000;
const unsigned long SIDE_PAUSE_MAX   = 3000;

Servo headServo;

// Keep track of where the head is currently pointing
int currentAngle = CENTER_ANGLE;

// Helper function that moves 1 degree at a time to reach targetAngle smoothly
void smoothMoveAndPause(int targetAngle, unsigned long minWait, unsigned long maxWait) {
  // Case 1: Turning toward a larger angle (e.g., 90 -> 140)
  if (targetAngle > currentAngle) {
    for (int angle = currentAngle; angle <= targetAngle; angle++) {
      headServo.write(angle);
      delay(STEP_DELAY_MS);
    }
  }
  // Case 2: Turning toward a smaller angle (e.g., 140 -> 45)
  else if (targetAngle < currentAngle) {
    for (int angle = currentAngle; angle >= targetAngle; angle--) {
      headServo.write(angle);
      delay(STEP_DELAY_MS);
    }
  }

  // Save the new position as our current angle
  currentAngle = targetAngle;

  // Hold still at the new angle for a random pause
  unsigned long randomPause = random(minWait, maxWait + 1);
  delay(randomPause);
}

void setup() {
  Serial.begin(115200);
  randomSeed(esp_random());

  headServo.attach(SERVO_PIN);
  headServo.write(CENTER_ANGLE);
  currentAngle = CENTER_ANGLE;
}

void loop() {
  int leftAngle  = random(LEFT_MIN_ANGLE, LEFT_MAX_ANGLE + 1);
  int rightAngle = random(RIGHT_MIN_ANGLE, RIGHT_MAX_ANGLE + 1);

  smoothMoveAndPause(CENTER_ANGLE, CENTER_PAUSE_MIN, CENTER_PAUSE_MAX);
  smoothMoveAndPause(leftAngle,    SIDE_PAUSE_MIN,   SIDE_PAUSE_MAX);
  smoothMoveAndPause(CENTER_ANGLE, CENTER_PAUSE_MIN, CENTER_PAUSE_MAX);
  smoothMoveAndPause(rightAngle,   SIDE_PAUSE_MIN,   SIDE_PAUSE_MAX);
}
