# Criteria

**_1. Assessment of responsiveness of the application in the context of the task._**
 
Since the environmental changes aren’t very drastic, slow response is perfectly acceptable. Our system does not have any major latency (0.022 seconds to 5 ms approx.) impeding the purpose of the tasks it has to perform. Thus, proving to be quite an effective solution.
 
_**2. Overall latency between the physical event and output**_

Approximately 3 to 4 second delay between the web server and physical event is found to exist. Since the speed of the response doesn’t take a high precedence in the application of our system, we can easily work with the existing latency in the system. It must also be noted that the responsive action is instantaneous, whereas the display of information on the web server has latency. 

The sensors have a processing latency of about 0.022 seconds to 5ms. Thus, it does not affect the performance of the system.

_**3. What is the sampling rate?**_
 
We use 2 sensors. 

* PIR sensor: which has a sampling rate of 1 second    
* Temperature & Humidity sensor: sampling rate of 3 seconds

The sampling of the data from the C++ program to the mySQL database occurs every 3 seconds

The PHP web server reads data from the database every second

_**4. Bus protocols:**_
 
The sensors come with a support for various bus protocols. But, we prefer to use UART (Universal Asynchronous Receiver-Transmitter) as we can use 1 Data bus to achieve our requirements and also, due to the simplicity in programming it. The 40-bit data response signal from Temperature sensor is given in the wiki.

Single-bus data is used for communication between RPI and DHT22, it costs 5ms for single time communication. This is a latency caused due to data processing.
 
_**5. How many channels?**_

A total number of 3 channels were ussed for the project. Namely:
* Motor
* PIR sensor
* Temperature and Humidity sensor
 
_**6. Low level implementation:**_

Userspace is used. Because:

* To implement GUI (Web-Server).
* Coding is easier.
* Fast response of the system is not an issue.
 
_**7. Data flow is provided in the detailed control flow graph section in the wiki.**_

[Detailed Control Flow Graph of the System](https://github.com/p4nd4m01um/team17/wiki/Detailed-Control-Flow-Graph-of-the-System)

_**8. Buffering of Data: How many samples?**_

We do not use a buffer as it is not necessary for a project of this scale. However, we use a database to store the obtained data from the sensors before the website reads it. The website reads the stored data every 3 seconds from the MySQL database.

_**9. Buffering:**_

No buffer is used, as we do not have a large amount of data that needs to undergo post-processing procedures and data trend analysis. However, since data from the temperature and humidity sensor is a string of 40 bits, it will only output temperature and humidity value after serially processing the entire string of 40 bits of data. Thus, we have added a timer and timed the latency resulting from it.

Latency due to buffering:
* No latency is resulted from the sensor buffer. 
* When a timer is added and the latency is timed, a latency of 0.022 seconds to 5 ms  was resulted from the temperature and humidity sensor.
 
_**10. Post Processing of data:**_

No latency due to post-processing is resulted as we are using only BLDC motor pump as an output, whose response is instantaneous. thus N/A.
 
_**11. How many threads are used:**_

4 threads have been used.
* Main works on one thread.
* Both the sensors work on their own independent threads.
* The web server runs on its own thread.

_**12. GUI:**_
 
The web-server is written in PHP using jQuery and Ajax which is short for asynchronous JavaScript and XML. It reads data from the database every second (which doubles up as the refresh rate of the website).  
 
_**13. Structure of the software:**_

The software structure has a low coupling design. We are using MySQL database as a medium for data storing and reading. One class called MyDB which manipulates MySql database by using SQL syntax. Another class called Sensor which involves relevant variables and reading functionalities for Temperature and Humidity sensor and PIR sensor. The main function calls the sensor functions for retrieving data and then stores the data into the database. The web server read the data from Mysql database. The task of controlling the motor pump is accomplished through PHP(web server).

_**14. Roles in the team:**_
 
_Revanth Kailashnath:_
* Github maintenance and updates including licenses, readme, wiki and code
* Technical content writing including criteria of assessment
* Procuring Hardware and sensor selection
* Motor control circuit, PCB designs and soldering
* Hardware implementation
* Mathematical equation for finding RHthreshold
* Package Version numbering and release
* Release strategy formulation
* Publications in various electronic blogs and websites including hackaday, hackster, instructables, reddit/r/diy

 
_Jinyu Cao:_
* Github Readme.md
* Procuring Hardware and sensor selection
* sub function for sensors
* PCB designs for sensors and motor
* PCB fabrication, soldering and test
* Unit test 
* Videography

_Hao Ding:_
* Code of Temperature & Humidity sensor
* Code of IR sensor
* Code of Snow calculation
* Code of MySql connection
* Building MySql database
* Building Web server
* Php code for data connection
* User interface design
* Applying domain name for public accessibility
* WIKI layout
* Video editing

_**15. Time allocation:**_
 
* Software: 2 months
* Hardware: 1 month
* Mechanical setup:10 days
 
_**16. Version Control Software and numbering of releases/ milestones:**_

Git as it is free. GitHub has a wide popularity in the technogeek community. It is easy to log, maintain and very efficient to use.
A project with only one branch(master) was used with accomodating and sensible distribution of various tasks among the team members. V 1.0 was released on the 16th of April, 2018 to mark the milestone of initial release of the product. later versions will be released based on the performance and iff tweaking is necessary.

_**17. Release strategy:**_

Publication in various social media and mainstream electronic websites, including:

* Hackster:  https://www.hackster.io/vant4u/anti-icing-system-440a41
* Instructables:  https://www.instructables.com/id/Anti-Icing-System/
* reddit/r/diy:  https://www.reddit.com/r/raspberry_pi/comments/8coow3/antiicing_system_using_raspberry_pi/?st=jg2fs7wc&sh=95f0193a
* Submitted the project to hackaday (waiting for them to revert back)
* create YouTube videos: 	https://www.youtube.com/watch?v=QaHXD64GoVk  
  				https://www.youtube.com/watch?v=q8ZnzTlgLoI

 
_**18. Measurement of success:**_

We will consider the project to be a success if it can prevent the formation of ice (precipitation) on pavements. Seeing as its accomplished this mission, the contraption can be declared to be a success. 
We will update you the success story by the end of the course duration.
 
