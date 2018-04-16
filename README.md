![dei cing 2](https://user-images.githubusercontent.com/36344537/36075929-44b53396-0f4d-11e8-983c-956414d058c5.png)
========


## Motivation
In the winter of Glasgow, Our team found roads always icy and slippery. Some people slip on roads because of ice and snow. So we decided to construct a system to prevent these accidents.
  
## Target
This project aims to prevent the formation of ice or snow by using brine as the anti-icing agent. Utilising the humidity and temperature sensor to detect the environmental conditions, the sprinkler spreads the brine water which is controlled by Raspberry Pi. IR sensor is used to detect people and animals. When it detects people, the sprinkler turns off.  

## Setup
<p align="center">
<img src="https://github.com/p4nd4m01um/team17/blob/master/ScreenShot/Setup_diagram.png" width="700px" height="400px" /> 
</p>

## Flow Diagram
<p align="center">
<img src="https://github.com/p4nd4m01um/team17/blob/master/ScreenShot/systemFlow.png" width="800px" height="550px" /> 
  
***

## Components

**1. _IR sensor: HC-SR501 PIR Motion Detector_**  
- Voltage: 5V – 20V  
- Power Consumption: 65mA  
- TTL output: 3.3V, 0V  
- Lock time: 0.2 sec  
- Trigger methods: L – disable repeat trigger, H enable repeat trigger  
- Sensing range: less than 120 degree, within 7 meters  
- Temperature: – 15 ~ +70  
- Dimension: 32*24 mm, distance between screw 28mm, M2, Lens dimension in diameter: 23mm

<p align="center">
<img src="https://github.com/p4nd4m01um/team17/blob/master/ScreenShot/sensor-HC-SR501.png" width="600px" height="200px" />
</p>


**2. _Humidity and temperature sensor: DHT22(AM2302)_**
- Low cost  
- 3 to 5V power and I/O  
- 2.5mA max current use during conversion (while requesting data)  
- Good for 0-100% humidity readings with 2-5% accuracy  
- Good for -40 to 80°C temperature readings ±0.5°C accuracy  
- No more than 0.5 Hz sampling rate (once every 2 seconds)  
- Single-bus data is used for communication between MCU and DHT22, it costs 5ms for single time
communication.  

<p align="center">
<img src="https://github.com/p4nd4m01um/team17/blob/master/ScreenShot/sensor-DHT22.png" width="700px" height="200px" />
</p>

**3. _Brushless DC Motor Pump Decdeal QR50E_**
- Low cost and Versatile
- 12V 5W Rating
- 280l/H pump quantity
- can handle different types of solutions including salt water (brine) and oil at various temparatures

<p align="center">
  <img src="https://github.com/p4nd4m01um/team17/blob/master/ScreenShot/motor%20rtep.jpg" width="400px" height="300px" />
</p>

## How to implement code  
1. Clone the repository.
2. Copy the Code/html to /var/www/html
3. In the Code folder, the main file can be executed.
4. If you changed the input/output pin number, you can use CMake to rebuild the main file.
5. Open browser enter the address of raspberryPi to access the user interface. 


## More information in WIKI
# YouTube Video:
<p align="center">
[![video](https://github.com/p4nd4m01um/team17/blob/master/ScreenShot/videoCover.jpg)](http://www.youtube.com/watch?v=QaHXD64GoVk "Anti-Icing System")
</p>

## University of Glasgow

Course name Real Time Embedded Programming, in association with University of Glasgow.  
Course convener: Dr. Bernd Porr 
