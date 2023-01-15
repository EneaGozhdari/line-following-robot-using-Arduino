# Line following Robot using Arduino

**What you need for the line following robot are :**

Arduino Board <br />
Adafruit Motor Shield <br />
Pololu QTR-8RC Reflectance Sensor <br />
2x DC Motor <br />
2x Wheel <br />
1x Omni-directional wheel <br />
Chassis (base) <br />
9V battery <br />
Battery connector <br />
Wires (female-female, male-female) <br />
ON/OFF button <br />
Glue gun <br />


**About the project :** 

This code is for an Arduino robot that uses line following sensors, specifically the QTRSensors library, to follow a line on the ground. The robot uses two motors, controlled by the AFMotor library, to move along the line.

The code starts by including the necessary libraries and declaring some variables such as the KP, KD, and the minimum and maximum speeds for the motors. It also defines the number of sensors and the timeout value.

The setup() function is called once when the Arduino is powered on or reset. It starts by delaying for 1.5 seconds and then calling the manual_calibration() function. It also sets the initial speed of the motors to 0.

The loop() function runs repeatedly after the setup function has completed. It starts by reading the values of the line following sensors and using that data to calculate the robot's position on the line. It uses the KP and KD variables to determine the speed of the motors based on the position of the robot on the line. It then sets the speed of the motors using the set_motors() function.

The set_motors() function is used to set the speed of the motors. It checks that the speed is within the defined minimum and maximum speeds and then sets the speed of the motors and makes them run forward.

The manual_calibration() function is used to calibrate the line following sensors by passing them over a line. The calibration values are then used to determine the position of the robot on the line.

It also uses the "debug" variable to output some data on the serial monitor to help understand the robot's behavior.

As you can see, the code is well commented and it helps to understand the functionality of the robot. The comments are in Albanian language but the variable names and function names are in english and it should be easy to understand.
