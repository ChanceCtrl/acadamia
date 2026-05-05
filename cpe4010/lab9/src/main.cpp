#include <Arduino.h>

const int echoPin = 4;
const int trigPin = 5;

uint16_t pwm_freq = 0;

float readSensorData() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  float distance =
      pulseIn(echoPin, HIGH) / 58.00; // Equivalent to (340m/s*1us)/2
  return distance;
}

void setup() {
  Serial.begin(9600);
  pinMode(echoPin, INPUT);
  pinMode(trigPin, OUTPUT);

  pinMode(49, OUTPUT); // R
  pinMode(48, OUTPUT); // Y
  pinMode(11, OUTPUT); // G
  // pinMode(2, OUTPUT);  // Buzzer
}

void loop() {
  float distance = readSensorData();

  Serial.println(distance);

  delay(100);
}

// void loop() {
//   float distance = readSensorData();
//
//   Serial.print("Distance: ");
//   Serial.println(distance);
//
//   digitalWrite(49, LOW);
//   digitalWrite(48, LOW);
//   digitalWrite(11, LOW);
//
//   if (distance > 12) {
//     digitalWrite(11, HIGH);
//     noTone(2);
//     delay(400);
//   } else if (distance > 6) {
//     digitalWrite(48, HIGH);
//     tone(2, 2000);
//     delay(400);
//     noTone(2);
//     delay(400);
//   } else if (distance >= 3) {
//     digitalWrite(49, HIGH);
//     tone(2, 2000);
//     delay(200);
//     noTone(2);
//     delay(200);
//   } else {
//     digitalWrite(49, HIGH);
//     Serial.println("WARNING: Object extremely close!");
//     tone(2, 2000);
//     delay(80);
//     noTone(2);
//     delay(80);
//   }
// }
// void loop() {
//   float distance = readSensorData();
//
//   if (distance > 12) {
//     pwm_freq = 0;
//   } else if (distance < 2) {
//     pwm_freq = 0;
//   } else {
//     pwm_freq = map(distance, 2, 12, 2500, 500);
//   }
//
//   Serial.print("Distance: ");
//   Serial.print(distance);
//   Serial.print("\tFreq: ");
//   Serial.println(pwm_freq);
//
//   tone(2, pwm_freq);
//   delay(100);
// }

// void loop() {
//   float distance = readSensorData();
//
//   if (distance > 12) {
//     Serial.println("Distance greater than 12cm");
//     digitalWrite(11, HIGH);
//   } else if (distance <= 12 && distance > 5) {
//     Serial.println("Distance between 12cm & 5cm");
//     digitalWrite(48, HIGH);
//   } else if (distance < 5) {
//     Serial.println("Distance less than 5cm");
//     digitalWrite(49, HIGH);
//   }
//
//   delay(400);
//   digitalWrite(49, LOW);
//   digitalWrite(48, LOW);
//   digitalWrite(11, LOW);
// }
