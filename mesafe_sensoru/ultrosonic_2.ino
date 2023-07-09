// Ultrasonik sensörün bağlı olduğu pinler
const int trigPin = 2; // Tetikleme pini
const int echoPin = 3; // Yanıt pini

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
  // Tetikleme pini için 10 mikrosaniye süreyle yüksek sinyal gönder
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Yanıt pini üzerinden gelen sinyalin süresini ölç
  unsigned long duration = pulseIn(echoPin, HIGH);

  // Ses dalgasının gidip dönmesi arasındaki süreyi mesafeye dönüştür
  distance = duration * 0.034 / 2;

  // Mesafe değerini seri monitöre yazdır
  Serial.print("Mesafe: ");
  Serial.print(distance);
  Serial.println(" cm");

  // Mesafeye göre LED parlaklığını ayarla
  if (distance <= 10) {
    analogWrite(ledPin, 255); // En yüksek parlaklık
  } else if (distance <= 50) {
    analogWrite(ledPin, 100); // Orta parlaklık
  } else {
    analogWrite(ledPin, 0); // Düşük parlaklık
  }

  delay(500); // Ölçüm aralığı için bekle
}


/*

____Bağlantı şeması______

Ultrasonik Sensör:
  - VCC --> Arduino 5V
  - GND --> Arduino GND
  - Trig --> Arduino D2
  - Echo --> Arduino D3

LED:
  - Anot (uzun bacak) --> Direnç --> Arduino D9
  - Katot (kısa bacak) --> Arduino GND

*/
