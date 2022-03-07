#include <MsTimer2.h>

#define flickStatus_pins      24
#define flickStatus_pastDatas 10
#define    swStatus_pins      20
#define    swStatus_pastDatas  2
#define flickChange_pins      24

uint8_t flickStatus[flickStatus_pins][flickStatus_pastDatas];
uint8_t swStatus[swStatus_pins][swStatus_pastDatas];
uint8_t flickChange[flickChange_pins][1][1];                   //pins, directions, MaximumData:

void setup(){
  for(uint8_t i = 0; i < flickStatus_pins; i++){
    for(uint8_t o = 0; o < flickStatus_pastDatas; o++){
      flickStatus[i][o] = 0;
    }
  }
  for(uint8_t i = 0; i < sw_pins; i++){
    for(uint8_t o = 0; o < sw_pastDatas; o++){
      swStatus[i][o] = 0;
    }
  }
  for(uint8_t i = 0; i < flickChange_pins; i++){
    flickChange[i][1][1] = 0;
  }
  //pinModeでGPIO初期化:
  MsTimer2::set(50, mainLoop);
  MsTimer2::begin;
}

void loop(){
}

void mainLoop(){
  //各配列のデータを移動:
  for(uint8_t i = flickStatus_pins; i > 0; i--){
    for(uint8_t o = flickStatus_pastDatas; o > 1 ; o--){
      flickStatus[i][o] = flickStatus[i-1][o-1];
    }
  }
  for(uint8_t i = swStatus_pins; i > 0; i--){
    for(uint8_t o = swStatus_pastDatas; o > 1 ; o--){
      swStatus[i][o] = swStatus[i-1][o-1];
    }
  }
  
  //配列の先頭行に新たなデータを追加:
  for(uint8_t i = 0; i < flickStatus_pins; i++){
    flickStatus[i][0] = ;  //ハードウェア仕様決定後に追記:
  }
  for(uint8_t i = 0; i < swStatus_pins; i++){
    swStatus[i][0] = ;     //ハードウェア仕様決定後に追記:
  }
}

void keyOut(uint16_t code){
  
}
