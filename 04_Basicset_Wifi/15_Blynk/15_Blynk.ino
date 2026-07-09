#define BLYNK_PRINT Serial

//#define BLYNK_TEMPLATE_ID "xxxxxx"
//#define BLYNK_TEMPLATE_NAME "xxxxxx"
//#define BLYNK_AUTH_TOKEN "xxxxxx"

#define BLYNK_TEMPLATE_ID "XXXX"
#define BLYNK_TEMPLATE_NAME "ESP32CherryIoT"
#define BLYNK_AUTH_TOKEN "XXXX"

#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>

char ssid[] = "XXXX";
char pass[] = "XXXX";

const int ledPin = 3; //3:ConnectorA 4:ConnectorB 10:Builtin

void setup()
{
  Serial.begin(115200);
  pinMode(ledPin, OUTPUT);
  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);
}

BLYNK_WRITE(V0)
{
  int value = param.asInt();
  digitalWrite(ledPin, value);
  Serial.println(value ? "LED ON" : "LED OFF");
}

void loop()
{
  Blynk.run();
}

