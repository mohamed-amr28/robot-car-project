# 🏎️ Modular Joystick-Controlled Motorized Car

This project implements a professional **Layered Architecture** for an embedded motorized vehicle, featuring precise joystick control and an automated battery safety system[cite: 8, 15]. The codebase is strictly partitioned into **MCAL**, **HAL**, and **APP** layers to ensure modularity and ease of hardware portability[cite: 1, 9, 15].

---

## 🏗️ System Architecture

*   **Microcontroller Abstraction Layer (MCAL):** Handles low-level register manipulation for peripherals like GPIO and ADC[cite: 1, 4].
*   **Hardware Abstraction Layer (HAL):** Provides high-level APIs for external components including DC Motors, an analog Joystick, and Battery monitoring[cite: 9, 12, 14].
*   **Application Layer (APP):** Contains the `main.c` logic that orchestrates sensor input to drive hardware responses[cite: 15].

---

## 🛠️ Technical Features

### 1. Register-Level Peripheral Drivers
*   **GPIO Driver:** Implements `pinmode`, `digitalwrite`, and `digitalread` functions using direct memory access to `DDRx`, `PORTx`, and `PINx` registers[cite: 2, 3, 4].
*   **ADC Driver:** Configured for 10-bit resolution with an AVcc reference and a prescaler of 128 for high-accuracy analog sensing[cite: 1, 6].

### 2. Intelligent Motion Control
*   **Joystick Deadzone:** The system utilizes a deadzone between 300 and 720 to prevent accidental motor activation due to sensor noise[cite: 14].
*   **Directional Mapping:** Automatically translates analog X/Y coordinates into specific motor states: Forward, Backward, Left, Right, and Stop[cite: 10, 14].

### 3. Battery Safety & Monitoring
*   **Voltage Calculation:** Real-time voltage is derived using the formula: $V_{batt} = ADC \times 1.5 \times \frac{5.0}{1023.0}$[cite: 12].
*   **Safety Cutoff:** If the battery level falls below `BATTERY_LOW_THRESHOLD` (6.5V), the system triggers a `MOTOR_stop()` command and updates visual LED indicators to prevent hardware damage[cite: 12, 13, 15].

---

## 📂 Project Structure

| File | Layer | Description |
| :--- | :--- | :--- |
| `ADC_Program.c` | MCAL | ADC initialization and analog read logic[cite: 1]. |
| `GPIO_Program.c` | MCAL | Port and pin direction/value management[cite: 4]. |
| `MOTOR.c` | HAL | High-level motor direction abstraction[cite: 9]. |
| `Joystick.c` | HAL | Joystick reading and movement logic[cite: 14]. |
| `battery.c` | HAL | Battery level monitoring and calculation[cite: 12]. |
| `main.c` | APP | System setup and main execution loop[cite: 15]. |
| `Types.h` | Common | Standard data type definitions and bit macros[cite: 5]. |

---

## 🚀 Hardware Interface

*   **Motor Control:** Connected to Port B (Pins 0-3)[cite: 15].
*   **Joystick Input:** Analog signals on ADC Channels 0 and 1[cite: 14, 15].
*   **Battery Input:** Monitored via ADC Channel 2[cite: 12, 15].
*   **Visual Status:** Status LEDs mapped to Port D (Pins 2 and 3)[cite: 15].
