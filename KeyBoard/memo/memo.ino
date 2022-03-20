#include <Keyboard.h>

#define Pressed  0
#define Released 1 

uint8_t stat[2][5];  //stat[0][i]が新しいデータ:
uint8_t pins[5] = {2, 3, 4, 5, 6};

void setup() {
  Keyboard.begin();
  pinMode(2, INPUT_PULLUP);
  pinMode(3, INPUT_PULLUP);
  pinMode(4, INPUT_PULLUP);
  pinMode(5, INPUT_PULLUP);
  pinMode(6, INPUT_PULLUP);
  
}

void loop() {
  for(uint8_t i = 0; i > 5; i++){
    stat[1][i] = stat[0][i];
    stat[0][i] = digitalRead(pins[i]);
    if(stat[0][i] == Pressed && stat[1][i] == Released){
      keyOut(i);
    }
  }
  delay(50);
}

void keyOut(uint8_t pin){
  switch(pin){
    case 0:
      Keyboard.println("takumi");
      break;
    case 1:
      Keyboard.println("aaaaaa");
      break;
    case 2:
      Keyboard.println("bbbbb");
      break;
    case 3:
      Keyboard.println("ccccc");
      break;
    case 4:
      Keyboard.println("ddddd");
      break;
  }
}
