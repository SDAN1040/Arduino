// Подключение

// VCC → 5V
// GND → GND
// SDA → A4
// SCL → A5

// GitHub 

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
