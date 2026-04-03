const int ruptPin = 3; //3:ConnectorA 4:ConnectorB

void setup(){
  pinMode(ruptPin, INPUT);
  Serial.begin(115200);
}

void loop(){
  //Look at the serial monitor
  if (digitalRead(ruptPin)==HIGH) {
    Serial.println("None!");
  } else {
    Serial.println("Interrupt！...");
  }
  delay(500);
}
