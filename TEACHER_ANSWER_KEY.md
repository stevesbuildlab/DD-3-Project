# Teacher Answer Key & Classroom Troubleshooting Guide

## Challenge Expected Results
* **Challenge 1 (The "Nervous" Droid):**
  * **Example Values:** `SIDE_PAUSE_MIN = 300`, `SIDE_PAUSE_MAX = 800`; `CENTER_PAUSE_MIN = 400`, `CENTER_PAUSE_MAX = 1000`.
  * **Observation:** Lowering millisecond values shortens the pause time between movements, making the droid dart its head rapidly back and forth instead of resting calmly.
* **Challenge 2 (Wide-Angle Lookout):**
  * **Example Values:** `LEFT_MIN_ANGLE = 15` to `20`, `RIGHT_MAX_ANGLE = 160` to `165`.
  * **Safety Question:** Low-cost SG90 servos have physical plastic stops inside their gears that vary slightly from motor to motor. Commanding `0°` or `180°` (or hitting the 3D-printed shell) can stall the motor, strip its plastic gears, or draw excessive current that resets the ESP32-C3.
* **Challenge 3 (Custom Personality):**
  * Look for logical alignment between numbers and behavior (e.g., *Sleepy* uses long pauses like `5000–8000` ms and small angles like `75°–105°`; *Guard Duty* uses wide angles and consistent pauses).

---

## Reflection Questions Answer Key
1. **Why do we use `randomSeed(esp_random());` in `setup()`?**
   * Computers generate "pseudo-random" numbers using a math formula. Without `randomSeed()`, the ESP32-C3 starts at the exact same point in that formula every time it powers on, causing the droid to repeat the exact same sequence of head turns every run. `esp_random()` reads electrical noise from the chip to pick a truly random starting point.
2. **How many milliseconds equal 2.5 seconds?**
   * **2500** ms (`2.5 × 1000`).
3. **What happens if you connect the signal wire to Pin 4 without changing the code?**
   * Nothing will move (or the servo will stay frozen at its starting position) because the code is still sending control pulses out of `SERVO_PIN = 0`. Students must update `const int SERVO_PIN = 4;` to match their wiring.

---

## Classroom Troubleshooting Tips
* **Board resets every time the servo moves:** The 3.7V lithium battery voltage is dipping below ~3.3V when the servo motor starts up (brownout reset). Recharge the battery, or solder a **100µF–470µF electrolytic capacitor** across the `5V` and `GND` pins to absorb motor current spikes.
* **Board will not upload code:** Make sure the battery switch is OFF, hold down the **BOOT** button on the ESP32-C3 while plugging in USB (or press **BOOT**, tap **RST**, then release **BOOT**), and try uploading again.
* **Head is crooked when powered on:** Upload the code first so the servo snaps to `90°`, unplug power, remove the servo horn, align the head straight forward, and press the horn back onto the gear.
