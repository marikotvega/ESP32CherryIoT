#include <DHT20.h> //DHT20 by RobTillaart
#include <Wire.h>

DHT20 DHT;
const int motorPin = 4; //3:ConnectorA 4:ConnectorB *DC Motor Connector B


void setup() {
  Serial.begin(115200);
  Wire.begin(1, 3); //1,3:ConnectorA 5,4:ConnectorB *Thermo censor Connector A
  pinMode(motorPin, OUTPUT);
}

void loop() {
  DHT.read();
  float Temperature = DHT.getTemperature();
  float Humidity = DHT.getHumidity();
  //Look at the serial monitor
  Serial.println(String(Humidity) + "％");
  Serial.print(" / ");
  Serial.print(String(Temperature) + "℃");
  
  if ((Temperature > 24.0) || (Humidity > 85.0)){
    Serial.println("扇風機を思いっきり回します。");
    digitalWrite(motorPin, HIGH);
    delay(3000);
    digitalWrite(motorPin, LOW);
    delay(1000);
    }
  else{
    Serial.println("扇風機を試しに回してみます。");
    digitalWrite(motorPin, HIGH);
    delay(500);
    digitalWrite(motorPin, LOW);
    delay(5000);
    }

  delay(500);
}
