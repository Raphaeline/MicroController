#include <Servo.h>

// Constants
const int TRIG_PIN = 12;
const int ECHO_PIN = 13;
const int SERVO_PIN = 2;
const int DISTANCE_THRESHOLD = 10; // centimeters

Servo servo;

void setup() {
  Serial.begin(9600);
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  servo.attach(SERVO_PIN);
}

void loop() {
  // Trigger ultrasonic sensor
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);

  // Measure echo duration
  long duration = pulseIn(ECHO_PIN, HIGH);
  float distance = duration * 0.034 / 2; // Calculate distance in centimeters

  if (distance <= DISTANCE_THRESHOLD) {
    // Object within range, rotate servo 90 degrees
    servo.write(90);
    delay(1000); // Wait for servo to reach the desired position
  } else {
    // Object out of range, do nothing
    servo.write(0);
  }

  // Print distance to Serial Monitor
  Serial.print("Jarak: ");
  Serial.print(distance);
  Serial.println(" cm");

  delay(500);
}
