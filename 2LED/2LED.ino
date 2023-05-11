
const int ledPin1 = 2; // Pin LED Merah
const int ledPin2 = 3; // Pin LED Kuning
const int ledPin3 = 4; // Pin LED Biru
const int ledPin4 = 5;

void setup() {
  pinMode(ledPin1, OUTPUT);
  pinMode(ledPin2, OUTPUT);
  pinMode(ledPin3, OUTPUT);
  pinMode(ledPin4, OUTPUT);
}

void loop() {
  digitalWrite(ledPin1, HIGH); // Menghidupkan LED pertama
  digitalWrite(ledPin2, LOW); // Mematikan LED kedua
  digitalWrite(ledPin3, LOW); // Mematikan LED ketiga
  digitalWrite(ledPin4, LOW); // Mematikan LED keempat
  delay(250); // Delay selama 500 ms

  digitalWrite(ledPin1, LOW); // Mematikan LED pertama
  digitalWrite(ledPin2, HIGH); // Menghidupkan LED kedua
  digitalWrite(ledPin3, LOW); // Mematikan LED ketiga
  digitalWrite(ledPin4, LOW); // Mematikan LED keempat
  delay(250); // Delay selama 500 ms

  digitalWrite(ledPin1, LOW); // Mematikan LED pertama
  digitalWrite(ledPin2, LOW); // Mematikan LED kedua
  digitalWrite(ledPin3, HIGH); // Menghidupkan LED ketiga
  digitalWrite(ledPin4, LOW); // Mematikan LED keempat
  delay(250); // Delay selama 500 ms
  
  digitalWrite(ledPin1, LOW); // Mematikan LED pertama
  digitalWrite(ledPin2, LOW); // Mematikan LED kedua
  digitalWrite(ledPin3, LOW); // Menghidupkan LED ketiga
  digitalWrite(ledPin4, HIGH); // Mematikan LED keempat
  delay(250); // Delay selama 500 ms

  digitalWrite(ledPin1, LOW); // Mematikan LED pertama
  digitalWrite(ledPin2, LOW); // Mematikan LED kedua
  digitalWrite(ledPin3, HIGH); // Menghidupkan LED ketiga
  digitalWrite(ledPin4, LOW); // Mematikan LED keempat
  delay(250); // Delay selama 500 ms
  
  digitalWrite(ledPin1, LOW); // Mematikan LED pertama
  digitalWrite(ledPin2, HIGH); // Menghidupkan LED kedua
  digitalWrite(ledPin3, LOW); // Mematikan LED ketiga
  digitalWrite(ledPin4, LOW); // Mematikan LED keempat
  delay(250); // Delay selama 500 ms
}
