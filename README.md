Automatic Liquid Dispenser with Cup Level Detection

Firmware for an automatic liquid dispensing system using ultrasonic sensors to detect cup presence and monitor liquid level during dispensing. The system activates a pump to dispense liquid and stops automatically once the desired level is reached.
This project demonstrates sensor-based automation, real-time distance measurement, and actuator control using a microcontroller.

System Overview

The system uses two ultrasonic sensors:

Sensor	Function
Sensor 1	Detects the presence of a cup
Sensor 2	Measures the liquid level inside the cup

When a cup is detected, the pump begins dispensing liquid. As the liquid level rises, the second ultrasonic sensor monitors the fill level. Once the liquid reaches a predefined threshold, the pump stops and a buzzer notifies the user.

Hardware Components

Microcontroller (Arduino compatible)
2 × Ultrasonic sensors (HC-SR04 or similar)
Liquid pump
Buzzer
Power supply
Tubing for liquid dispensing

Pin Configuration
Pump and Buzzer
Pin 2  -> Pump Motor
Pin 3  -> Buzzer
Ultrasonic Sensor 1 (Cup Detection)
Pin 10 -> Trigger
Pin 11 -> Echo
Ultrasonic Sensor 2 (Liquid Level Detection)
Pin 5 -> Trigger
Pin 6 -> Echo
System Operation
1. Cup Detection

Sensor 1 continuously checks for the presence of a cup.
If the measured distance is less than 5 cm, the system assumes a cup is placed under the dispenser.
distance1 < 5 cm

2. Liquid Dispensing

Once a cup is detected:
The pump is activated
Liquid begins filling the cup

3. Liquid Level Monitoring
Sensor 2 measures the distance to the liquid surface.
If the measured distance becomes less than 4 cm, the system assumes the cup is full.
distance2 < 4 cm

4. Automatic Stop and Notification
When the liquid level reaches the threshold:
The pump is turned OFF
The buzzer is activated to notify the user
The buzzer produces a periodic alert until the cup is removed.

Firmware Features
Automatic cup detection
Real-time liquid level monitoring
Pump control for automatic dispensing
Overflow prevention
Audible alert using buzzer
Continuous distance monitoring
Distance Measurement
Distance is calculated using ultrasonic echo timing:
distance = pulseDuration * 0.0176

This converts the echo time into centimeters.

Example Serial Output
Cup Sensor: 3.4 cm
Liquid Level: 6.2 cm
Applications

This project can be applied to:
automatic beverage dispensers
contactless liquid dispensing systems
smart refill systems
hygiene-focused dispensing devices

Future Improvements
Possible improvements include:
adjustable fill levels
LCD display for system status
flow rate monitoring
touchless activation using IR sensors
IoT integration for monitoring

Author

Frederick Joshua N. Carlos
Embedded Systems | Firmware Development | Hardware Integration
