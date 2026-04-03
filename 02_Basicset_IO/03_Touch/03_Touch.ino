const int touchPin = 3; //3:ConnectorA 4:ConnectorB

void setup() {
  Serial.begin(115200);
  pinMode(touchPin, INPUT);
}

void loop() {
  //Look at the serial monitor
  if (digitalRead(touchPin) == LOW) {
    Serial.println("Non Touch!");
    delay(200);
  } else {
    Serial.println("...");
    delay(200);
  }
  delay(500);
}