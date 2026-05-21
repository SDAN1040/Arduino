// КОД ДЛЯ ДАТЧИКА DHT11

// Подключение

// VCC → 5V
// GND → GND
//  S  → 2

// GitHub https://github.com/SDAN1040/Arduino

// Библиотеку DHT11 sensor library установить через менеджер библиотек Arduino IDE.
// Название библиотеки: DHT sensor library by Adafruit

#include "DHT.h"

#define DHTPIN 2
#define DHTTYPE DHT11 

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(9600);
  dht.begin();
}

void loop() {
  float h = dht.readHumidity();
  float t = dht.readTemperature();

  Serial.print("Влажность: ");
  Serial.print(h);
  Serial.print("%  Температура: ");
  Serial.print(t);
  Serial.println("°C");

  delay(2000); // задержку не убирать, иначе все сломается
}
