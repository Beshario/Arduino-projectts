
#include <LiquidCrystal.h>

// initialize the library by associating any needed LCD interface pin
// with the arduino pin number it is connected to
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
//trigger and echo pins for ultra sonic sensor
const int trigPin = 12;
const int echoPin = 13;
const int success = 6;
const int fail = 7;

long duration;
long distance;
LiquidCrystal lcd(0, 1, 8, 9, 10, 11);

void setup() {
    pinMode(trigPin,OUTPUT);
    pinMode(echoPin,INPUT);
    pinMode(success,OUTPUT);
    pinMode(fail,OUTPUT);
    
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  // Print a message to the LCD.
  lcd.print("Distance");   
  
}

void loop() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  //Reads the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(echoPin, HIGH);
  //Calculating the distance
  distance= duration*0.0346/2;  
  lcd.setCursor(0, 1);
  lcd.print(distance);
  delay(250);
  float offset= (30-distance)*(30-distance);
  if (offset>2){
    digitalWrite(fail, HIGH);
  } else {
    digitalWrite(fail, LOW);
    }
    

}
