````md
# Driver Drowsiness Alert System 🚗💤

## Overview
The Driver Drowsiness Alert System is an Arduino-based safety project designed to monitor a driver’s eye state using an IR sensor. If the driver’s eyes remain closed for dangerous periods, the system provides staged warnings through a buzzer and automatically stops the vehicle motors to prevent accidents.

This project demonstrates embedded systems, real-time monitoring, and automation for road safety applications.

---

## Features
- Real-time eye closure detection using IR sensor
- Multi-stage warning system:
  - **2 seconds:** Mild warning buzzer
  - **4 seconds:** Strong warning buzzer
  - **7 seconds:** Continuous alarm + motor stop
- Automatic motor restart when eyes reopen
- Non-blocking time tracking using `millis()`
- Simple ON/OFF motor control
- Beginner-friendly Arduino implementation

---

## Components Used
- Arduino Uno
- IR Eye Blink Sensor
- Buzzer
- Motor Driver Module (L298N/L293D)
- DC Motors
- Battery/Power Supply
- Jumper Wires
- Chassis (optional for vehicle model)

---

## Circuit Connections

### IR Sensor:
- VCC → 5V
- GND → GND
- OUT → Pin 3

### Buzzer:
- Positive → Pin 8
- Negative → GND

### Motor Driver:
- IN1 → Pin 9
- IN2 → Pin 10
- IN3 → Pin 11
- IN4 → Pin 12

---

## Working Principle
1. IR sensor continuously monitors driver’s eye state.
2. If eyes close:
   - Timer starts
   - Warning stages activate based on duration
3. If eyes reopen:
   - Timer resets
   - Buzzer stops
   - Motors continue
4. If eyes remain closed for too long:
   - Vehicle stops automatically

---

## Timing Logic
| Eye Closure Duration | Action |
|----------------------|--------|
| 0–2 sec | Normal |
| 2–4 sec | Mild warning |
| 4–7 sec | Strong warning |
| 7+ sec | Alarm + Stop motors |

---

## Code Highlights
- `millis()` used for accurate timing
- `const int` for fixed pin assignments
- Modular motor functions:
  - `startMotors()`
  - `maintainMotors()`
  - `stopMotors()`

---


## Applications

* Driver safety systems
* Smart vehicles
* Transportation automation
* Embedded systems education
* Accident prevention research

---

## Future Improvements

* GSM emergency alert system
* LCD status display
* GPS tracking
* Vibration alerts
* Camera-based eye detection
* Machine learning integration

---

## Learning Outcomes

* Arduino programming
* Sensor interfacing
* Motor control
* Real-time automation
* Safety system design
* GitHub project documentation

---

## Author

**Abdul Haseeb**
**Mohammad Touqeer Hussain**

---

## License

This project is open-source and available under the MIT License.

---

## Acknowledgment

This project was developed as an academic embedded systems/Arduino safety solution to address driver fatigue and improve transportation safety.

