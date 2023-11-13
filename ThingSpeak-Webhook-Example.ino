int led = D7;  // The on-board LED

void setup() {
  // make sure you create your own integration following the example in the README
  Particle.subscribe("hook-response/temp", myHandler, MY_DEVICES);
  pinMode(led, OUTPUT);
}

void loop() {
  //turning on the LED so we know when it has published!
  digitalWrite(led, HIGH);   // Turn ON the LED

  // To make it easy, let's create some random temps
  String temp = String(random(60, 80));
  Particle.publish("temp", temp, PRIVATE);
  
  delay(20000);               // Wait for 20 seconds

  digitalWrite(led, LOW);    // Turn OFF the LED

  delay(20000);               // Wait for 20 seconds
}


void myHandler(const char *event, const char *data) {
  // Handle the webhook response
  Serial.println(event);
  Serial.println(data);
    
  // shows and example of publishing the response message to Particle cloud. You can see it in the Particle Console in your web browser.
  Particle.publish("GotIt", String(data));
}