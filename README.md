# Arduino-Based Secure & Automated VIP Cabin System (Simulation)

> **A virtual prototyping project featuring multi-factor automation, secure password-based access control, and real-time environmental telemetry for VIP train cabins, implemented entirely in Proteus.**

## Project Overview
Developed for the **Microprocessor & Interfacing (BM-321L)** course at **Sir Syed University of Engineering and Technology (SSUET)**, this project demonstrates a fully functional virtual model of an automated cabin system. The project focuses on high-density peripheral interfacing and complex software logic to manage security and comfort within a simulated environment.

## Balanced Team Contributions
This project was a collaborative effort focusing on software-based system integration:

* **Shahmeer Hussain ([@shahmeeerx](https://github.com/shahmeeerx)):** Led the circuit design in Proteus, peripheral mapping, and technical performance reporting.
* **Amna Yousuf Judge ([@amna-014](https://github.com/amna-014)):** Developed the core firmware logic, including the password validation system and non-blocking timer.

## Technical Methodology
The system is implemented as a virtual prototype on an Arduino Uno, utilizing advanced pin optimization to handle multiple peripherals:

* **Secure Access Logic:** A simulated 4x4 Keypad interface facilitates password entry. The system validates input against the credential **"1214"** to grant access.
* **Environmental Telemetry:** An **LM35 sensor** provides real-time temperature monitoring, processed via the Arduino’s ADC and displayed on a **20x4 LCD**.
* **Non-Blocking Execution:** The "Length of Stay" timer is implemented using the `millis()` function, ensuring the system remains responsive to sensor inputs while updating the clock.
* **Automated Actuation:** Motion detection (simulated via push button) triggers the **DC Motor (Fan)** and **Bar LEDs (Lighting)** only when occupancy is detected, demonstrating energy-efficient logic.

## Simulation Results
![Project Demonstration](Working%20Image%20Proteus.png)
*Figure 1: Virtual prototype demonstration in Proteus showing the 'Access Granted' state with active timer and temperature display.*

## Repository Contents
* **`Project-Report.pdf`**: Comprehensive technical documentation including simulation steps and results.
* **`Arduino-Sketch.ino`**: Core C++ firmware optimized for Proteus-based peripheral interfacing.
* **`Diagrams/`**: High-resolution System Architecture and Software Flowchart images.
* **`Simulation/`**: Primary Proteus design file (`.pdsprj`) for virtual verification.

## Development Team
* **Shahmeer Hussain** — [@shahmeeerx](https://github.com/shahmeeerx) (2022F-BBM-014)
* **Amna Yousuf Judge** — [@amna-014](https://github.com/amna-014) (2022F-BBM-012)

---
_© 2026 Secure Cabin Project. Built for the Dept. of Biomedical Engineering, SSUET._
