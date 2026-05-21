// КОД ДЛЯ АНАЛОГОВОГО ПОДКЛЮЧЕНИЯ ДАТЧИКА MQ-135

// Подключение

// VCC → 5V
// GND → GND
// A0  → A0
// D0  → НЕ ПОДКЛЮЧАЕТСЯ

// GitHub https://github.com/SDAN1040/Arduino

// Код

int mq135_pin = A0;
void setup() {
  Serial.begin(9600);
  Serial.println("Прогрев датчика MQ-135...");
  delay(60000); 
}

void loop() {  
  int sensorValue = analogRead(mq135_pin);
  Serial.print("Аналоговое значение газа: ");
  Serial.println(sensorValue);

  // сюда можно добавлять любые проверки и действия в зависимости от значения газа

  delay(1000);
}
