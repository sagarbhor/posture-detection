/*
  Analog input, analog output, serial output

 Reads an analog input pin, maps the result to a range from 0 to 255
 and uses the result to set the pulsewidth modulation (PWM) of an output pin.
 Also prints the results to the serial monitor.

 The circuit:
 * potentiometer connected to analog pin 0.
   Center pin of the potentiometer goes to the analog pin.
   side pins of the potentiometer go to +5V and ground
 * LED connected from digital pin 9 to ground

 created 29 Dec. 2008
 modified 9 Apr 2012
 by Tom Igoe

 Changes by Sagar for testing with LED

 Comment added by Kiran

 This example code is in the public domain.

 */

// These constants won't change.  They're used to give names
// to the pins used:
const int analogInPin = A0;  // Analog input pin that the potentiometer is attached to
const int ledpin = 7; // Analog output pin that the LED is attached to
const int thA = 487;
const int thB = 440;
int sensorValue = 0;        // value read from the pot
int outputValue = 0;        // value output to the PWM (analog out)
#include<LiquidCrystal.h>
LiquidCrystal lcd(12,11,5,4,3,2);
void setup() {
  pinMode(ledpin, OUTPUT);
  // initialize serial communications at 9600 bps:
  Serial.begin(9600);
}

void loop() {
  // read the analog in value:
  sensorValue = analogRead(analogInPin);
  // map it to the range of the analog out:
  outputValue = map(sensorValue, 540,800, 0, 145);
  if ((thA > sensorValue) && (sensorValue > thB))
  // change the analog out value:
  {
    digitalWrite(ledpin, HIGH);
  }else{
    digitalWrite(ledpin, LOW);
    }

  // print the results to the serial monitor:
  Serial.print("sensor = ");
  Serial.print(sensorValue);
  Serial.print("\t output = ");
  Serial.println(-outputValue);
  lcd.print("degree = "-outputValue);

  // wait 2 milliseconds before the next loop
  // for the analog-to-digital converter to settle
  // after the last reading:
  delay(2);
}
