// КОД ДЛЯ ВЕНТИЛЯТОРА 140C04 С СЕРВОМОТОРОМ

// Подключение

// СЕРВОМОТОР
// VCC → 5V
// GND → GND
// SIGNAL → D2

// 140C04 (вентилятор)
// VCC → 5V
// GND → GND
// INA → 5
// INB → 9

// ПЕРЕМЕННЫЕ РЕЗИСТОРЫ
// VCC → 5V
// GND → GND
// SIGNAL → A0/A1

// GitHub https://github.com/SDAN1040/Arduino

int inA = 5;
int inB = 9;

int servo = 2; 

void setup()
{
  pinMode(servo, OUTPUT);

  pinMode(inA, OUTPUT);
  pinMode(inB, OUTPUT);

  digitalWrite(inB, HIGH); 
  digitalWrite(inA, LOW);  


  Serial.begin(9600);
}

void setServoAngle(int angle) {
  int pulseWidth = map(angle, 0, 180, 500, 2500); 

  digitalWrite(servo, HIGH);
  delayMicroseconds(pulseWidth);
  digitalWrite(servo, LOW);
  
  delayMicroseconds(20000 - pulseWidth); 
}


void loop() {


    
    analogWrite(inA, map(analogRead(A0), 0,1023,0,255));

    int dt = map(analogRead(A1), 0,1023,4,40);
    if (dt <39){
      HandleRotate();
      
    }
    delay(dt);
}

int orientation = 90;
bool rotate_side = true;
void HandleRotate(){
  setServoAngle(orientation);
  if (rotate_side){
    orientation += 1;
  }else{
    orientation -= 1;
  }
  if(orientation == 180){
    rotate_side = false;

  }else if(orientation == 0){
    rotate_side = true;
  }
}

