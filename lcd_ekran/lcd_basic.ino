#include <LiquidCrystal.h>

// LCD ekranın bağlı olduğu pinler
const int rs = 12;
const int en = 11;
const int d4 = 5;
const int d5 = 4;
const int d6 = 3;
const int d7 = 2;

// LCD objesi oluşturma
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

void setup() {
  // LCD ekranın satır ve sütun sayısını belirle
  lcd.begin(16, 2);
  
  // Yazıyı ekrana yazdır
  lcd.print("Merhaba!");
  
    // İkinci satıra geç
  lcd.setCursor(0, 1);
  lcd.print("Dunya!");
}

void loop() {
  // Devamlı yazıyı ekranda tutmak için loop fonksiyonunda ek bir işlem yapmanız gerekmez
}


/*
____Bağlantı şeması_____

LCD Ekran:
  - VSS --> Arduino GND
  - VDD --> Arduino 5V
  - V0 --> Orta noktadan bir potansiyometre ayarı yapılır
  - RS --> Arduino D12
  - RW --> Arduino GND
  - EN --> Arduino D11
  - D4 --> Arduino D5
  - D5 --> Arduino D4
  - D6 --> Arduino D3
  - D7 --> Arduino D2
  - A --> Arduino 5V (Arka ışık için)
  - K --> Arduino GND (Arka ışık için)

*/
