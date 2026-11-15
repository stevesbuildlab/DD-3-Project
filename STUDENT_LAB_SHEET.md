# STEM Robotics Lab: Animating the DD-3 Droid

**Student Name:** __________________________  **Date:** ______________

## 1. Mission Overview
In this lab, you will bring a 3D-printed **DD-3 Star Wars Droid** to life by wiring an **ESP32-C3 Super Mini** microcontroller and an **SG90 servo motor**, uploading code from [stevesbuildlab/DD-3-Project](https://github.com), and customizing the droid's personality.

### Parts Checklist
* [ ] 3D-Printed DD-3 Droid Body & Head
* [ ] **ESP32-C3 Super Mini** Microcontroller
* [ ] **SG90** Micro Servo Motor (+ plastic servo horn)
* [ ] **3.7V Lithium Battery** + Power Switch
* [ ] Jumper Wires & USB-C Data Cable

---

## 2. Wiring Diagram & Battery Safety

> **CRITICAL BATTERY SAFETY RULE**
> **ALWAYS turn your power switch OFF (or unplug the 3.7V battery) before plugging a USB-C cable into your computer!** The ESP32-C3's `5V` pin connects straight to the USB port. Leaving the battery connected while plugged into USB will push power backward into the battery and can damage it.

```text
[ 3.7V BATTERY ]                                       [ ESP32-C3 SUPER MINI ]
================                                       =======================
 (+) Red ----[ SWITCH ]----+--------------------------> [ 5V ]
                           |
                           |   [ SG90 SERVO ]
                           |   ==============
                           +-> (Red) Power


 (-) Black ----------------+--------------------------> [ GND ]
                           |
                           +-> (Brown/Black) Ground


                               (Orange/Yellow) Signal -> [ GPIO 0 ]
```

### Quick-Reference Wiring Table

| Component Wire | Connects To (ESP32-C3 Pin) | Purpose |
| :--- | :--- | :--- |
| **Battery (+)** *(through switch)* | `5V` | Supplies power to the board and motor |
| **Battery (-)** | `GND` | Common ground connection |
| **SG90 Red Wire** | `5V` | Supplies power to the servo motor |
| **SG90 Brown/Black Wire** | `GND` | Common ground connection |
| **SG90 Orange/Yellow Wire** | `0` *(GPIO 0)* | Carries angle signals from the code |

*(Instructor Check: Have your teacher inspect your wiring before turning on the power switch! **Initials:** _____)*

---

## 3. Getting & Uploading the Code
1. Open **`basic.ino`** from [https://github.com](https://github.com) and paste it into the Arduino IDE.
2. Confirm the **`ESP32Servo`** library is installed (**Sketch > Include Library > Manage Libraries**).
3. Select **Tools > Board > ESP32C3 Dev Module** and set **USB CDC On Boot** to **Enabled**.
4. Make sure your battery switch is **OFF**, plug in your USB-C cable, and click **Upload**.
5. When the servo centers at **90°**, unplug USB, press-fit the 3D-printed head facing straight ahead, and flip the battery switch **ON** to test!

---

## 4. Student Lab Experiments
*(Remember: Always switch the battery OFF before plugging in USB to upload changes!)*

### Challenge 1: The "Nervous" Droid
Make DD-3 act like it just heard a loud noise and is frantically checking its surroundings.
* **What did you change?**
  * `SIDE_PAUSE_MIN` / `MAX`: Changed from `1000 / 3000` to `_______ / _______`
  * `CENTER_PAUSE_MIN` / `MAX`: Changed from `2000 / 4500` to `_______ / _______`
* **Observation:** How did lowering the millisecond values change the droid's behavior?
  _________________________________________________________________________

### Challenge 2: Wide-Angle Lookout
Right now, DD-3 only turns between `30°` and `150°`. Widen its field of view without hitting the mechanical limits of the servo (`0°` and `180°`).
* **New `LEFT_MIN_ANGLE`:** _______°  |  **New `RIGHT_MAX_ANGLE`:** _______°
* **Safety Question:** Why do we avoid setting the servo angles to `0°` or `180°`?
  _________________________________________________________________________

### Challenge 3: Custom Personality Design
Invent your own mood for DD-3 (examples: *Sleepy*, *Curious*, *Suspicious*, or *Guard Duty*). Adjust both the angle ranges and pause times to match your mood.
* **Chosen Personality Name:** __________________________
* **Describe how your code changes created this personality:**
  _________________________________________________________________________
  _________________________________________________________________________

---

## 5. Reflection Questions
1. **Why do we use `randomSeed(esp_random());` in the `setup()` section of our code?**
   _________________________________________________________________________
2. **In Arduino code, how many milliseconds equal 2.5 seconds?** ______________ ms
3. **What happens if you connect the SG90 servo's orange signal wire to Pin 4 instead of Pin 0, without changing the code?**
   _________________________________________________________________________
