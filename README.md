# Lecturer Availability Door Announcer

## Abstract
Traditionally a student would have to summon a lecturer in a shared office by knocking on the door. This disturbs the other lecturers in the office, and the desired lecturer may not even be present.

A system to alert a specific lecturer to the presence of someone at the door is not currently widely adopted. To investigate how such a system should work, it is crucial to gain insight into the current solutions to the individual technical challenges.

## Introduction
The main aim of this project is to develop a battery-operated device with inputs to receive interaction from the student, and outputs to feed back to the student and lecturer. It is to be fixed to the inside of the door of a multiple occupied lecturer's room. Through this device anyone outside the door shall be able to raise the attention of a single lecturer, and not to everyone in the room (which is what knocking at the door does). When a student operates the device, a notification should be sent to the appropriate lecturer’s mobile phone. It should also be possible for students to see the status/availability of a lecturer from the device, which the lecturer can set.


## Hardware

 - ESP32-WROOM-32
 - Waveshare 2.9" B/W ePaper
 - TCA9548A i2c multiplexer
 - VCNL4020 IR proximity sensor(s)
