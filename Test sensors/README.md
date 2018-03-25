## Sensors  
### Humidity and Temperature sensor:   
we choose DHT22 with one signal output.  
- Low cost  
- 3 to 5V power and I/O  
- 2.5mA max current use during conversion (while requesting data)  
- Good for 0-100% humidity readings with 2-5% accuracy  
- Good for -40 to 80°C temperature readings ±0.5°C accuracy  
- No more than 0.5 Hz sampling rate (once every 2 seconds)  

- Single-bus data is used for communication between MCU and DHT22, it costs 5mS for single time
communication.  

### PIR sensor:
we choosed HC-SR501.

- Voltage: 5V – 20V  
- Power Consumption: 65mA  
- TTL output: 3.3V, 0V  
- Lock time: 0.2 sec  
- Trigger methods: L – disable repeat trigger, H enable repeat trigger  
- Sensing range: less than 120 degree, within 7 meters  
- Temperature: – 15 ~ +70  
- Dimension: 32*24 mm, distance between screw 28mm, M2, Lens dimension in diameter: 23mm  

## connection:  
### PIR sensor  
connect ground to Header 6  
Vcc to Header 2  
signal to Header 11
LED to Header 13  
  
### Humidity&temperature sensor  
connect ground to Header 6  
Vcc to Header 4  
signal to Header 7 

## Test Code  

- the code for testing DHT22 was named as humidityandtemp.c
- the code for testing Hc-SR501 was named as PIR_sensor.c
