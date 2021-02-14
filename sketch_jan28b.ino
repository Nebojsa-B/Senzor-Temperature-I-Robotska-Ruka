#include <Braccio.h>
#include <Servo.h>
#include <OneWire.h>
#include <DallasTemperature.h>
#include <LiquidCrystal_I2C.h>
#include <Wire.h>
LiquidCrystal_I2C lcd(0x27,16,2);
#define ONE_WIRE_BUS 7 
Servo base;
Servo shoulder;
Servo elbow;
Servo wrist_rot;
Servo wrist_ver;
Servo gripper;
OneWire oneWire(ONE_WIRE_BUS);

DallasTemperature sensors(&oneWire);

int ledRed = 13;
void setup() {
  
Serial.begin(9600); // Starts the serial communication
  Braccio.begin();
  sensors.begin(); 
  lcd.init(); 
  lcd.backlight(); 
  //LED Dioda
  pinMode(ledRed, OUTPUT);

}
void loop() {
  
  //Pocetna pozicija
                      //(step delay  M1 , M2 , M3 , M4 , M5 , M6);
  Braccio.ServoMovement(20,           0,  45, 180, 180,  90,  10);


sensors.requestTemperatures();
  lcd.setCursor(0, 0);
  lcd.print("TemC: ");
  lcd.print(sensors.getTempCByIndex(0));

  lcd.print(char(223));
  lcd.print("C");
  lcd.setCursor(0, 1);
  lcd.print("...Cekanje 25");
  lcd.print(char(223));
  lcd.print("C");
 
 //LED dioda
  digitalWrite(ledRed, LOW);



if(sensors.getTempCByIndex(0) > 25){
  
  digitalWrite(ledRed, HIGH);
  
  lcd.setCursor(0, 1);
  lcd.print("Robot u akciji!");
  
  
  Braccio.ServoMovement(20,           0,  90, 180, 180,  90,  10);
  
  Braccio.ServoMovement(20,           0,  90, 180, 180,  90,  73);
  
  Braccio.ServoMovement(20,           180,  45, 180, 180,  90,  73);

  Braccio.ServoMovement(20,           180,  90, 180, 180,  90,  73);
  
   Braccio.ServoMovement(20,           180,  90, 180, 180,  90,  10);

  
}





}