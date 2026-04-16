const int ruptPin = 3; //3:ConnectorA 4:ConnectorB  * interruptor
const int vibPin = 4; //3:ConnectorA 4:ConnectorB   * vibration
int count = 0;
void setup(){
  pinMode(ruptPin, INPUT);
  Serial.begin(115200);
  pinMode(vibPin, OUTPUT);
}

void loop(){
  //Look at the serial monitor
  if (digitalRead(ruptPin)==LOW) {
    count++;
    Serial.println("Interrupt");
    Serial.println(count);
  } else {
    Serial.println("None");
    Serial.println(count);
  }
  delay(500);
   if (count ==5){
    digitalWrite(vibPin, HIGH);
    delay(1000);
    digitalWrite(vibPin, LOW);
    delay(5000);
    count = 0; //reset counter 
   }
}
