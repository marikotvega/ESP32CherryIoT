//https://www.haruirosoleil.com/entry/2020/02/02/101937

#include <WiFi.h>
#include <WiFiClientSecure.h>
#include <DHT20.h> //DHT20 by RobTillaart
#include <Wire.h>

DHT20 DHT;
//Distance censor
const int trigPin = 4; //3:ConnectorA 4:ConnectorB
const int echoPin = 5; //1:ConnectorA 5:ConnectorB

float Duration = 0; //Received Interval Time
float Distance = 0; //Calculation results from Duration
  

// 接続先のSSIDとパスワード
const char* ssid = "AAAXXXXX"; //無線ルーターのssidを入力
const char* password = "AAAXXXXX"; //無線ルーターのパスワードを入力

const int litsnsrPin = 3; //3:ConnectorA 4:ConnectorB

void setup() {
  Serial.begin(115200);
  pinMode(litsnsrPin, INPUT);
  Wire.begin(1, 3); //1,3:ConnectorA 5,4:ConnectorB
  pinMode(echoPin,INPUT);
  pinMode(trigPin,OUTPUT);
}


void loop() {
  sendData();
  delay(10000);
}


//WiFiに接続
void connectWiFi(){

  Serial.print("ssid:");
  Serial.print(ssid);
  Serial.println(" に接続します。");

  WiFi.begin(ssid, password);

  Serial.print("WiFiに接続中");
  while(WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(500);
  }

  Serial.println("接続しました。");

  //IPアドレスの表示
  Serial.print("IPアドレス:");
  Serial.println(WiFi.localIP());
}

 

//測定データの送信
void sendData(){

  WiFiClientSecure sslclient;

  const char* server = "script.google.com";
//  String url = "https://script.google.com/macros/s/xxxxxxxxxxxxxx/exec";  //googlescript web appのurlを入力
  String url = "https://script.google.com/macros/s/AKfycbyDT1GE-lTbSD6SHS2RpRMjuESWhjq4zlrsFSyV1Aa71P5bOEelzMWOUHFMGrb1Qv4G/exec";

  //測定値を準備
  //float litsnsr_ad = analogRead(litsnsrPin); // Read analog data
  //float litsnsr_v = litsnsr_ad * 3.3 / 4096; // Calculation of voltage value
  //float lux = 10000 * litsnsr_v / (3.3 - litsnsr_v) / 1000; // Calculation of lux value

  DHT.read();
  float Temperature = DHT.getTemperature();
  float Humidity = DHT.getHumidity();
  //Look at the serial monitor
  Serial.println(String(Humidity) + "％");
  Serial.print(" / ");
  Serial.print(String(Temperature) + "℃");
  
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
  //  Serial.print(lux);
  //  Serial.println(" Lux ");
  
 // float sensor_data1= lux;

  //wifiに接続
  connectWiFi();

  //測定値の表示(
 // Serial.println(sensor_data1);
  

  //urlの末尾に測定値を加筆
  url += "?";
  url += "&1_cell=";
  url += String(Humidity);
  url += "&2_cell=";
  url += String(Temperature);
  url += "&3_cell=";
  url += String(Distance);
 
  Serial.println(url);
  // サーバーにアクセス
  Serial.println("サーバーに接続中...");
  sslclient.setInsecure(); //skip verification

  //データの送信
  if (!sslclient.connect(server, 443)) {
    Serial.println("接続に失敗しました");
    Serial.println("");//改行
    return;
  }

  Serial.println("サーバーに接続しました");

  sslclient.println("GET " + url);
  delay(1000); //私の環境ではここに待ち時間を入れないとデータが送れないことがある
  sslclient.stop();

  Serial.println("データ送信完了");
  Serial.println("");//改行

  //WiFiを切断
  WiFi.mode(WIFI_OFF);
}
