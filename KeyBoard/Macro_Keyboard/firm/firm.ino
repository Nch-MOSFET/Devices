uint8_t incomingByte = 0;  // 受信データ用
char forEncorder_Large[27] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
char forEncorder_Small[27] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};

void setup() {
  Serial.begin(9600); // 9600bpsでシリアルポートを開く
}

void loop() {
  if (Serial.available() > 0) { // 受信したデータが存在する
    incomingByte = Serial.read(); // 受信データを読み込む

    Serial.print("I received: "); // 受信データを送りかえす
    Serial.println(incomingByte, HEX);
    Serial.print("Encored   :  ");
    if(incomingByte >= 0x30 && 0x39 >= incomingByte){
      Serial.println(encorder_Num(incomingByte));
    }else if((incomingByte >= 0x41 && 0x5A >= incomingByte) || (incomingByte >= 0x61 && 0x7A >= incomingByte)){
      Serial.println(encorder_Chr(incomingByte));
    }
  }
}
uint8_t encorder_Num(uint8_t dat){
  //0~9の処理:
  if(dat >= 0x30 && 0x39 >= dat){
    return (dat - 0x30);
  }
}
char encorder_Chr(uint8_t dat){
  //A~Zの処理:
  if(dat >= 0x41 && 0x5A >= dat){
    return forEncorder_Large[dat - 0x41];
  }
  //a~zの処理:
  if(dat >= 0x61 && 0x7A >= dat){
    return forEncorder_Small[dat - 0x61];
  }
}
