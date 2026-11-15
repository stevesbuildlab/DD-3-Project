# DD-3 Star Wars Droid — STEM Robotics Project

Bring a 3D-printed **DD-3 Star Wars Droid** to life using an **ESP32-C3 Super Mini**, an **SG90 micro servo**, and a **3.7V lithium battery**. Designed for STEM classrooms and makerspaces, this repository includes beginner-friendly Arduino code, wiring instructions, and a printable student lab worksheet.

* **3D Printable Model:** [DD-3 by Clonan on Printables](https://printables.com)
* **Starter Code:** [`basic.ino`](basic.ino)
* **Student Handout:** [`STUDENT_LAB_SHEET.md`](STUDENT_LAB_SHEET.md)
* **Instructor Key:** [`TEACHER_ANSWER_KEY.md`](TEACHER_ANSWER_KEY.md)

---

## Hardware Required
* 3D-Printed DD-3 Droid Body & Head
* **ESP32-C3 Super Mini** Microcontroller
* **SG90** Micro Servo Motor (with plastic servo horn)
* **3.7V Lithium Battery** (LiPo or 14500/18650 Li-ion)
* Inline **Slide/Toggle Power Switch**
* Jumper wires & USB-C data cable

---

## Wiring Diagram & Battery Safety

> **CRITICAL BATTERY SAFETY WARNING**
> **ALWAYS turn the power switch OFF (or unplug the 3.7V battery) before plugging a USB-C cable into your computer.** On the ESP32-C3 Super Mini, the `5V` pin connects straight to the USB-C 5V line without a protection diode. Plugging in USB while the battery is connected will backfeed power into the lithium battery.

```text
   [ 3.7V LITHIUM BATTERY ]                  [ ESP32-C3 SUPER MINI ]
   ========================                  =======================
   (+) Red Wire ----[ POWER SWITCH ]----+---> [ 5V ]  (Power Input)
   (-) Black Wire ----------------------+---> [ GND ] (Ground)
                                        |
                                        |    [ GPIO 0 ] <---+

                                        |                   |
   [ SG90 MICRO SERVO ]                 |                   |
   ====================                 |                   |
   Red Wire (Power) --------------------+                   |
   Brown/Black Wire (Ground) -----------+                   |
   Orange/Yellow Wire (Signal) -----------------------------+
```

### Pinout Table

| Component Wire | ESP32-C3 Pin | Notes |
| :--- | :--- | :--- |
| **Battery (+)** *(via switch)* | `5V` | Powers both the microcontroller and servo |
| **Battery (-)** | `GND` | Common ground |
| **SG90 Red (Power)** | `5V` | Needs full battery voltage (~3.7V–4.2V) |
| **SG90 Brown/Black (Ground)** | `GND` | Common ground |
| **SG90 Orange/Yellow (Signal)** | `0` (`GPIO 0`) | Safe backup pins: `1, 3, 4, 5, 6, 7, 10` *(Avoid `2, 8, 9`)* |

---

## Arduino IDE Setup & Upload Steps

1. **Install the Board Package:**
   * Open Arduino IDE and go to **Tools > Board > Boards Manager**.
   * Search for **`esp32`** by Espressif Systems and click **Install**.
2. **Install the Servo Library:**
   * Go to **Sketch > Include Library > Manage Libraries**.
   * Search for **`ESP32Servo`** by Kevin Harrington and click **Install**.
3. **Configure Board Settings:**
   * **Board:** `ESP32C3 Dev Module`
   * **USB CDC On Boot:** `Enabled` *(Required if using Serial Monitor)*
   * **Port:** Select the COM/serial port for your ESP32-C3
4. **Upload & Center the Head:**
   * Confirm your battery switch is **OFF**.
   * Plug in your USB-C cable, open [`basic.ino`](basic.ino), and click **Upload**.
   * Once uploaded, the servo will move to **90° (straight ahead)**. Unplug USB, press-fit the 3D-printed head onto the servo facing forward, and turn on the battery switch to test!
