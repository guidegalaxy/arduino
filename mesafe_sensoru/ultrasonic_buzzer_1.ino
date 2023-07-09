// Ultrasonik sensörün bağlı olduğu pinler
const int trigPin = 2; // Tetikleme pini
const int echoPin = 3; // Yanıt pini

// Buzzer'ın bağlı olduğu pin
const int buzzerPin = 9;

// Park mesafesi
const int parkDistance = 10; // cm

void setup() {
  pinMode(trigPin, OUTPUT); // Tetikleme pini çıkış olarak ayarla
  pinMode(echoPin, INPUT); // Yanıt pini giriş olarak ayarla
  pinMode(buzzerPin, OUTPUT); // Buzzer pinini çıkış olarak ayarla
  Serial.begin(9600); // Seri iletişimi başlat
}

void loop() {
  long duration, distance;
  
  // Ultrasonik sensörden mesafeyi ölç
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  duration = pulseIn(echoPin, HIGH);
  
  // Mesafeyi hesapla
  distance = (duration / 2) / 29.1;
  
  // Mesafeyi seri monitöre yazdır
  Serial.print("Mesafe: ");
  Serial.println(distance);
  
  // Park mesafesini kontrol et ve uyarı ver
  if (distance <= parkDistance) {
    int frequency = map(distance, 0, parkDistance, 2000, 5000); // Mesafeye göre frekansı hesapla
    tone(buzzerPin, frequency); // Buzzer'ı çal
  } else {
    noTone(buzzerPin); // Buzzer'ı durdur
  }
  
  delay(200); // Ölçüm aralığı için bekle
}




/*
_____Bağlantı şeması_____

Ultrasonik Sensör:
  - VCC --> Arduino 5V
  - GND --> Arduino GND
  - Trig --> Arduino D2
  - Echo --> Arduino D3

Buzzer:
  - Uzun bacak (Anot) --> Arduino D9
  - Kısa bacak (Katot) --> Arduino GND


*/
