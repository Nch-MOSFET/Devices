#include <BleKeyboard.h>

#define PULLUP

#ifdef PULLUP
 #define Pressed  0
 #define Released 1
#else
 #define Pressed  1
 #define Rereased 0
#endif

#define LED_PIN 23

#define SW_1_1 27
#define SW_1_2 14
#define SW_1_3 12
#define SW_2_1 17
#define SW_2_2 16
#define SW_2_3  4

uint8_t usingPins[] = {SW_1_1, SW_1_2, SW_1_3, SW_2_1, SW_2_2, SW_2_3};

void setup() {
  for(uint8_t i = 0; i < sizeof(usingPins); i++) {
    pinMode(usingPins[i],  INPUT);
  }
}

void loop() {
}
