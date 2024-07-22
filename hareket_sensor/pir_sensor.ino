// Arduino'ya bağlı bileşenlerin pin tanımlamaları
const int pirPin = 5;   // PIR sensörünün sinyal pininin Arduino'daki bağlı olduğu pin
const int ledPin = 9;   // LED'in bağlı olduğu pin

void setup() {
  pinMode(pirPin, INPUT);  // PIR sensörünün pinini giriş olarak ayarla
  pinMode(ledPin, OUTPUT); // LED pinini çıkış olarak ayarla
}

void loop() {
  int pirState = digitalRead(pirPin);  // PIR sensöründen okunan değeri al
  
  if (pirState == HIGH) {   // Eğer PIR sensörü hareket algılarsa
    digitalWrite(ledPin, HIGH);  // LED'i yak
    delay(1000);  // 1 saniye bekle
  } else {
    digitalWrite(ledPin, LOW);   // Hareket algılanmadığında LED'i söndür
  }
}


  // Bağlantı açıklamaları
  // Arduino GND - PIR sensörü GND
  // Arduino 5V  - PIR sensörü VCC
  // Arduino 5V  - LED anotu (uzun bacak)
  // Arduino GND - LED katodu (kısa bacak)
  // Arduino pin 5 - PIR sensörü OUT
  // Arduino pin 9 - LED
