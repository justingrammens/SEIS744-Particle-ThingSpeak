// This #include statement was automatically added by the Particle IDE.
#include <Grove_Temperature_And_Humidity_Sensor.h>

DHT dht(D2);

// This #include statement was automatically added by the Particle IDE.
#include "ThingSpeak.h"

TCPClient client;

unsigned long myChannelNumber = XXXX;    // change this to your channel number
const char * myWriteAPIKey = "XXXX"; // change this to your channels write API key

float temp, humidity;

void setup() {
  ThingSpeak.begin(client);

  Serial.begin(9600);
  dht.begin();


}

void loop() {
// read the input on analog pin 0:
//int sensorValue = analogRead(A0);

temp = dht.getTempFarenheit();
humidity = dht.getHumidity();

Serial.printlnf("Temp: %f", temp);
Serial.printlnf("Humidity: %f", humidity);

// Write to ThingSpeak, field 1, immediately
ThingSpeak.writeField(myChannelNumber, 1, temp, myWriteAPIKey);
delay(20000); // ThingSpeak will only accept updates every 15 seconds.
}