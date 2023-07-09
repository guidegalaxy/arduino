// Buzzer'ın bağlı olduğu pin
const int buzzerPin = 9;

// Star Wars müziği notaları
int starWarsMelody[] = {
  440, 440, 440, 349, 523, 440, 349, 523,
  440, 659, 659, 587, 523, 494, 494, 440,
  349, 523, 440, 349, 523, 440
};

// Star Wars müziği zamanlamaları
int starWarsNoteDurations[] = {
  4, 4, 4, 2, 4, 4, 4, 2,
  4, 4, 4, 2, 4, 4, 4, 2,
  4, 4, 4, 2, 4, 4
};

void setup() {
  // Buzzer pinini çıkış olarak ayarla
  pinMode(buzzerPin, OUTPUT);
}

void loop() {
  // Star Wars müziğini çal
  playStarWarsMelody();
}

void playStarWarsMelody() {
  // Müziği notalara ve zamanlamalara göre çal
  for (int i = 0; i < sizeof(starWarsMelody) / sizeof(starWarsMelody[0]); i++) {
    int noteDuration = 1000 / starWarsNoteDurations[i];
    tone(buzzerPin, starWarsMelody[i], noteDuration);
    int pauseBetweenNotes = noteDuration * 1.30;
    delay(pauseBetweenNotes);
    noTone(buzzerPin);
  }
}
