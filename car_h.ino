#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
//#include <BlynkSimpleEsp8266.h>
 
//Motor PINs
#define ENA D0
#define IN1 D1
#define IN2 D2
#define IN3 D3
#define IN4 D4
#define ENB D5
 
bool forward = 0;
bool backward = 0;
bool left = 0;
bool right = 0;
int Speed;
int incomingByte;
//char auth[] = "qf_WLLsCzQXrPx3FazbIIY30R_IGIKEr"; 
//char ssid[] = "SMASH"; 
//char pass[] = "kartikeyamandhar"; 
 
 
void setup() {
  Serial.begin(9600);
  pinMode(ENA, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  pinMode(ENB, OUTPUT);
}
  /*Blynk.begin(auth, ssid, pass);
}
 
BLYNK_WRITE(V0) {
  forward = param.asInt();
}
 
BLYNK_WRITE(V1) {
  backward = param.asInt();
}
 
BLYNK_WRITE(V2) {
  left = param.asInt();
}
 
BLYNK_WRITE(V3) {
  right = param.asInt();
}
 
BLYNK_WRITE(V4) {
  Speed = param.asInt();
}*/
 
 
void smartcar() {
  incomingByte=Serial.read();
  if (incomingByte == 'F') {
    carforward();
    //Serial.println(“carforward”);
  } else if (incomingByte == 'B') {
    carbackward();
    //Serial.println(“carbackward”);
  } else if (incomingByte == 'L') {
    carturnleft();
    //Serial.println(“carfleft”);
  } else if (incomingByte == 'R') {
    carturnright();
    //Serial.println(“carright”);
  } else if (incomingByte=='S') {
    carStop();
    //Serial.println(“carstop”);
  }
}
void loop() {
  //Blynk.run();
  smartcar();
}
 
void carforward() {
  
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}
void carbackward() {
  
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}
void carturnleft() {
 
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}
void carturnright() {
  analogWrite(ENA, Speed);
  analogWrite(ENB, Speed);
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}
void carStop() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
}
