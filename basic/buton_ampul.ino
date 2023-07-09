// Butonun bağlı olduğu pin
const int buttonPin = 2;

// Ampulün bağlı olduğu pin
const int bulbPin = 9;

// Buton durumu
int buttonState = 0;

void setup() {
  pinMode(buttonPin, INPUT); // Buton pinini giriş olarak ayarla
  pinMode(bulbPin, OUTPUT); // Ampul pinini çıkış olarak ayarla
}

void loop() {
  buttonState = digitalRead(buttonPin); // Buton durumunu oku

  if (buttonState == HIGH) {
    digitalWrite(bulbPin, LOW); // Buton basılmadığında ampulu söndür
  } else {
    digitalWrite(bulbPin, HIGH); // Buton basıldığında ampulu yak
  }
}


/*
______Bağlantı şeması______

Buton:
  - Bir uç --> Arduino D2
  - Diğer uç --> Arduino GND

Ampul:
  - Bir uç --> Arduino D9
  - Diğer uç --> Arduino GND

*/
