// Menghubungkan LED ke pin Arduino
const int ledMerahPin = 3; // Pin LED merah
const int ledHijauPin = 4; // Pin LED hijau

// Menghubungkan sensor ultrasonik ke pin Arduino
const int trigPin = 13; // Pin trigger sensor ultrasonik
const int echoPin = 12; // Pin echo sensor ultrasonik

void setup() {
  pinMode(ledMerahPin, OUTPUT);
  pinMode(ledHijauPin, OUTPUT);

  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  // Mematikan LED awal saat program dimulai
  digitalWrite(ledMerahPin, LOW);
  digitalWrite(ledHijauPin, LOW);
}

void loop() {
  // Mengirimkan sinyal trigger ke sensor ultrasonik
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Menerima dan menghitung waktu pantulan sinyal dari objek yang terdeteksi
  long duration = pulseIn(echoPin, HIGH);

  // Menghitung jarak berdasarkan waktu pantulan
  int distance = duration * 0.034 / 2;

  // Menyalakan LED merah jika objek dekat (jarak kurang dari 20 cm)
  if (distance < 10) {
    digitalWrite(ledMerahPin, HIGH);
    digitalWrite(ledHijauPin, LOW);
  } else {
    digitalWrite(ledMerahPin, LOW);
    digitalWrite(ledHijauPin, HIGH);
  }

  delay(100); // Delay untuk stabilitas pembacaan
}
