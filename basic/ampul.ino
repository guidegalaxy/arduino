// Dijital 3 pinini ampule bağla
int ampulPin = 3;

void setup() {
  // ampulPin'i çıkış olarak ayarla
  pinMode(ampulPin, OUTPUT);
}

void loop() {
  // Ampulu yak
  digitalWrite(ampulPin, HIGH);
  delay(1000); // 1 saniye bekle

  // Ampulu söndür
  digitalWrite(ampulPin, LOW);
  delay(1000); // 1 saniye bekle
}
