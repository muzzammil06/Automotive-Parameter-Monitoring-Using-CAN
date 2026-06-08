# 🚗 CAN-Based Vehicle Monitoring System

### Real-Time Distributed Automotive Monitoring Using LPC2129 and CAN Protocol

---

## 📖 Overview

The **CAN-Based Vehicle Monitoring System** is a distributed embedded system developed using **LPC2129 ARM7 Microcontrollers** and the **Controller Area Network (CAN) Protocol**. The project demonstrates real-time communication between multiple nodes for monitoring essential vehicle parameters such as **engine temperature**, **fuel level**, and **turn indicators**.

The system follows a multi-node architecture similar to modern automotive Electronic Control Units (ECUs), where individual nodes perform dedicated tasks and exchange information over a common CAN bus.

---

## 🎯 Objectives

* Implement real-time CAN communication between embedded nodes.
* Monitor engine temperature using DS18B20.
* Measure fuel level using ADC.
* Control vehicle indicators using external interrupts.
* Display vehicle information on a 20x4 LCD dashboard.
* Demonstrate distributed embedded system architecture.

---

## 🏗️ System Architecture

```text
                 Fuel Monitoring Node
               (ADC Acquisition Unit)
                        │
                        │ CAN BUS
                        ▼

 DS18B20 ───► Main Dashboard Node ───► Indicator Control Node
 Sensor          (Monitoring ECU)         (Lighting ECU)
                        │
                        ▼
                  20x4 LCD Display
```

---

## ⚙️ Functional Description

### 🔹 Main Dashboard Node

The Main Node acts as the central controller of the system.

Responsibilities:

* Reads temperature from DS18B20 sensor.
* Receives fuel percentage from Fuel Node.
* Displays vehicle information on LCD.
* Sends indicator commands through CAN.
* Handles external interrupts.

---

### 🔹 Fuel Monitoring Node

The Fuel Node is responsible for fuel-level measurement.

Responsibilities:

* Reads analog fuel value using ADC.
* Converts ADC value into fuel percentage.
* Transmits fuel information through CAN.

---

### 🔹 Indicator Control Node

The Indicator Node controls LED-based turn indicators.

Responsibilities:

* Receives CAN messages.
* Decodes indicator commands.
* Generates left and right LED patterns.
* Simulates automotive turn indicators.

---

## 📡 CAN Communication

### CAN Message IDs

| CAN ID | Data    | Description     |
| ------ | ------- | --------------- |
| 1      | 1       | Left Indicator  |
| 1      | 2       | Right Indicator |
| 1      | 3       | Indicator OFF   |
| 2      | 0 – 100 | Fuel Percentage |

### Example

```text
CAN ID : 2
DATA   : 75
```

Meaning:

```text
Fuel Level = 75%
```

---

## 🌡️ Temperature Monitoring

The project uses the **DS18B20 Digital Temperature Sensor** based on the **One-Wire Communication Protocol**.

### Working Sequence

1. Sensor Reset
2. Presence Detection
3. Temperature Conversion Command
4. Internal Conversion
5. Scratchpad Memory Read
6. LCD Display Update

---

## ⛽ Fuel Monitoring

Fuel level is simulated using a potentiometer connected to the ADC channel.

### Processing Flow

```text
Fuel Sensor
     │
     ▼
ADC Conversion
     │
     ▼
Fuel Percentage Calculation
     │
     ▼
CAN Transmission
     │
     ▼
LCD Dashboard Display
```

---

## ↔️ Indicator Control

Indicator control is implemented using external interrupts.

| Interrupt | Function        |
| --------- | --------------- |
| EINT0     | Left Indicator  |
| EINT1     | Right Indicator |

The Main Node transmits indicator commands through CAN, and the Indicator Node generates LED sequences accordingly.

---

## 🖥️ Dashboard Display

### Normal State

```text
SMART VEHICLE SYS

TEMP : 32°C

FUEL : ████ 75%

TURN : OFF   ← →
```

### Left Indicator Active

```text
SMART VEHICLE SYS

TEMP : 32°C

FUEL : ████ 75%

TURN : LEFT  ← →
```

### Right Indicator Active

```text
SMART VEHICLE SYS

TEMP : 32°C

FUEL : ████ 75%

TURN : RIGHT ← →
```

---

## 🛠️ Hardware Components

| Component       | Description                |
| --------------- | -------------------------- |
| LPC2129         | ARM7 Microcontroller       |
| DS18B20         | Digital Temperature Sensor |
| 20x4 LCD        | Dashboard Display          |
| CAN Transceiver | CAN Communication          |
| Potentiometer   | Fuel Level Simulation      |
| LEDs            | Indicator Visualization    |
| Push Buttons    | Indicator Control          |
| Power Supply    | System Supply              |

---

## 📂 Repository Structure

```text
CAN-Based-Vehicle-Monitoring-System/
│
├── Main_Node/
│   ├── main_pro.c
│   ├── lcd.c
│   ├── ds18b20.c
│   ├── interrupts.c
│   ├── can.c
│   └── ...
│
├── Fuel_Node/
│   ├── node1_pro.c
│   ├── adc_pro.c
│   └── ...
│
├── Indicator_Node/
│   ├── node2_pro.c
│   └── ...
│
├── Images/
│   ├── Main_Node.jpg
│   ├── Fuel_Node.jpg
│   ├── Indicator_Node.jpg
│   └── lcd_dashboard.jpg
│
└── README.md
```

---

## 📸 Project Gallery

### Hardware Setup

<img width="1280" height="720" alt="All_Nodes" src="https://github.com/user-attachments/assets/215c0b5e-27b6-4f09-86d1-e1c7ba535721" />


```text
Images/hardware_setup.jpg
```

### Dashboard Display
```text
Images/lcd_dashboard.jpg
```
<img width="720" height="1280" alt="lcd_dashboard" src="https://github.com/user-attachments/assets/3f0ad1ff-ace9-4a00-9d0b-6a24b7caa205" />


### Indicator Demonstration

<img width="713" height="1280" alt="WhatsApp Image 2026-06-08 at 9 47 01 AM" src="https://github.com/user-attachments/assets/8df88254-488f-4fc1-b1dc-1175dcd7b182" />

---

## 🧠 Concepts Demonstrated

* Embedded C Programming
* ARM7 LPC2129 Programming
* CAN Protocol
* ADC Interfacing
* One-Wire Communication
* Interrupt Handling
* LCD Interfacing
* Real-Time Embedded Systems
* Distributed Embedded Architecture

---

## 📊 Results

The system successfully demonstrates:

* Reliable CAN communication between multiple nodes.
* Real-time engine temperature monitoring.
* Fuel-level acquisition and display.
* Interrupt-driven indicator control.
* Dashboard visualization using a 20x4 LCD.
* Distributed automotive communication architecture.

---

## 🚀 Future Scope

* Vehicle Speed Monitoring
* RPM Measurement
* GPS Integration
* Wireless CAN Gateway
* Cloud Data Logging
* IoT Dashboard Connectivity
* Automotive Diagnostics

---

## 👨‍💻 Author

**SYED MOHAMMED MUZZAMMIL**

Embedded Systems | ARM7 LPC2129 | CAN Protocol | Embedded C

---

### ⭐ A Distributed Embedded Automotive Monitoring System Demonstrating Real-Time CAN Communication, Sensor Integration, and Dashboard Visualization.
