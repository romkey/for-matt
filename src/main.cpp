#include <Arduino.h>

#define LED_PIN 13

void setup() {
  delay(1000);
  Serial.begin(115200);
  Serial.println("Hello World");

  pinMode(LED_PIN, OUTPUT);
  digitalWrite(LED_PIN, LOW);
}

void loop() {
  Serial.println("on");
  digitalWrite(LED_PIN, HIGH);
  delay(1000);

  Serial.println("off");
  digitalWrite(LED_PIN, LOW);
  delay(1000);
}
