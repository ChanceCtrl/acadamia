#include <Arduino.h>
#include <Metro.h>
#include <Servo.h>

Servo myservo; // create servo object to control a servo
Metro sec_1(1000);

void setup() {
  Serial.begin(9600);

  myservo.attach(9); // attachs the servo on pin 9 to servo object
  myservo.write(0);  // back to 0 degrees

  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN, LOW);
}

void loop() {
  uint8_t fella = Serial.read();

  switch (fella) {
  case 'a':
    Serial.println("\nSetting angle to 0...");
    myservo.write(0);
    break;
  case 'b':
    Serial.println("\nSetting angle to 90...");
    myservo.write(90);
    break;
  case 'c':
    Serial.println("\nSetting angle to 180...");
    myservo.write(180);
    break;
  }
}

// void loop() {
//   int angle = map(analogRead(A0), 20, 680, 0, 180);
//   myservo.write(angle);
//
//   if (angle < 100 && angle > 80)
//     digitalWrite(LED_BUILTIN, HIGH);
//   else
//     digitalWrite(LED_BUILTIN, LOW);
//
//   if (sec_1.check()) {
//     Serial.print("Da raw: ");
//     Serial.print(analogRead(A0));
//     Serial.print("\tDa angle: ");
//     Serial.println(angle);
//   }
// }
