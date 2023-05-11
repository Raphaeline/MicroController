#include <Servo.h>

// constants won't change
const int TRIG_PIN  = 12;  
const int ECHO_PIN  = 13;  
const int SERVO_PIN = 2; 
const int DISTANCE_THRESHOLD = 50; // centimeters

Servo servo;


float durasi, jarak;

void setup() {
  Serial.begin (9600);       // initialize serial port
  pinMode(TRIG_PIN, OUTPUT); // set arduino pin to output mode
  pinMode(ECHO_PIN, INPUT);  // set arduino pin to input mode
  servo.attach(SERVO_PIN);   // attaches the servo on pin 9 to the servo object
  servo.write(0);
}

void loop() {
  // generate 10-microsecond pulse to TRIG pin
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);

  
  durasi = pulseIn(ECHO_PIN, HIGH);
  
  jarak = 0.017 * durasi;

  if(jarak < DISTANCE_THRESHOLD)
    servo.write(189); // rotate servo motor to 90 degree
  else
    servo.write(0);  // rotate servo motor to 0 degree

  // print the value to Serial Monitor
  Serial.print("distance: ");
  Serial.print(jarak);
  Serial.println(" cm");

  delay(500);
}