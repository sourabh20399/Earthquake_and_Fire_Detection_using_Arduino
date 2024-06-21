# Earthquake_and_Fire_Detection_using_Arduino

**HAZARD DETECTION SYSTEM**

<br/>
    
**ABSTRACT**

Safety plays a major role in today’s world and it is necessary that good safety systems are to be implemented in places of education and work. This system modifies the existing safety model installed in industries and this system can also to be used in homes and offices. 

The main objective of the project is designing Arduino based hazard detection system. The advantage of this automated detection and alerting system over the manual method is that it offers quick response time and accurate detection of an emergency.

Though there are several advancements in technology, only a very few of them are concentrated on predicting and detecting natural disasters such as Earthquake, Tsunami and such others. But using technology in these areas would save lives by warning people about the disaster at an earlier time. Hence, the objective is to come up with a cost-effective device which can detect fire and natural disasters and can be implemented in any remote area.

The scope of this device is to send alerts to people in advance of any disaster. It uses a Wi-Fi module which needs internet and sends data to the app installed on android phones.

In order to achieve this, a Wi-Fi module is interfaced to the Arduino board, TCP/UDP terminal application on the cell phone sends the commands to the receiver that is connected. Hazard detecting system developed here uses LDR sensor in order to detect the fire. As soon as the fire is detected it alerts the people by switching on the buzzer and it also turns on the sprinkler system. This system can also be used to detect the earthquake by using the accelerometer or tilt sensor. The sensed message will be sent to people through Wi-Fi system and it is also displayed in the LCD display.

The objective of Fire & Earthquake Detection system is to,

1\. Minimize the risk and consequences of an accidental event.

2\. Minimize the potential for hazardous occurrences

3\. Ensure a safe working environment for personnel

4\. Ensure adequate means of escape are provided

5\. Provide appropriate fire protection systems to rapidly bring under control and extinguish any reasonably foreseeable fire which could develop during normal operations.

<br/>

**COMPONENTS REQUIRED**

- Arduino Uno R3
- Regulated Power Supply
- 16\*2 LCD Display 
- Motor
- 12V SPDT Relay
- Buzzer
- Accelerometer
- LDR
- ESP8266 WIFI Module

<br/>

**DESCRIPTION**

The hazard system designed here detects earthquakes and fire threats. The monitoring system is constantly active and as soon as fire or earthquake is detected a message is sent to the concerned person and fire department and the siren is switched on. In case of fire, a sprinkler system is initiated. There is also a provision for the person who receives the message to switch off or on the power supply and gas supply of the building.

Accelerometer detects the change in axis (x, y, z) values and indicates earthquake if the tilt is beyond the safety values. The tilt going beyond the safety value also causes the buzzer to turn on. In addition to this a message is sent to the person in charge and the fire department.

LDR is used to detect fire in the building. As LDR goes to low state the buzzer turns on and signal is given to drive the motor. The message will be sent to the person through Wi-Fi module. The person can send a message from his mobile phone to the system to push the relays to high or low state in order to turn on or turn off the power supply or gas supply of the building. 

<br/>

**BLOCK DIAGRAM**

![Aspose Words 09c11ef7-e7bb-4c49-b981-fc1ae2096b2a 001](https://github.com/sourabh20399/Earthquake_and_Fire_Detection_using_Arduino/assets/84284202/bfae8fa1-9990-4e53-a05c-611abe34cac2)

<br/>

**APPLICATIONS:**

This system can be implemented in apartments, hotels, educational institution, shopping malls and all kinds of industries.

<br/>

**RESULTS**

The system detects any change in the temperature signaling a fire hazard and rapid changing position signaling earthquake.
- Earthquake is detected when there is rapid change in the 'X','Y' or 'Z' cordinates. When detected, an alarm is sounded and emergency text is displayed on the screen.
- Fire is detected when the temperate increases over the threshold. This triggers the alarm and sprinkler system.

![Aspose Words 09c11ef7-e7bb-4c49-b981-fc1ae2096b2a 002](https://github.com/sourabh20399/Earthquake_and_Fire_Detection_using_Arduino/assets/84284202/8c959caf-44e0-4471-b68b-8eef3f6cc868)

