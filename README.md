# ThreadCoach: An Open-Source Wearable Coaching System

**ThreadCoach** is a low-cost, open-source wearable system that uses e-textile sensors, IMUs, and real-time video analysis (via MediaPipe) to provide motion feedback for athletic training, accessibility, and education.

## 🌟 Project Highlights
- Real-time motion tracking of fingers, wrist, and elbow
- Combines data from flex/stretch sensors and IMUs
- BLE or USB communication with computer running MediaPipe
- Trigger vibration/LED/audio feedback for coaching
- Ideal for sprinting, throwing, badminton, or skill acquisition

---

## 🧰 Hardware Components
- [x] ESP32 Dev Board (e.g., DOIT ESP-WROOM-32)
- [x] 3 × Flex Sensors (e.g., 2.2")
- [x] 2 × IMUs (MPU6050/MPU9250)
- [x] TCA9548A I2C Multiplexer (optional)
- [x] 1 × Vibration Motor or Piezo Buzzer
- [x] 10kΩ resistors × 3 (for flex sensors)
- [x] LiPo Battery + charging module (optional)
- [x] Conductive thread, sports sleeve, jumper wires

---

## 🔌 Wiring Summary
| Sensor          | ESP32 Pin       |
|----------------|------------------|
| Flex Sensor 1  | GPIO 36 (A0)     |
| Flex Sensor 2  | GPIO 39 (A3)     |
| Flex Sensor 3  | GPIO 34 (A6)     |
| IMU 1 (Wrist)  | I2C: GPIO 21/22  |
| IMU 2 (Elbow)  | I2C: GPIO 21/22 (via TCA9548A) |
| Vibration Motor| GPIO 5           |

---

## 🧠 Software Structure
- **`/firmware/esp32_flex_imu_feedback.ino`** — Reads sensors, controls feedback
- **`/python/pose_tracking_inference.py`** — Uses MediaPipe to get pose landmarks
- **`/python/ble_feedback_sender.py`** — Sends commands to ESP32 via BLE (e.g., `"vibrate"`)
- **`/hardware/ThreadCoach_schematic.png`** — Visual wiring diagram
- **`/docs/demo_video.mp4`** — Optional demo showcase

---

## 🚀 Getting Started
1. Upload firmware to ESP32
2. Connect flex sensors and IMUs as described above
3. Run `pose_tracking_inference.py` to process webcam pose
4. Fuse data with sensor readings and run trained model
5. Trigger feedback if bad form detected!

---

## 📂 Repository Structure
```
ThreadCoach/
├── firmware/
│   └── esp32_flex_imu_feedback.ino
├── python/
│   ├── pose_tracking_inference.py
│   └── ble_feedback_sender.py
├── hardware/
│   └── ThreadCoach_schematic.png
├── docs/
│   └── demo_video.mp4 (optional)
└── README.md
```

---

## 📖 License
ThreadCoach is released under the MIT License. You are free to use, modify, and share this project — attribution appreciated!

---

## 🤝 Contributing
Pull requests, forks, and suggestions are welcome! This project is ideal for high school research, hackathons, and accessibility-focused design challenges.

---

## 🎓 Acknowledgements
Inspired by biomechanics, wearable tech, and the mission to democratize athletic coaching.

Made with 💡 by [Your Name Here] as part of the ISEF/JSHS project "ThreadCoach: Real-Time Motion Analysis via E-Textiles for Accessible Athletic Training."
