# ESP32 Wi-Fi Robot Car

A Wi-Fi controlled 2WD robot car built on the ESP32. The car is driven from a phone or laptop browser over a local network, with no app needed.

## Hardware
- ESP32 development board
- L298N dual H-bridge motor driver
- 2 x DC geared motors (2WD chassis)
- Battery pack for motor power

## How it works
1. The ESP32 connects to a Wi-Fi network and prints its IP address on the Serial Monitor.
2. It runs a small web server that serves a control page with Forward, Backward, Left, Right and Stop buttons.
3. Each button calls a URL on the ESP32. The firmware sets the L298N input pins (IN1-IN4) to drive the two motors in the required direction.
4. Turning is done by spinning the two motors in opposite directions (differential drive).

## Pin connections
| ESP32 GPIO | L298N pin |
|---|---|
| 26 | IN1 |
| 27 | IN2 |
| 14 | IN3 |
| 12 | IN4 |

## Concepts used
Embedded C/C++, GPIO control, H-bridge motor driving, Wi-Fi networking, HTTP web server on a microcontroller

## Files
- `robot_car.ino`: main robot control firmware
- `ESP32_MAC_Address.ino`: utility sketch to read the board MAC address

## How to run
1. Install Arduino IDE and the ESP32 board package.
2. Open `robot_car.ino` and enter your Wi-Fi name and password.
3. Select ESP32 Dev Module and the correct COM port, then upload.
4. Open the Serial Monitor (115200 baud) to read the IP address.
5. Open that IP in a browser on the same Wi-Fi network and control the car.

## Future improvements
- PWM speed control using the L298N enable pins
- Ultrasonic sensor for obstacle avoidance
- Live control dashboard using MQTT
