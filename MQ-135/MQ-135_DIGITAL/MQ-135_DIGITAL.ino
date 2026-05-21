// КОД ДЛЯ ЦИФРОВОГО ПОДКЛЮЧЕНИЯ ДАТЧИКА MQ-135

// Подключение

// VCC → 5V
// GND → GND
// A0  → НЕ ПОДКЛЮЧАЕТСЯ
// D0  → D2

// GitHub https://github.com/SDAN1040/Arduino

// Код

int mq135_pin = 2;
void setup() {
  Serial.begin(9600);
  pinMode(mq135_pin, INPUT);
  
  Serial.println("Прогрев датчика MQ-135...");
  delay(60000);
}

void loop() {
  int gasDetected = digitalRead(mq135_pin); // Порог срабатывания датчика, при котором полученное значение будет 1 настраивается потенциометром на самом датчике

  if (gasDetected == LOW) {  
  // в блоке if else можно добавить дополнительные действия если газ есть/нету
    Serial.println("Обнаружен газ/дым!");
  } else {
    Serial.println("Воздух в норме.");
  }

  delay(1000);
}

