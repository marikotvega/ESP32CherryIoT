const int spkrPin = 3; //3:ConnectorA 4:ConnectorB
const int touchPin = 4; //3:ConnectorA 4:ConnectorB

#define DO 261.6
#define _DO 277.18
#define RE 293.665
#define _RE 311.127
#define MI 329.63
#define FA 349.228
#define _FA 369.994
#define SO 391.995
#define _SO 415.305
#define RA 440
#define _RA 466.164
#define TI 493.883
#define octDO 523.251
#define oct_DO 554.36
#define octRE 587.33
#define oct_RE 622.25
#define octMI 659.26

void playmusic(){
 //
//
  delay(300);
  ledcWriteTone(spkrPin, octRE);
  delay(100);
  ledcWriteTone(spkrPin, octDO);
  delay(300);
  ledcWriteTone(spkrPin, octRE);
  delay(100);
  ledcWriteTone(spkrPin, TI);
  delay(300);
  ledcWriteTone(spkrPin, RA);
  delay(100);
  ledcWriteTone(spkrPin, SO);
  delay(600);

  ledcWriteTone(spkrPin, 0); // no sound
  delay(500);
  }


void setup() {

  Serial.begin(115200);
  pinMode(touchPin, INPUT);
  pinMode(spkrPin, OUTPUT);
  ledcAttach(spkrPin, 12000, 8); //Pin setting(Pin num, Max frequency, Resolution)
}

void loop() {

    //Look at the serial monitor
  if (digitalRead(touchPin) == HIGH) {
    Serial.println("Touch!");
    playmusic();
    delay(300);
  } else {
    Serial.println("...");
    delay(200);
  }


}
