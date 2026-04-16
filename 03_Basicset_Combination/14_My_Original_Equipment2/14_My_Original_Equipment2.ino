
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h> //by Adafruit

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET     -1
#define SCREEN_ADDRESS 0x3C

const int swPin = 3; //3:ConnectorA 4:ConnectorB *input Connector A
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);
int txtsize = 1;
int count=0;

void setup() {
  Serial.begin(115200);   //Input Switch
  pinMode(swPin, INPUT);

  Wire.begin(5, 4); //(SDA, SCL) 1,3:ConnectorA 5,4:ConnectorB * Output Display
  if(!display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS)) {
    for(;;); //Infinite loop when screen initialization fails
  }
  display.setTextWrap(false);  // Disable wrapping

}

void loop() {
  if (digitalRead(swPin) == HIGH) {
    //Look at the serial monitor
    Serial.println("Pushed"); 
    if (txtsize == 3) {txtsize =1;}
    else{ txtsize++;}
//from OLED
    for(int i=0; i<64; i++){
     display.clearDisplay();

     display.setTextSize(txtsize);
     display.setTextColor(SSD1306_WHITE);
     display.setCursor(i*2, i-20);
     display.print(F("CherryIoT"));

     display.display();
     delay(20);
     Serial.print("txtsize=");
     Serial.println(txtsize);
     
  }

//end of OLED
    delay(500);
  } else {
    Serial.println("Not Pushed");
    delay(500);
  }
}
