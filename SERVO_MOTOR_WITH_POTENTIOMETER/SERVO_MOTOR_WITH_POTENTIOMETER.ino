// КОД ДЛЯ СЕРВОМОТОРА УПРАВЛЯЕМОГО С ПОТЕНЦИОМЕТРА

// Подключение изображено на фото

// GitHub https://github.com/SDAN1040/Arduino


int servo = 2; 

void setup()
{
  pinMode(servo, OUTPUT);
}
void setServoAngle(int angle) {
  int pulseWidth = map(angle, 0, 180, 500, 2500); 

  digitalWrite(servo, HIGH);
  delayMicroseconds(pulseWidth);
  digitalWrite(servo, LOW);
  
  delayMicroseconds(20000 - pulseWidth); 
}

void loop()
{
    setServoAngle(map(analogRead(A0), 0, 1023, 0, 180));
}

