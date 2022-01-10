# MRA
Mobile Robotic Arm with App and Web Interface using Microcontrollers


The project works having the interaction between different software and hardware components as it’s backbone. The microcontroller used for the robotic car and sensor reading is the NodeMCU, the microcontroller used for the robotic arm is an Arduino UNO board.
There are two apps developed using python, one for the car and for the arm.
The apps interact using the principal of serial communication, when we press a button or move the slider, the respective data is sent in bytes to a port on the PC, from where the microcontroller can detect the byte and take a decision regarding motion and locomotion of the arm and the car respectively.
An ultrasonic sensor and an IR sensor are attached on the car, telling us how far the object is and whether we have reached or not. An IR sensor is attached to the claw of the arm, telling us whether the object has been picked, or dropped.
All the hardware programming is done on Arduino IDE, apps have been made on SPYDER IDE, and the website has been made on Microsoft Visual Studio. The three IDEs mentioned provide the best environment for development.
Information from the sensors is sent to firebase database, from firebase we extract the data onto our website using JavaScript API’s.
All of the project has been coded extensively and thorough troubleshooting has been done. Coding for the hardware has been done on the Arduino IDE and the website has been made using HTML, CSS, JavaScript and Bootstrap and as mentioned above the hardware and the apps interact via ports.
