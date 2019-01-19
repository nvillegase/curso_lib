#include <lib_ultrasonido.h>
#define trig 39
#define echo 38

HCSR04 sensor(trig, echo);

void setup() {
  Serial.begin(9600);
}

void loop() {
  Serial.println(sensor.get_cm());
}

