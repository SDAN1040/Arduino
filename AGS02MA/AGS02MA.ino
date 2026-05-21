// КОД ДЛЯ ДАТЧИКА AGS02MA С ШИНОЙ I2C

// Подключение

// VCC → 5V
// GND → GND
// SDA → A4
// SCL → A5

// GitHub https://github.com/SDAN1040/Arduino

// Библиотеку AGS02MA установить тут SourceCode.zip: https://github.com/RobTillaart/AGS02MA/releases/tag/0.4.4
// Библиотеку подключить как .ZIP Library

#include <Wire.h>
#include <AGS02MA.h>

AGS02MA ags(0x1A);

void setup() {
  Serial.begin(115200);
  Serial.println("AGS02MA TVOC Sensor Test");

  Wire.begin();
  Wire.setClock(25000); // 25 кГц

  if (!ags.begin()) {
    Serial.println("Датчик не найден. Проверьте подключение!");
    while (1);
  }
  
  Serial.println("Датчик подключен. Идет разогрев...");
}

void loop() {
  if (!ags.isHeated()) {
    Serial.print("Идет прогрев... ");
    Serial.print((millis() - 0) / 1000); 
    Serial.println(" сек.");
  }

  uint32_t tvoc = ags.readPPB();
  
  Serial.print("TVOC: ");
  Serial.print(tvoc);
  Serial.println(" ppb (parts per billion)");

  delay(2000);
}
