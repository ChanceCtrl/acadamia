#include <Arduino.h>

uint8_t my_array[10] = {0, 2, 4, 2, 6, 5, 0, 8, 10, 11};

int get_max(uint8_t *array, uint8_t size) {
  int max;
  for (int x = 0; x < size; x++) {
    if (array[x] > max) {
      max = array[x];
    }
  }

  return max;
}

void setup() { Serial.begin(9600); }

void loop() {
  int result = get_max(my_array, sizeof(my_array));

  Serial.println(result);

  delay(1000);
}
