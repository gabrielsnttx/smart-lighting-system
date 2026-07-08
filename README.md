# Smart Lighting Automation System

## Overview

This project presents an intelligent lighting automation system capable of controlling indoor lighting based on room occupancy. The system uses two ultrasonic sensors to detect people entering and leaving an environment, allowing automatic control of the lighting according to the number of occupants.

## Objectives

- Automate lighting control based on real-time room occupancy.
- Reduce unnecessary energy consumption.
- Apply embedded systems and sensor-based automation concepts.

## Technologies Used

- Arduino
- C/C++ Programming
- Ultrasonic Sensors (HC-SR04)
- Electronic Components

## System Operation

The system uses two ultrasonic sensors positioned at the entrance of the environment to identify the direction of movement. One sensor detects entry events while the other detects exit events, allowing the controller to maintain an accurate count of people inside the room.

When the occupancy count is greater than zero, the lighting system is activated. When the room becomes empty, the lights are automatically turned off.

## Future Improvements

- IoT connectivity for remote monitoring.
- Add an audible feedback system using a buzzer to indicate successful person detection and occupancy count updates.


