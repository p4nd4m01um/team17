# PCB description  
   
    
## Schematic and PCB   
We selected Orcad capture and PCB editor to draw the PCB. 
#### sensors circuit:   
The original file of the [schematic](https://github.com/p4nd4m01um/team17/blob/master/PCB/Sensor%20circuit.zip).  Please open this file by Orcad Capture.  
The original file of the [PCB](https://github.com/p4nd4m01um/team17/blob/master/PCB/Circuit%20for%20sensors.brd). Please open this file by PCB Editor.   
#### motor control circuit:  
The original file of the [schematic](https://github.com/p4nd4m01um/team17/blob/master/PCB/Motor%20control%20circuit.zip).  Please open this file by Orcad Capture.  
The original file of the [PCB](https://github.com/p4nd4m01um/team17/blob/master/PCB/Motot%20control.brd). Please open this file by PCB Editor. 

### Here is the schematic of sensors circuit. 16 pins are enough for our project, so we only used a header with 16 Pins.   
J2 is for PIR sensor  
J3 is for humidity&temperature sensor   
J4 is for GPIO  
R1 and R2 are the pull-up resistors   
D1 LED is for the motor test. This signal is used to control motor.  
D2 LED is for observation. It will show if the circuit is working.    
![sensor circuit](https://user-images.githubusercontent.com/36344537/38472461-7448a17c-3b78-11e8-851d-66f798775ef5.PNG)    
  
### The PCB layout is shown in the next figure.  
![sensor pcb layout](https://user-images.githubusercontent.com/36344537/38472462-745e8ad2-3b78-11e8-8bfe-a8e9627cfb0d.PNG)     
    
### Here is the pdf file for fabrication. This one is the top layer.  
![sensor pcb top](https://user-images.githubusercontent.com/36344537/38472463-7473922e-3b78-11e8-8959-69dac39f5cdf.PNG)      
  
### Here is the bottom layer.  
![sensor pcb](https://user-images.githubusercontent.com/36344537/38472464-748677f4-3b78-11e8-9f26-37ec2a2fd449.PNG)   
  
---    
### Schematic and PCB for motor drive  
  
### Here is the Schematic of Motor driver circuit. 
J1 is for Power source.  
J2 is for Motor.  
J3 is for Control signal that comes from the GPIO.  
J4 is for switch.  
Q1 is to control the motor.  
D2 LED is to check if the circuit works properly.  
![motor circuit](https://user-images.githubusercontent.com/36344537/38472465-749a0a44-3b78-11e8-8c09-b766f2a3f90a.PNG)  

### The PCB layout is shown in the next figure.  
![motor pcb layout](https://user-images.githubusercontent.com/36344537/38472459-7418ab3e-3b78-11e8-97a2-b0927f66296b.PNG)  
  

### Here is the pdf file for fabrication. This one is the top layer.  
![motor pcb top](https://user-images.githubusercontent.com/36344537/38472460-74348f02-3b78-11e8-9701-f4ff382bdd15.PNG)  
  
### This one is the bottom layer.  
![motor pcb bottom](https://user-images.githubusercontent.com/36344537/38472466-74adcb7e-3b78-11e8-8929-ffdb804320a3.PNG)  
  
      
  #### PCB Artwork  
   PCB Artwork in the circuit designing process refers to the planning and placing of electrical traces and via holes to connect every component mounted on the board with each other.  
   PCB Artwork rules/guidelines is used as a base for the circuit design to facilitate a standard design and manufacturing procedures.
   this file named as ``` art_parm.txt ``` .
    
  #### PCB NC  
   Named as ``` nc_param.txt ```.  
     
  #### IPC2581  
  IPC-2581 is a generic standard for printed circuit board and assembly manufacturing description data and transfer methodology.  
  This file named as ``` ipc2581.txt```.
  
