#include <ESP32Servo.h> //ESP32Servo by Kevin Harrington
const int trigPin = 3; //3:ConnectorA 4:ConnectorB
const int echoPin = 1; //1:ConnectorA 5:ConnectorB

float Duration = 0; //Received Interval Time
float Distance = 0; //Calculation results from Duration

//Servo Motor
const int motorPin = 4; //3:ConnectorA 4:ConnectorB

Servo myservo;  // Servo instance

void setup() {
  Serial.begin(115200);
  pinMode(echoPin,INPUT);
  pinMode(trigPin,OUTPUT);
  myservo.attach(motorPin); // Servo
}

void loop() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH); //Ultrasonic output
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  Duration = pulseIn(echoPin, HIGH); //Input from sensor
  Duration = Duration/2; //Half the round trip time
  Distance = Duration*340*100/1000000; //Set sonic speed to 340 m/s

  //Look at the serial monitor
  Serial.print("空間の距離:");
  Serial.print(Distance);
  Serial.println("cm");
  delay(500);
  if (Distance < 30.0) {  //Combination with Servo
      // 0-180 right
    for(int angle = 0; angle <= 90; angle++) {                        
     myservo.write(angle);
      delay(100);
    }
      // 180-0  left 
    for(int angle = 180; angle >= 0; angle--) {                 
      myservo.write(angle);  
      delay(15);      
    }                 //End of combination
  }
}

