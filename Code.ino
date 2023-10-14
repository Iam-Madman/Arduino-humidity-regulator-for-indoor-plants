int requiredhumidity = 80 ;
// change the above variable to change the humidity
const int atomizer = 8;
const int buzzer = 9 ;
#include "DHT.h"
#define DHTPIN 2
#define DHTTYPE DHT11
 DHT dht(DHTPIN, DHTTYPE);
void setup() {
 Serial.begin(9600);
 Serial.println(F("My auto humidifier Made by Abinav"));
 pinMode(atomizer, OUTPUT);-
 pinMode(buzzer, OUTPUT);
 dht.begin();
}
void loop() {
 // Wait a few seconds between measurements.
 delay(10000);
 // Reading temperature or humidity takes about 250 milliseconds!
 // Sensor readings may also be up to 2 seconds 'old' (its a very
slow sensor)
 float h = dht.readHumidity();
 // Check if any reads failed and exit early (to try again).
 if (isnan(h)) {
 Serial.println(F("Failed to read from DHT sensor!"));
 return;
 }
 Serial.print(F(" Humidity: "));
 Serial.print(h);
 Serial.println();
 Serial.print(". . . . . . . . .");
 Serial.println();
 if (h < requiredhumidity ) {
 // turn LED on:
 digitalWrite(atomizer, HIGH);
 digitalWrite(buzzer, HIGH);
 } else {
 // turn LED off:
 digitalWrite(atomizer, LOW);
 digitalWrite(buzzer, LOW);
 }
}
