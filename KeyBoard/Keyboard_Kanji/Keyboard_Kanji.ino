//Arduino Pro Microを使用する場合次の行をコメント解除,Digisparkを使用する場合そのまま:
//#define Pro_Micro

//入力の最後に改行を入れたい場合次の行をコメント解除:
//#define EndEnter_True

//キーボード方式を指定, USキーボードとして扱われる場合次の行をコメント解除:
//#define US_Keyboard

//各Unicode配列に格納する要素数の指定:
#define Kanji1_Long 6
#define Kanji2_Long 6

//入力させたい文字のUnicodeコードポイントを16進数で定義:
uint16_t Kanji1[Kanji1_Long] = {0x4e00, 0x822c, 0x306e, 0x3054, 0x5bb6, 0x5ead};  //一般のご家庭:
uint16_t Kanji2[Kanji2_Long] = {0x9038, 0x822c, 0x306e, 0x8aa4, 0x5bb6, 0x5ead};  //逸般の誤家庭:

#ifdef Pro_Micro

#include <Keyboard.h>
#define InputA 3
#define InputB 5

byte PinA_old_data = 1;
byte PinB_old_data = 1;
byte PinA_new_data = 1;
byte PinB_new_data = 1;

void setup() {
  pinMode(InputA, INPUT_PULLUP);
  pinMode(InputB, INPUT_PULLUP);
  Keyboard.begin();
}

void loop() {
  if (PinA_old_data == 1 && PinA_new_data == 0) {
    for (uint16_t i = 0; i < Kanji1_Long; i++) {
      typeUnicode(Kanji1[i]);
    }
#ifdef EndEnter_True
    Keyboard.println();
#endif
  }

  if (PinB_old_data == 1 && PinB_new_data == 0) {
    for (uint16_t i = 0; i < Kanji2_Long; i++) {
      typeUnicode(Kanji2[i]);
    }
#ifdef EndEnter_True
    Keyboard.println();
#endif
  }

  PinA_old_data = PinA_new_data;
  PinB_old_data = PinB_new_data;

  PinA_new_data = digitalRead(InputA);
  PinB_new_data = digitalRead(InputB);

  delay(50);
}

void typeUnicode(uint16_t key) {
#ifdef US_Keyboard
  Keyboard.print("U:");
#else
  Keyboard.print("U+");
#endif
  Keyboard.print(key, HEX);
  Keyboard.println("  ");
}

#else

#include <DigiKeyboard.h>
#define InputA 0
#define InputB 2

byte PinA_old_data = 1;
byte PinB_old_data = 1;
byte PinA_new_data = 1;
byte PinB_new_data = 1;

void setup() {
  pinMode(InputA, INPUT);
  pinMode(InputB, INPUT);
}

void loop() {
  if (PinA_old_data == 1 && PinA_new_data == 0) {
    for (uint16_t i = 0; i < Kanji1_Long; i++) {
      typeUnicode(Kanji1[i]);
    }
#ifdef EndEnter_True
    DigiKeyboard.println();
#endif
  }
  
  if (PinB_old_data == 1 && PinB_new_data == 0) {
    for (uint16_t i = 0; i < Kanji2_Long; i++) {
      typeUnicode(Kanji2[i]);
    }
#ifdef EndEnter_True
    DigiKeyboard.println();
#endif
  }
  PinA_old_data = PinA_new_data;
  PinB_old_data = PinB_new_data;

  PinA_new_data = digitalRead(InputA);
  PinB_new_data = digitalRead(InputB);

  delay(50);
}

void typeUnicode(uint16_t key) {
#ifdef US_Keyboard
  DigiKeyboard.print("U:");
#else
  DigiKeyboard.print("U+");
#endif
  DigiKeyboard.print(key, HEX);
  DigiKeyboard.println("  ");
}
#endif
