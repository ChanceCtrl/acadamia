#include <Arduino.h>
#include <DHT.h>

#define DHTPIN 4      // Set the pin connected to the DHT11 data pin
#define DHTTYPE DHT11 // DHT 11

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(9600);
  Serial.println("DHT11 test!");
  dht.begin();
}

void loop() {
  // Wait a few seconds between measurements.
  delay(1000);

  // Reading temperature or humidity takes about 250 milliseconds!
  // Sensor readings may also be up to 2 seconds 'old' (it's a very slow sensor)
  float humidity = dht.readHumidity();

  // Read temperature as Celsius (the default)
  float temperature = dht.readTemperature();

  // Check if any reads failed and exit early (to try again).
  if (isnan(humidity) || isnan(temperature)) {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }

  // Print the humidity and temperature
  Serial.print("Time: ");
  Serial.print(int(millis() / 1000));
  Serial.print("\tTemperature: ");
  Serial.print(temperature);
  Serial.print(" *C, ");
  Serial.print((temperature * 9 / 5) + 32);
  Serial.print(" *F, ");
  Serial.print(temperature + 273.15);
  Serial.println(" *K");
}
