// Buzzer'ın bağlı olduğu pin
const int buzzerPin = 9;

// Star Wars müziği notaları
int starWarsMelody[] = {
  NOTE_A4, NOTE_A4, NOTE_A4, NOTE_F4, NOTE_C5, NOTE_A4, NOTE_F4, NOTE_C5,
  NOTE_A4, NOTE_E5, NOTE_E5, NOTE_D5, NOTE_C5, NOTE_B4, NOTE_B4, NOTE_A4,
  NOTE_F4, NOTE_C5, NOTE_A4, NOTE_F4, NOTE_C5, NOTE_A4
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
