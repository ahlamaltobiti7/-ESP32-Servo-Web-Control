# ESP32 Servo Web Control

A web-based servo motor control system using ESP32.

The system allows the user to control a servo motor through a web interface hosted directly by the ESP32 Access Point.

The project uses two LEDs to indicate the servo status:

-  Red LED → Closed
-  Yellow LED → Open

The project was first tested using Wokwi simulation and then implemented on real ESP32 hardware.

---

## Project Overview

This project demonstrates how an ESP32 can be used to create a simple IoT control system.

The ESP32 creates its own Wi-Fi Access Point, allowing a phone or laptop to connect directly to the ESP32 without requiring an external Wi-Fi router.

After connecting to the ESP32 network, the user can open a web page and control the servo motor using two buttons:

- **Open** → Moves the servo to 90° and turns ON the yellow LED.
- **Close** → Moves the servo to 0° and turns ON the red LED.

---

## Features

- ESP32-based control system
- Wi-Fi Access Point mode
- Web-based control interface
- Servo motor control
- Red LED status indicator
- Yellow LED status indicator
- Wokwi simulation
- Real hardware implementation
- Simple and responsive web interface

---

## Components

| Component | Quantity |
|---|---:|
| ESP32 Development Board | 1 |
| Servo Motor | 1 |
| Red LED | 1 |
| Yellow LED | 1 |
| 220Ω Resistor | 2 |
| Breadboard | 1 |
| Jumper Wires | Several |
| USB Cable | 1 |

---

## Hardware Connections

The following GPIO pins are used in the project:

| Component | ESP32 Pin |
|---|---|
| Servo Signal | GPIO 27 |
| Red LED | GPIO 25 |
| Yellow LED | GPIO 26 |
| Servo VCC | 5V |
| Servo GND | GND |
| Red LED GND | GND |
| Yellow LED GND | GND |

### Red LED

~~~text
ESP32 GPIO25
     |
   220Ω
     |
  Red LED
     |
    GND
~~~

### Yellow LED

~~~text
ESP32 GPIO26
     |
   220Ω
     |
 Yellow LED
     |
    GND
~~~

### Servo

~~~text
Servo Signal → GPIO27
Servo VCC    → 5V
Servo GND    → GND
~~~

---

## Step 1: Simulate in Wokwi

Before connecting the real hardware, the project was tested using **Wokwi** to verify the circuit connections and program behavior.

The Wokwi simulation contains:

- ESP32
- Servo motor
- Red LED
- Yellow LED
- Two 220Ω resistors

### Wokwi Setup

The project was simulated using [Wokwi](https://wokwi.com/).

1. Create a new ESP32 project.
2. Replace the default `sketch.ino` with the project code.
3. Replace the default `diagram.json` with the diagram file included in this repository.
4. Make sure the `ESP32Servo` library is available.
5. Start the simulation.
6. Open the Serial Monitor.
7. Check the IP address displayed by the ESP32.
8. Use Wokwi's browser/network simulation to access the web interface.
9. Test the **Open** and **Close** buttons.
10. Confirm that the servo angle changes correctly.
11. Confirm that the correct LED turns on for each state.

### Wokwi Simulation Files

The Wokwi simulation files are included in this repository:

~~~text
diagram.json
esp32_servo_wed.ino
~~~

The `diagram.json` file contains the complete circuit configuration, while `esp32_servo_wed.ino` contains the ESP32 control program.

---

## Step 2: Real Hardware Implementation

After successfully testing the project in Wokwi, the same circuit was implemented using real hardware.

The real circuit contains:

- ESP32
- Servo motor
- Red LED
- Yellow LED
- Two 220Ω resistors
- Breadboard
- Jumper wires

### Real Hardware Circuit

![Real Hardware Circuit](Real%20Hardware%20Circuit.png)

---

## Wi-Fi Access Point

The ESP32 works as a **Wi-Fi Access Point** instead of connecting to an existing Wi-Fi network.

The ESP32 creates its own network:

~~~text
SSID: ESP32-Servo
Password: 12345678
~~~

After connecting to this network, the user can access the control page using:

~~~text
http://192.168.4.1
~~~

This allows the system to operate without an external Wi-Fi router.

---

## Web Control Interface

The ESP32 hosts a simple web page containing two control buttons.

### Open

When the **Open** button is pressed:

- Servo moves to 90°
- Yellow LED turns ON
- Red LED turns OFF

~~~text
Servo       → 90°
Yellow LED  → ON
Red LED     → OFF
~~~

### Close

When the **Close** button is pressed:

- Servo moves to 0°
- Red LED turns ON
- Yellow LED turns OFF

~~~text
Servo       → 0°
Red LED     → ON
Yellow LED  → OFF
~~~

---

## System Workflow

~~~text
                 ESP32
                   |
          Creates Wi-Fi Network
                   |
             ESP32-Servo
                   |
          Phone / Laptop Connects
                   |
            192.168.4.1
                   |
            Web Control Page
               /         \
           Open           Close
             |              |
        Servo → 90°    Servo → 0°
             |              |
      Yellow LED ON    Red LED ON
      Red LED OFF      Yellow LED OFF
~~~

---

## Program Workflow

~~~text
Start
  |
Initialize ESP32
  |
Initialize Servo and LEDs
  |
Create Wi-Fi Access Point
  |
Start Web Server
  |
Wait for User Command
  |
  +------ Open ------+
  |                 |
Servo → 90°     Yellow LED ON
Red LED OFF
  |
  +------ Close -----+
                    |
               Servo → 0°
               Red LED ON
               Yellow LED OFF
~~~

---


---

## Technologies Used

- ESP32
- Arduino C++
- Wi-Fi Access Point
- Web Server
- HTML
- Servo Motor
- Wokwi
- ESP32Servo Library

---

## Project Demonstration

After successful simulation, the same circuit and program were implemented and tested using a real ESP32 board, servo motor, and LEDs.

### Demo Video

![Project Demonstration](Demo%20Video.png)

[Watch the Project Demonstration](YOUR_VIDEO_LINK)

---

## Results

The system successfully achieved the following:

- Created a Wi-Fi Access Point using ESP32.
- Provided a web-based control interface.
- Controlled the servo motor remotely.
- Moved the servo to 90° when opening.
- Moved the servo to 0° when closing.
- Used the yellow LED to indicate the Open state.
- Used the red LED to indicate the Closed state.
- Successfully tested the system in Wokwi.
- Successfully implemented the system using real hardware.

---

## Conclusion

This project demonstrates how an ESP32 can be used to build a simple web-based IoT control system.

The ESP32 creates its own Wi-Fi network and hosts a web interface that allows the user to control a servo motor remotely. The LEDs provide a visual indication of the current servo state.

The system was successfully tested first in Wokwi and then implemented using real ESP32 hardware.
