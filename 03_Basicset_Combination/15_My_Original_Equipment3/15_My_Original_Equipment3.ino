const int swPin = 3; //3:ConnectorA 4:ConnectorB
const int motorPin = 4; //3:ConnectorA 4:ConnectorB
int count = 0;
void setup() {
  Serial.begin(115200);
  pinMode(swPin, INPUT);
  pinMode(motorPin, OUTPUT);
}

void loop() {
  if (digitalRead(swPin) == HIGH) {
    //Look at the serial monitor
    Serial.println("Pushed"); 
    count++;
    Serial.print("count=");
    Serial.println(count);
    delay(500);
  } else {
    Serial.println("Not Pushed");
    count = 0;
    delay(500);
  }
  if (count == 5){
    Serial.println("扇風機を思いっきり回します。");
    digitalWrite(motorPin, HIGH);
    delay(3000);
    digitalWrite(motorPin, LOW);
    delay(1000);
  }
}
