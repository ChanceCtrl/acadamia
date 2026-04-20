#include <Arduino.h>

#include <MPU6050.h>
#include <Wire.h>

#include <Metro.h>
Metro sec_1(1000);

MPU6050 mpu;

void checkSettings() {
  Serial.println();

  Serial.print(" * Sleep Mode:            ");
  Serial.println(mpu.getSleepEnabled() ? "Enabled" : "Disabled");

  Serial.print(" * Clock Source:          ");
  switch (mpu.getClockSource()) {
  case MPU6050_CLOCK_KEEP_RESET:
    Serial.println("Stops the clock and keeps the timing generator in reset");
    break;
  case MPU6050_CLOCK_EXTERNAL_19MHZ:
    Serial.println("PLL with external 19.2MHz reference");
    break;
  case MPU6050_CLOCK_EXTERNAL_32KHZ:
    Serial.println("PLL with external 32.768kHz reference");
    break;
  case MPU6050_CLOCK_PLL_ZGYRO:
    Serial.println("PLL with Z axis gyroscope reference");
    break;
  case MPU6050_CLOCK_PLL_YGYRO:
    Serial.println("PLL with Y axis gyroscope reference");
    break;
  case MPU6050_CLOCK_PLL_XGYRO:
    Serial.println("PLL with X axis gyroscope reference");
    break;
  case MPU6050_CLOCK_INTERNAL_8MHZ:
    Serial.println("Internal 8MHz oscillator");
    break;
  }

  Serial.print(" * Accelerometer:         ");
  switch (mpu.getRange()) {
  case MPU6050_RANGE_16G:
    Serial.println("+/- 16 g");
    break;
  case MPU6050_RANGE_8G:
    Serial.println("+/- 8 g");
    break;
  case MPU6050_RANGE_4G:
    Serial.println("+/- 4 g");
    break;
  case MPU6050_RANGE_2G:
    Serial.println("+/- 2 g");
    break;
  }

  Serial.print(" * Accelerometer offsets: ");
  Serial.print(mpu.getAccelOffsetX());
  Serial.print(" / ");
  Serial.print(mpu.getAccelOffsetY());
  Serial.print(" / ");
  Serial.println(mpu.getAccelOffsetZ());

  Serial.println();
}

// uint8_t pins[] = {52, 50, 48, 46, 44, 42, 40};
//
//   for (int i = 0; i < sizeof(pins); i++) {
//     pinMode(pins[i], OUTPUT);
//     digitalWrite(pins[i], LOW);
//   }

void setup() {
  Serial.begin(115200);

  Serial.println("Initialize MPU6050");

  pinMode(8, OUTPUT);
  analogWrite(8, 100);

  // while (!mpu.begin(MPU6050_SCALE_2000DPS, MPU6050_RANGE_2G)) {
  //   Serial.println("Could not find a valid MPU6050 sensor, check wiring!");
  //   delay(500);
  // }

  // checkSettings();
}

void loop() {
  // Vector normAccel = mpu.readNormalizeAccel();
  //
  // float Ax = normAccel.ZAxis;
  // float Ay = normAccel.YAxis;
  // float Az = normAccel.XAxis;
  //
  // float pitch = atan2(-Ax, sqrt(Ay * Ay + Az * Az)) * (180.0 / PI);
  // float roll = atan2(Ay, Az) * (180.0 / PI);
  //
  // if (sec_1.check()) {
  //   Serial.print("Pitch: ");
  //   Serial.print(pitch);
  //   Serial.print("\tRoll: ");
  //   Serial.println(roll);
  // }
}

// void loop() {
//   Vector normAccel = mpu.readNormalizeAccel();
//
//   if (normAccel.YAxis > 19) {
//     Serial.println("+Y Max Reached");
//     digitalWrite(pins[0], HIGH);
//   } else if (normAccel.YAxis > 13) {
//     Serial.println("+Y Mid Reached");
//     digitalWrite(pins[1], HIGH);
//   } else if (normAccel.YAxis > 6) {
//     Serial.println("+Y Min Reached");
//     digitalWrite(pins[2], HIGH);
//   } else if (normAccel.YAxis < 1.5 && normAccel.YAxis > -1.5)
//     analogWrite(pins[3], 10);
//   else if (normAccel.YAxis < -19) {
//     Serial.println("-Y Min Reached");
//     digitalWrite(pins[6], HIGH);
//   } else if (normAccel.YAxis < -13) {
//     Serial.println("-Y Min Reached");
//     digitalWrite(pins[5], HIGH);
//   } else if (normAccel.YAxis < -6) {
//     Serial.println("-Y Min Reached");
//     digitalWrite(pins[4], HIGH);
//   }
//
//   delay(50);
//
//   for (int i = 0; i < sizeof(pins); i++)
//     digitalWrite(pins[i], LOW);
// }
