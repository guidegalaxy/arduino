// Ultrasonik sensörünün bağlı olduğu pinler
const int trigPin = 2; // Trigger pini
const int echoPin = 3; // Echo pini

// LED'in bağlı olduğu pin
const int ledPin = 9;

// Mesafe değeri
int distance;

void setup() {
  // Pin modlarını ayarla
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(ledPin, OUTPUT);

  Serial.begin(9600); // Seri iletişim başlat
}

void loop() {
  // Trigger pini için 10 mikrosaniye süreyle yüksek sinyal gönder
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Echo pini üzerinden gelen sinyalin süresini ölç
  unsigned long duration = pulseIn(echoPin, HIGH);

  // Ses dalgasının gidip dönmesi arasındaki süreyi mesafeye dönüştür
  distance = duration * 0.034 / 2;

  // Mesafe değerini seri monitöre yazdır
  Serial.print("Mesafe: ");
  Serial.print(distance);
  Serial.println(" cm");

  // Mesafeye göre LED parlaklığını ayarla
  analogWrite(ledPin, map(distance, 0, 100, 0, 255));

  delay(500); // Ölçüm aralığı için bekle
}


/*
____Bağlantı şeması_____

Ultrasonik Sensör:
  - VCC --> Arduino 5V
  - GND --> Arduino GND
  - trigPin --> Arduino D2
  - echoPin --> Arduino D3

LED:
  - Anot (uzun bacak) --> Arduino D9
  - Katot (kısa bacak) --> Arduino GND

*/
