#include <Servo.h>

// Constants
const int LDR_PIN = A1;      // LDR pin connected to analog input A0
const int SERVO_PIN = 6;     // Servo pin connected to digital pin 9
const int LDR_THRESHOLD = 250; // LDR threshold value for servo activation

Servo servo;

void setup() {
  Serial.begin(9600);
  pinMode(LDR_PIN, INPUT);
  servo.attach(SERVO_PIN);
}

void loop() {
  // Read LDR value
  int ldrValue = analogRead(LDR_PIN);

  if (ldrValue <= LDR_THRESHOLD) {
    // LDR value below threshold, rotate servo 90 degrees
    servo.write(90);
    delay(1000);
  } else {

    servo.write(0);
  }
    Serial.print("value : ");
    Serial.println(ldrValue);
    delay(500);
}
