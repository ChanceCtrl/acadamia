#include <Arduino.h>

const int redPin = 11;
const int greenPin = 10;
const int bluePin = 9;
const long COUNTER_VAL = 50000;
long counter = 0;

void setup() {
  Serial.begin(9600);

  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
}

void color(unsigned char red, unsigned char green, unsigned char blue) {
  analogWrite(redPin, red);
  analogWrite(greenPin, green);
  analogWrite(bluePin, blue);
}

void loop() {
  if (Serial.available() > 0) {
    char input = Serial.read();

    Serial.print("Got ");
    Serial.print(input);
    Serial.println("...");

    switch (input) {
    case 'r':
      color(255, 0, 0);
      break;
    case 'g':
      color(0, 255, 0);
      break;
    case 'b':
      color(0, 0, 255);
      break;
    case 'y':
      color(255, 255, 0);
      break;
    case 'c':
      color(0, 200, 255);
      break;
    case 'm':
      color(128, 0, 128);
      break;
    case 'w':
      color(255, 240, 255);
      break;
    case '0':
      color(0, 0, 0);
      break;
    }
  }

  if (counter < COUNTER_VAL)
    counter++;
  else {
    int sensorValue = analogRead(A0);
    Serial.println(sensorValue);

    if (sensorValue < 515 && sensorValue > 510)
      Serial.println("Red light detected");

    counter = 0;
  }
}
