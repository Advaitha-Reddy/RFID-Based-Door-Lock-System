# RFID-Based Door Lock System

## Overview
With the increasing need for security in both residential and commercial areas, traditional lock-and-key mechanisms are becoming outdated. This project presents an RFID-based door lock system that provides a more secure, efficient, and convenient method of access control.

RFID (Radio Frequency Identification) technology is widely used for tracking and authentication applications, ranging from inventory management to baggage tracking in the aviation industry. The system developed in this project uses RFID tags and an RFID reader to grant access only to authorized users.

The project is built using an Arduino Nano microcontroller, RFID reader module, servo motor for locking/unlocking, LCD display for UID visualization, and a buzzer for access indication.

---

## Features

- RFID-based secure authentication
- Automatic door locking and unlocking mechanism
- Displays scanned RFID tag UID on LCD screen
- Audio indication using buzzer
- Easy to use and cost-effective
- Suitable for homes, offices, and restricted-access areas

---

## Objectives

- Design and implement a secure door locking system using RFID technology
- Allow access only to authorized RFID tags
- Improve security and convenience over traditional lock-and-key systems

---

## RFID Technology

RFID (Radio Frequency Identification) is a wireless communication technology used for identification and tracking purposes.

An RFID system mainly consists of:
- RFID Tags
- RFID Reader

This project uses:
- Passive RFID Tags
- High Frequency (HF) RFID operation range

### Advantages of RFID Technology

#### Efficiency
RFID systems can read multiple tags quickly, reducing processing time.

#### Accuracy
Eliminates manual data entry errors and improves reliability.

#### Security
RFID tags can be encrypted, making unauthorized access difficult.

---

## Components and Materials

### Hardware Components

| Component | Description |
|---|---|
| Arduino Nano | Microcontroller used for processing and control |
| RFID Reader (MFRC522) | Reads RFID tags |
| RFID Tags | Unique identifiers for authorized users |
| LCD Display with I2C Module | Displays scanned tag UID |
| Servo Motor | Controls the locking mechanism |
| Buzzer | Indicates access status |
| Door Locker | Physical locking mechanism |
| Door Hinges | Used for door setup |
| Connecting Wires | Circuit connections |
| Power Supply | Powers the Arduino and peripherals |

---

### Software Components

| Software | Purpose |
|---|---|
| Arduino IDE | Writing and uploading code |
| MFRC522 Library | Interfacing with RFID Reader |
| Servo Library | Controlling servo motor |

---

## Working Principle

1. The RFID reader continuously scans for RFID tags.
2. When a tag is brought near the reader, its UID is read.
3. The Arduino compares the UID with stored authorized IDs.
4. If the UID matches:
   - Servo motor unlocks the door
   - Buzzer indicates successful access
   - LCD displays access information
5. If the UID does not match:
   - Access is denied
   - Buzzer alerts unauthorized attempt

---

## Circuit Connections

- RFID Reader connected to Arduino Nano via SPI communication
- Servo motor connected to PWM pin
- LCD connected using I2C interface
- Buzzer connected to digital output pin

---

## Applications

- Smart home security systems
- Office access control
- Hotel room security
- Laboratory and restricted-area access
- Attendance and authentication systems

---

## Future Enhancements

- Add password authentication along with RFID
- Integrate IoT for remote monitoring
- Mobile app-based access control
- Face recognition integration
- Cloud-based access logs

---

## Conclusion

This RFID-based door lock system provides a secure, reliable, and efficient access control mechanism. By replacing traditional lock-and-key systems with RFID technology, the project enhances security while improving user convenience. The system can be further expanded with IoT and biometric technologies for advanced smart security solutions.

---

## Libraries Used

```cpp
#include <SPI.h>
#include <MFRC522.h>
#include <Servo.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
```

---

## Author
Advaitha Patti
