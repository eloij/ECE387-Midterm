#include <SoftwareSerial.h>
SoftwareSerial BTSerial(0, 1); // RX | TX

#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

int sensorPin = A0;
int sensorValue = 0;
LiquidCrystal_I2C lcd(0x27,20,4);
 
void setup() 
{
    Serial.begin(9600);
    Serial.println("Arduino with HC-06 is ready");
 
    // HC-06 default baud rate is 9600
    BTSerial.begin(9600);  
    Serial.println("BTserial started at 9600");

    lcd.init();                      // initialize the lcd 
    lcd.init();
    lcd.begin(20,4);
    lcd.backlight();
    lcd.setCursor(0,0);
    lcd.println("Midterm Juliano");
}
 
void loop()
{
  // Keep reading from HC-06 and send to Arduino Serial Monitor
  if (BTSerial.available())
    sensorValue = BTSerial.read();
    Serial.write(sensorValue);
 
  // Keep reading from Arduino Serial Monitor and send to HC-06
  if (Serial.available())
    BTSerial.write(Serial.read());


  //Print on LCD
  if(sensorValue < 100){
    lcd.setCursor(2,2);
    lcd.print(0);
    lcd.setCursor(3,2);
    lcd.print(0);
    lcd.setCursor(4,2);
    lcd.print(sensorValue);
  }
  else if(sensorValue < 1000){
    lcd.setCursor(2,2);
    lcd.print(0);
    lcd.setCursor(3,2);
    lcd.print(sensorValue);
  }
  else{
    lcd.setCursor(2,2);
    lcd.print(sensorValue);
  }
}
