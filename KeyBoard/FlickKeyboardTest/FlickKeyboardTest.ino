#define  SW 3
#define VRX 1
#define VRY 3
#define offsetX 497
#define offsetY 519
#define Border 50
int sw0, sw1;
void setup() {
  pinMode(SW, INPUT_PULLUP);
  Serial.begin(115200);
}

void loop() {
  sw0 = sw1;
  sw1 = getFlick(SW, 0);
  if(sw1 == 1 && sw0 == 0){
    Serial.print(getChar());
  }
  delay(50);
}

char getChar(){
  
}

int getFlick(byte pin, byte type){
  int data;
  if(type == 0){         //押し込みスイッチ
    data = digitalRead(pin);
    if(data == 0){
      data = 1;
    }else{
      data = 0;
    }
  }else if(type == 1){   //X軸の調整
    data = analogRead(pin);
    data = data - offsetX;
  }else if(type == 2){   //Y軸の調整
    data = analogRead(pin);
    data = -1 * (data - offsetY);
  }
  return data;
}
