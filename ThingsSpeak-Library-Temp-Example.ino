#include "ThingSpeak.h"

unsigned long myChannelNumber = XXXX;    // change this to your channel number
const char * myWriteAPIKey = "XXXX"; // change this to your channels write API key

TCPClient client;

void setup() {
  ThingSpeak.begin(client);
  Serial.begin(9600);
}

void loop() {

// To make it easy, let's create some random temps
String temp = String(random(60, 80));

Serial.printlnf("Temp: ", temp);

// Using the Library, write to ThingSpeak, field 1, immediately
ThingSpeak.writeField(myChannelNumber, 1, temp, myWriteAPIKey);
delay(20000); // ThingSpeak will only accept updates every 15 seconds, let's make a 20 second delay to be safe

}
