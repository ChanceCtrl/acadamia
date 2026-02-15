#include <Arduino.h>

int ledpin = 2; // initialize pin 11
int greenPin = 3;
int inpin = 4; // initialize pin 7
int val;       // define val

void setup() {
  pinMode(ledpin, OUTPUT);   // set LED pin as “output”
  pinMode(greenPin, OUTPUT); // set LED pin as “output”
  pinMode(inpin, INPUT);     // set button pin as “input”
  digitalWrite(inpin, HIGH);
}

void loop() {
  val =
      digitalRead(inpin); // read the level value of pin 7 and assign if to val
  if (val == LOW) // check if the button is pressed, if yes, turn on the LED
  {
    digitalWrite(ledpin, HIGH);
    digitalWrite(greenPin, LOW);
  } else {
    digitalWrite(ledpin, LOW);
    digitalWrite(greenPin, HIGH);
  }
}
