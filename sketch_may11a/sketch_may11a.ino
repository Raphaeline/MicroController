
const int ledPin1 = 2;
const int ledPin2 = 3; 
const int ledPin3 = 4; 
const int ledPin4 = 5;

const int buttonPin = 6;

int mode = 0;

int prevButtonState = HIGH;
void setup() {
  pinMode(ledPin1, OUTPUT);
  pinMode(ledPin2, OUTPUT);
  pinMode(ledPin3, OUTPUT);
  pinMode(ledPin4, OUTPUT);

  pinMode(buttonPin, INPUT_PULLUP);
}

void loop() {
  // Membaca status tombol
  int buttonState = digitalRead(buttonPin);

  // Memeriksa perubahan status tombol
  if (buttonState != prevButtonState) {
    // Jika tombol ditekan
    if (buttonState == LOW) {
      // Mengubah mode
      mode = (mode + 1) % 2;
    }
    // Menunda untuk menghindari bounce tombol
    delay(50);
  }

  // Menyimpan status tombol sebelumnya
  prevButtonState = buttonState;

  // Menjalankan mode yang dipilih
  if (mode == 0) {
    nyalasemua(); // Mode kedap kedip semua
  } else {
    berderet(); // Mode kedip berurutan
  }
}



void nyalasemua(){

  digitalWrite(ledPin1, HIGH);
  digitalWrite(ledPin2, HIGH);
  digitalWrite(ledPin3, HIGH);
  digitalWrite(ledPin4, HIGH);
  delay(500);
  digitalWrite(ledPin1, LOW);
  digitalWrite(ledPin2, LOW);
  digitalWrite(ledPin3, LOW);
  digitalWrite(ledPin4, LOW);
  delay(500);
}

void berderet() {
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
