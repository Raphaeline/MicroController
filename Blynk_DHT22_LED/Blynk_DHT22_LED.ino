#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include <DHT.h>

char auth[] = "116Pt3G4mpbQGSWidM7WpOwhMDYTiYWc"; // Masukkan token otentikasi Blynk Anda
char ssid[] = "MAIAIONE"; // Nama jaringan WiFi Anda
char pass[] = "12121212"; // Kata sandi WiFi Anda

#define DHTPIN 2      // Pin data DHT22 terhubung ke D2 (GPIO 4)
#define DHTTYPE DHT22  // Jenis sensor DHT22

#define GREEN_LED 16  // Pin GPIO yang terhubung ke LED hijau
#define RED_LED 13    // Pin GPIO yang terhubung ke LED merah

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(9600);
  Blynk.begin(auth, ssid, pass);

  dht.begin();

  pinMode(GREEN_LED, OUTPUT);
  pinMode(RED_LED, OUTPUT);

  digitalWrite(GREEN_LED, LOW);
  digitalWrite(RED_LED, LOW);
}

void loop() {
  Blynk.run();
  float humidity = dht.readHumidity();
  float temperature = dht.readTemperature();

  if (isnan(humidity) || isnan(temperature)) {
    Serial.println("Gagal membaca sensor DHT22!");
    digitalWrite(RED_LED, HIGH); // Menghidupkan LED merah
    delay(500);
    digitalWrite(RED_LED, LOW);  // Mematikan LED merah
    delay(500);
    return;
  }

  digitalWrite(GREEN_LED, HIGH); // Menghidupkan LED hijau

  Serial.print("Suhu: ");
  Serial.print(temperature);
  Serial.print(" °C, Kelembapan: ");
  Serial.print(humidity);
  Serial.println(" %");

  Blynk.virtualWrite(V1, temperature);  // Mengirim data suhu ke pin virtual V1 di aplikasi Blynk
  Blynk.virtualWrite(V2, humidity);     // Mengirim data kelembapan ke pin virtual V2 di aplikasi Blynk

  delay(2000); // Interval pembacaan sensor

  digitalWrite(GREEN_LED, LOW);  // Mematikan LED hijau
}
