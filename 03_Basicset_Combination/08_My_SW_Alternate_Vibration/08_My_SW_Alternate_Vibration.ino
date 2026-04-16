const int swPin = 3; //3:ConnectorA 4:ConnectorB
const int motorPin = 4; //3:ConnectorA 4:ConnectorB

bool swState = 0;

void setup() {
  Serial.begin(115200);
  pinMode(swPin, INPUT);
  pinMode(motorPin, OUTPUT);
}

void loop() {
  
  if (digitalRead(swPin) == HIGH) {
    swState = !swState;
  }

  if(swState == 1){
    //Look at the serial monitor
    Serial.println("ON");
     digitalWrite(motorPin, HIGH);
    delay(1000);
  } else {
    Serial.println("OFF");
    digitalWrite(motorPin, LOW);
    delay(1000);
  }

}
