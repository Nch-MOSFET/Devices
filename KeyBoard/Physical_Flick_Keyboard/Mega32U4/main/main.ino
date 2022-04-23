//#include <Keyboard.h>
#include <SPI.h>

#define BaudRate 115200

//実際の回路に合わせて要変更:
#define MISO 12
#define MOSI 11
#define  CLK 13

uint8_t    CS[  ] = {5, 6, 7};  //実際の回路に合わせて要変更:
uint8_t  Buff[ 2];
uint8_t  data[20];  //8, 8, 4bit:
uint16_t ADCs;

SPISettings settings(1000000, MSBFIRST, SPI_MODE0);

void setup() {
//  Keyboard.begin();
  Serial.begin(BaudRate);
  SPI.begin();

  Serial.print("sizeof(CS) = ");
  Serial.println(sizeof(CS));
  for(uint8_t i = 0; i < sizeof(CS); i++){
    pinMode     (CS[i], OUTPUT);
    digitalWrite(CS[i],   HIGH);
  }
}

void loop() {
  SPI.beginTransaction(settings);
}
