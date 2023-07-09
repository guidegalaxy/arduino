// Buzzer'ın bağlı olduğu pin
const int buzzerPin = 9;

// Imperial March notaları
int imperialMarchMelody[] = {
  370, 370, 370, 294, 440, 370, 294, 440,
  370, 370, 370, 294, 440, 370, 294, 440,
  370, 311, 311, 370, 415, 440, 370, 294,
  440, 370, 370, 370, 494, 466, 440, 370, 294,
  370, 415, 440, 370, 294, 440
};

// Imperial March zamanlamaları
int imperialMarchNoteDurations[] = {
  4, 4, 4, 2, 4, 4, 4, 2,
  4, 4, 4, 2, 4, 4, 4, 2,
  4, 4, 4, 4, 4, 4, 4, 2,
  4, 4, 4, 4, 4, 4, 4, 4, 4,
  4, 4, 4, 4, 4, 4
};

void setup() {
  // Buzzer pinini çıkış olarak ayarla
  pinMode(buzzerPin, OUTPUT);
}

void loop() {
  // Imperial March'ı çal
  playImperialMarchMelody();
}

void playImperialMarchMelody() {
  // Müziği notalara ve zamanlamalara göre çal
  for (int i = 0; i < sizeof(imperialMarchMelody) / sizeof(imperialMarchMelody[0]); i++) {
    int noteDuration = 1000 / imperialMarchNoteDurations[i];
    tone(buzzerPin, imperialMarchMelody[i], noteDuration);
    int pauseBetweenNotes = noteDuration * 1.30;
    delay(pauseBetweenNotes);
    noTone(buzzerPin);
  }
}
