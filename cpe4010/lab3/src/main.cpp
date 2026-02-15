#include <Arduino.h>

int buzzer = 8; // select digital IO pin for the buzzer

void setup() {
  pinMode(buzzer, OUTPUT); // set digital IO pin pattern, OUTPUT to be output
  Serial.begin(9600);
}

void loop() {
  while (1) {
    // Get user input
    float delay_freq = map(analogRead(A0), 0, 690, 60, 10000);
    Serial.print("Frequency is ");
    Serial.println(delay_freq);

    tone(buzzer, delay_freq);
  }
}
