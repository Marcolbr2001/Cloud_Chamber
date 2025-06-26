# ☁️ Cloud Chamber V2 – Peltier-Cooled Particle Detector

A fully custom-built **cloud chamber** designed to visualize ionizing particles using thermoelectric cooling, alcohol vapor, and electric field control. Built from scratch using Peltier elements, water cooling, and a touchscreen interface for real-time monitoring and control.

---

## 🔬 Project Overview

This cloud chamber uses:
- **4 small upper Peltier cells** to maintain a cool top environment.
- **1 large lower Peltier cell** with **water-cooled heat dissipation** for achieving the necessary supersaturated alcohol vapor zone.
- An optional **electric field** to enhance particle visualization by regulating vapor distribution.

A **touchscreen display** allows users to:
- Toggle individual Peltier cells and the electric field.
- Read temperatures from all Peltier surfaces and the coolant.
- View the alcohol sensor reading inside the chamber.
- Activate LED lights and the liquid pump for circulation.
- Monitor real-time **graphs** of all environmental parameters.

---

## 🧠 Features

- 🧊 Multi-zone thermoelectric cooling (top & bottom Peltier arrays)
- 💧 Water-cooled plate for heat dissipation
- ⚡ Electric field activation system
- 📊 Live graphing of sensors over time
- 💡 LED illumination for enhanced visibility
- 📱 Intuitive touchscreen GUI for full control
- 🔄 Alcohol vapor concentration monitoring

---

## 🖼️ Images

### 📦 Construction Phase
<p align="center"> <img src="https://github.com/user-attachments/assets/23f7969d-1943-4642-8b9c-0758fa434a94" alt="Construction phase" width="500"/> </p>

### ✨ Operational View
<p align="center"> <img src="https://github.com/user-attachments/assets/5c9d3f43-40d9-40d1-8693-3f338915dc58" alt="Chamber on" width="500"/> </p>
<p align="center"> <img src="https://github.com/user-attachments/assets/0dd0311a-0c6d-4123-b3af-6a66448d3c83" alt="Chamber illuminated" width="500"/> </p>

![camp](https://github.com/user-attachments/assets/0dd0311a-0c6d-4123-b3af-6a66448d3c83)

Why do we choose liquid cooler?
<p align="center"> <img src="https://github.com/user-attachments/assets/6b176e9f-cd7c-4a02-90d2-e081bc61d8ab" alt="Sensor analysis" width="600"/> </p>---

## 🎥 Demo Video

<p align="center">
  <a href="https://youtu.be/soM0Bwh30M0" target="_blank">
    <img src="https://img.youtube.com/vi/soM0Bwh30M0/hqdefault.jpg" alt="Watch the video" width="600">
  </a>
</p>

Watch the chamber in action as it visualizes ionizing particle tracks!

---

## 📂 Code and Architecture

The full codebase (available in this repository) manages:
- Temperature sensing and regulation
- Touchscreen display logic (UI & interaction)
- Peltier and pump control
- Electric field toggling
- Real-time data logging and graphing

See `Cloud_Chamber_V2/` folder for:
- Arduino source code
- UI screens and logic
- Sensor management and logging

---

## ⚙️ Future Improvements
- PID-based temperature regulation
- Data export via SD card or serial
- Automatic particle event detection
- Wireless control/logging (e.g., via ESP32)

---

## 📬 Contact

For questions, collaborations or suggestions:  
**📧 marcolbr2001@gmail.com**

---

