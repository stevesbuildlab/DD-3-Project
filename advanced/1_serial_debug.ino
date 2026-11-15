// ============================================================================
// PROJECT: DD-3 Droid — Extension 1: Live Serial Monitor Debugging
// HARDWARE: ESP32-C3 Super Mini + SG90 Micro Servo + 3.7V Lithium Battery
// DESCRIPTION: Same movement as basic.ino, plus live status messages printed
//              to the Arduino Serial Monitor so students can see the exact
//              random angles and pause times the droid chooses.
//
// SETUP NOTE: In Arduino IDE, make sure "Tools > USB CDC On Boot" is set to
//             "Enabled", then open "Tools > Serial Monitor" (set to 115200 baud).
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
const unsigned long CENTER_PAUSE_MIN = 2000;
const unsigned long CENTER_PAUSE_MAX = 4500;
const unsigned long SIDE_PAUSE_MIN   = 1000;
const unsigned long SIDE_PAUSE_MAX   = 3000;

Servo headServo;

// Helper function with Serial Monitor logging added
void moveHeadWithDebug(String directionLabel, int targetAngle, unsigned long minWait, unsigned long maxWait) {
  // Pick the random pause time first so we can print everything before waiting
  unsigned long randomPause = random(minWait, maxWait + 1);

  // Print a clean status line to the computer screen
  Serial.print("Looking ");
  Serial.print(directionLabel);
  Serial.print(" -> Angle: ");
  Serial.print(targetAngle);
  Serial.print(" deg | Holding for: ");
  Serial.print(randomPause / 1000.0, 2);  // Convert milliseconds to seconds with 2 decimals
  Serial.println(" sec");

  // Move the servo and wait
  headServo.write(targetAngle);
  delay(randomPause);
}

void setup() {
  Serial.begin(115200);
  delay(1500);  // Give the ESP32-C3 USB Serial connection a moment to open

  Serial.println("========================================");
  Serial.println("DD-3 Droid Online! Starting scan loop...");
  Serial.println("========================================");

  randomSeed(esp_random());
  headServo.attach(SERVO_PIN);
  headServo.write(CENTER_ANGLE);
}

void loop() {
  int leftAngle  = random(LEFT_MIN_ANGLE, LEFT_MAX_ANGLE + 1);
  int rightAngle = random(RIGHT_MIN_ANGLE, RIGHT_MAX_ANGLE + 1);

  moveHeadWithDebug("CENTER", CENTER_ANGLE, CENTER_PAUSE_MIN, CENTER_PAUSE_MAX);
  moveHeadWithDebug("LEFT  ", leftAngle,    SIDE_PAUSE_MIN,   SIDE_PAUSE_MAX);
  moveHeadWithDebug("CENTER", CENTER_ANGLE, CENTER_PAUSE_MIN, CENTER_PAUSE_MAX);
  moveHeadWithDebug("RIGHT ", rightAngle,   SIDE_PAUSE_MIN,   SIDE_PAUSE_MAX);
}
