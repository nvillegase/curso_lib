#define trig 39
#define echo 38

void setup() {
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
  Serial.begin(9600);
  digitalWrite(trig, LOW);
}

void loop() {
  
  float tiempo;
  float distancia;
  
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);
  
  tiempo = contar_us() / 2.0;
  if (tiempo > 0) {
    distancia = tiempo * 0.034;
  }
  else {
    distancia = -1;
  }
  
  Serial.println(distancia);
  delay(60);
  
}


float contar_us(void) {
  
  while(!digitalRead(echo)) {}
  uint64_t start_us = micros();
  
  while(digitalRead(echo)) {
    if (micros() - start_us > 20e3) {
      return -1;
    }
  }
  
  uint64_t end_us = micros();
  return end_us - start_us;
  
}
  
  
