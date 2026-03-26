# 🏠 Smart Room Occupancy, Safety and Energy Optimization System

> **MPCA Laboratory Project — 4th Semester CSE**
> PES University EC Campus | Team 3 | Section: SEM 4-H

---

## 👥 Team Members

| Name | SRN |
|---|---|
| Shreelakshmi G Bhat | PES2UG24CS478 |
| Aniyath Amrita Pradeep | PES2UG24CS919 |
| Shreya S Mattimadu | PES2UG24CS486 |

---

## 📌 Overview

The **Smart Room Occupancy, Safety and Energy Optimization System** is an Arduino-based embedded system that automates room management using a set of basic sensors. It monitors occupancy, ambient light, temperature, and air quality to intelligently control electrical devices — reducing unnecessary energy consumption while ensuring occupant safety.

---

## ✨ Features

- **Occupancy Detection** — HC-SR04 ultrasonic sensor detects the presence of a person and controls lights/fans accordingly.
- **Natural Light Sensing** — UV sensor measures ambient light and suppresses artificial lighting during daytime.
- **Temperature-Based Fan Control** — LM35 temperature sensor activates the fan automatically when the room exceeds a set threshold.
- **Smoke & Fire Alert** — MQ-2 gas/smoke sensor triggers a buzzer and warning LED upon detecting smoke or fire.
- **Visual Status Indicators** — Three LEDs (Red, Yellow, Green) indicate the current safety status of the room at a glance.

---

## 🧰 Hardware Components

| Component | Model | Function | Arduino Pin |
|---|---|---|---|
| Microcontroller | Arduino UNO | Central control unit | — |
| Ultrasonic Sensor | HC-SR04 | Occupancy detection | Trig: D9, Echo: D10 |
| Light Sensor | UV Sensor Module | Ambient light detection | VCC, GND (Digital) |
| Temperature Sensor | LM35 | Room temperature monitoring | A0 |
| Smoke Sensor | MQ-2 Gas Sensor | Smoke / fire detection | Analog In |
| Buzzer | Active Buzzer | Audible fire/smoke alert | — |
| LED (Red) | 5mm LED | Warning indicator | D8 |
| LED (Yellow) | 5mm LED | Caution indicator | D7 |
| LED (Green) | 5mm LED | Safe status indicator | — |
| Breadboard | Standard | Component connections | — |
| Jumper Wires | M-M / M-F | All connections | — |

---

## 🗂️ Project Structure

```
smart-room-system/
│
├── src/
│   └── smart_room_system.ino       # Main Arduino sketch
│
├── docs/
│   ├── circuit_diagram.md          # Pin mapping and wiring details
│   └── components.md               # Component specifications and datasheets
│
├── simulation/
│   └── tinkercad_notes.md          # Notes for Tinkercad/Wokwi simulation
│
├── .gitignore
├── LICENSE
└── README.md
```

---

## ⚙️ System Logic

```
START
│
├─ Read Ultrasonic Sensor
│   ├─ Person Detected?
│   │   ├─ YES → Check UV Sensor
│   │   │         ├─ Dark? → Turn ON Light
│   │   │         └─ Bright? → Keep Light OFF
│   │   │       Check Temperature (LM35)
│   │   │         ├─ Temp > Threshold? → Turn ON Fan
│   │   │         └─ Temp ≤ Threshold? → Keep Fan OFF
│   │   └─ NO → Turn OFF Light & Fan
│
├─ Read Smoke Sensor (MQ-2) — Always Active
│   ├─ Smoke Detected?
│   │   ├─ YES → Sound Buzzer + RED LED ON
│   │   └─ NO → GREEN LED ON, Buzzer OFF
│
└─ LOOP
```

---

## 🚀 Getting Started

### Prerequisites

- [Arduino IDE](https://www.arduino.cc/en/software) (v1.8.x or 2.x)
- Arduino UNO board + USB cable
- All hardware components listed above

### Uploading the Code

1. Clone this repository:
   ```bash
   git clone https://github.com/<your-username>/smart-room-system.git
   cd smart-room-system
   ```

2. Open `src/smart_room_system.ino` in the Arduino IDE.

3. Select the correct board and port:
   - **Board:** Arduino UNO
   - **Port:** (the COM/tty port your board is connected to)

4. Click **Upload**.

### Wiring

Refer to [`docs/circuit_diagram.md`](docs/circuit_diagram.md) for the full wiring guide and pin mapping.

---

## 📊 Thresholds (Configurable in Code)

| Parameter | Default Value |
|---|---|
| Occupancy Distance | < 100 cm |
| Temperature Threshold | 30 °C |
| Smoke Detection Level | Analog > 400 |

These values can be modified at the top of `smart_room_system.ino`.

---

## 🔮 Future Improvements

- Add an LCD/OLED display for real-time sensor readout
- Integrate Wi-Fi (ESP8266/ESP32) for remote monitoring
- Implement a mobile app dashboard
- Add a people counter for multi-occupancy rooms
- Data logging to SD card

---

## 📄 License

This project is licensed under the MIT License — see the [LICENSE](LICENSE) file for details.

---

*Submitted as part of the MPCA Laboratory Project, 4th Semester CSE, PES University EC Campus, 2026.*
