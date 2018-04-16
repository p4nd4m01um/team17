1.    Assessment of responsiveness of the application in the context of the task.
 
Since the environmental changes aren’t very drastic, slow response is perfectly acceptable. Our system does not have any major latency (0.022 seconds approx.) impeding the purpose of the tasks it has to perform. Thus, proving to be quite an effective solution.
 
2.    Overall latency between the physical event and output

Approximately 3 to 4 second delay between the web server and physical event is found to exist. Since the speed of the response doesn’t take a high precedence in the application of our system, we can easily work with the existing latency in the system. It must also be noted that the responsive action is instantaneous, whereas the display of information on the web server has latency. 
The sensors have a pre-processing latency of about 0.022 seconds to 5ms. Thus, it does not affect the performance of the system.

3.    What is the sampling rate?
 
We use 2 sensors. Namely,

*PIR sensor: which has a sampling rate of 1 second    
*Temperature & Humidity sensor: sampling rate of 3 seconds
*The sampling of the data from the C++ program to the mySQL database occurs every 3 seconds
*The PHP web server reads data from the database every second

 
4.    Bus protocols:
 
  The sensors come with a support for various bus protocols. But, we prefer to use UART (Universal Asynchronous Receiver-Transmitter) as we have only 1 Data bus and, due to the simplicity in programming it. The 40-bit data response signal from Temperature sensor is given in the wiki.
Single-bus data is used for communication between RPI and DHT22, it costs 5ms for single time communication. This is pre processing latency.
 
5.    How many channels?
      1.     Motor
      2.    PIR sensor
      3.    Temperature and Humidity sensor
 
6.    Low level implementation:
Userspace is used. Because:
·          To implement GUI (Web-Server).
·          Coding is easier.
·          Fast response of the system is not an issue.
 
7.    Data flow is provided in the detailed control flow graph section in the wiki.

8.     How many samples? 

9.    Buffering: 

  No buffer is used, as we do not have a large amount of data that needs to undergo post-processing procedures. However, since data from the temperature and humidity sensor is a string of 40 bits, it will only output temperature and humidity value after serially processing the entire string of 40 bits of data.latency due to buffer. Add a timer and time the latency
* Latency due to buffering:
Almost no latency is resulted from the sensor buffer. Add a timer and time the latency
 
10. Post Processing of data: no latency as we are using BLDC motor pump only, the response is instantaneous.
 
12. How many threads are used: 
  	4 threads have been used.
  1.  Main works on one thread.
	2.  Both the sensors work on their own independent threads.
	3.  The web server runs on its own thread.
 


13.  GUI:
 
The web-server is written in PHP using jQuery Ajax which is short for asynchronous JavaScript and XML. It reads data from the database every second (which doubles up as the refresh rate of the website).  
 
14. Structure of the software:

The software structure has a low coupling design. We are using MySQL database as a medium for data storing and reading. One class called MyDB which manipulates MySql database by using SQL syntax. Another class called Sensor which involves relevant variables and reading functionalities for Temperature and Humidity sensor and PIR sensor. The main function calls the sensor functions for retrieving data and then stores the data into the database. The web server read the data from Mysql database. The task of controlling the motor pump is accomplished through PHP(web server).


15. Roles in the team:
 
Revanth Kailashnath:
  ·         Github maintenance and update
  ·         Procuring Hardware and sensor selection
  ·         Motor control circuit, PCB design and its implementation
  ·         Mathematical equation for finding RHthreshold
  ·        release strategy on hackaday, hackster, instructables, reddit/r/diy

 
Jinyu Cao:
	·         Github Readme.md .
	·         Procuring Hardware and sensor selection.
	·         sub function for sensors.
	·         PCBs design for sensors and motor.
	·         PCBs fabrication, soldering and test.
  ·         Unit test 
  ·         Videography
Hao “Ken” Ding:

16. Time allocation:.
 
Software: 2 months
Hardware: 1 month
Mechanical setup:10 days
 
17. Version Control Software: Git as it is free.
 
18. Release strategy:	       	
  1. Hackster
  2. Instructables
  3. reddit/r/diy
  4. Submitted the project to hackaday (waiting for them to revert back)
  5. create YouTube videos

 
Release strategy success: TBD
 
19. Measurement of success: TBD

we will will update the success story by the end of the course duration.
 
 
 
 

