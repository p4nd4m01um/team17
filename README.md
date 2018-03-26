![dei cing 2](https://user-images.githubusercontent.com/36344537/36075929-44b53396-0f4d-11e8-983c-956414d058c5.png)
========

## Idea
  
   In the winter of Glasgow, Our team found roads always icy and slippery. Some people slip on roads because of ice and snow. So we decided to construct a system to prevent these accidents.
  
## Target of this project  
  
  This project aims to prevent the formation of ice or snow by using brine as the anti-icing agent. Utilising the humidity and temperature sensor to detect the environmental conditions, the sprinkler spreads the brine water which is controlled by Raspberry Pi. IR sensor is used to detect people and animals. When it detects people, the sprinkler turn off.  

## The diagram of the Anti-Icing System  
![2e80396c-0860-46e9-b20f-047bef2133cd](https://user-images.githubusercontent.com/27271468/36057635-6a6f7434-0e08-11e8-8364-cc74c057d6f9.jpg)  
  
---  

## Contributors:  
Revanth Kailashnath  
Cao Jinyu  
Ding Hao  

## Sensors
IR sensor: HC-SR501 PIR Motion Detector  
<img src="https://user-images.githubusercontent.com/36344537/36178890-4e5ba800-1112-11e8-907d-1f80e61244a6.png" width="200px" height="200px" />


Humidity and temperature sensor: DHT22  
<img src="https://user-images.githubusercontent.com/36344537/37292286-8636f486-2608-11e8-85ff-8439183cb009.jpg" width="200px" height="200px" />  
 
  
  
## Connection and testing sensors  
[Connection and testing sensors](https://github.com/p4nd4m01um/team17/blob/master/Test%20sensors/README.md)  
  
  
## PCB Design
[details of the PCB](https://github.com/p4nd4m01um/team17/blob/master/PCB/README.md)

  
## How to implement code  
1. Clone the repository.
2. Copy the Code/html to /var/www/html
3. In the Code folder, the main file can be executed.
4. If you changed the input/output pin number, you can use CMake to rebuild the main file.
5. Open browser enter the IP of raspberryPi to access the user interface. 

### details are shown in the wiki
