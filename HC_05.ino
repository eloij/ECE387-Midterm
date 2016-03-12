#include <SoftwareSerial.h>
SoftwareSerial BTserial(0 , 1); // RX | TX
// Connect the HC-05 TX to Arduino pin 0 RX. 
// Connect the HC-05 RX to Arduino pin 1 TX

int sensorPin = A0;    // select the input pin for the potentiometer
int sensorValue = 0;  // variable to store the value coming from the sensor
 
char c = ' ';
 
void setup() 
{
    Serial.begin(9600);
    Serial.println("Arduino is ready");
 
    // HC-05 default serial speed for AT mode is 38400
    BTserial.begin(38400);  
}
 
void loop()
{
    sensorValue = analogRead(sensorPin);
    // Keep reading from HC-05 and send to Arduino Serial Monitor
    if (BTserial.available())
    {
        Serial.write(BTserial.read());
    }
      
    // Keep reading from Arduino Serial Monitor and send to HC-05 (Communication Arduino-Bluetooth Module)
    if (Serial.available())
    {
        Serial.write(sensorValue); 
        BTserial.write(sensorValue);  //Send the message 
    }
}

