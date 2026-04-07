# LABVIEW_Control
LabView-enabled control of KeFIRE (Kenya's First Rocket Engine) under NAKUJA Project.

## 1. Labview Essentials
Compared to other ways of controlling a system, Labview is very direct and operates at a much more user-friendly level, while allowing a lot of benefits; but knowing how to program fundamentally allows the user to have a very easy time transferring knowledge of how data flows through functions, data type conversions, from input to output with the different intermediary levels.
In Labview, variables are implemented through control elements like sliders, data entry boxes, dials, etc. Functions are depicted by function boxes where the user provides inputs through data lines and the function box outputs processed data through data lines. Data at different states is represented by the differently colored lines, distinguished by differing data types e.g. Orange-Float, Pink-String, Blue-Integer etc.
These are the 3 main building blocks of Labview, present in any project.
Helper structures such as While/For loops and Case statements are implemented as a box where everything (inputs, data lines, functions, outputs) run the same way they would in any other programing technique. Initial inputs may be fed into the structure from outside and the same can be done for final data that can be passed out of the structure after it runs its course.
With those core principles, powerful Labview programs can be built to control complex systems in real time, remotely and in a visually simple environment that is condusive for rapid iteration and modification.
One of the most distinguishing capabilities of Labview is **implicit multi-threading**. This is that every program in place runs *simultaneously* without need for additional clarification or deep definition of the workflow. each stage simply awaits that all data it requires is made available before running. It puts it head and shoulders above the likes of C++ **MCU** programs that rely on single thread operations, crucial for large and complex control and data visualization systems.

## 2. KEFIRE SOLENOID VALVE CONTROL

<img width="1919" height="1034" alt="Screenshot 2026-04-07 091635" src="https://github.com/user-attachments/assets/22519f8d-e72e-4cce-9aef-9d52263f4c68" />

## **Overview**
First draft for the **LabView Dashboard** for remote SV (solenoid Valve) control. This version establishes a **VISA communication pipeline** and the UI for valve control.

## **Technical Details**
* **Protocol:** Uses **NI-VISA** for serial communication with our ESP32 MCU to send command packets.
* **Basic Architecture:** Implements a **Data polling style loop** for responsive updates.
    * Handles **VISA Open, Write, Read, Flush and Close** within the main execution flow.
    * Handles **Boolean to string conversion** for the write step, then handles **string to boolean** for the read step.
    * The MCU waits on the Dashboard to send data in every loop, thus no delay is required on the MCU code since flow control is handled by LabView.

## **Hardware Requirements**
* Active MCU on a serial port.
* Matching Baud rates: i.e., **9600** for Arduino, **115200** for ESP32.

## **Testing Directions**
1.  Connect the MCU to a USB port and confirm port number using **Device Manager** (Windows).
2.  Upload code to the MCU via the Arduino IDE and make the appropriate connections to the pins.
3.  Open the LabView file (`SolenoidDAQandControl.lvproj`) and select the COM port from the dropdown labelled **"ESP32"**.
4.  Run the LabView VI to control the Solenoid Valves using the toggle switches in the UI.

## **Pro-Tips**
* If using Arduino, adjust the **Baud Rate to 9600** from 115200.
* If using ESP32, ensure the device is powered by the **3V3 pin** or if using 5V signal should be stepped down via a **voltage divider**; to avoid damaging the pins.
