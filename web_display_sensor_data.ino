#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>
#include <WiFiUdp.h>
#include <NTPClient.h>
#include <FirebaseArduino.h>
#define FIREBASE_HOST "roboarm-345f1-default-rtdb.firebaseio.com"
#define FIREBASE_AUTH "L6LBmNjLq2n8qFfLKgXxOm3blIZmz75DmiCqpDUQ"
#define WIFI_SSID "SMASH"
#define WIFI_PASSWORD "kartikeyamandhar"
const int trigP = 4;  //D4 Or GPIO-2 of nodemcu
const int echoP = 0;  //D3 Or GPIO-0 of nodemcu
const long secs = 25200;
int inputPin= 13; // D7
int inputPin1= 12; // D6
WiFiUDP ntpUDP;
NTPClient timeClient(ntpUDP,"pool.ntp.org",secs);
long duration;
int distance;
String myString;
String value;
String push;
int val=0;
String value1;
String push1;
int val1=0;
String db="roboarm-345f1-default-rtdb";
void setup() {
Serial.begin(9600);
pinMode(trigP, OUTPUT);  // Sets the trigPin as an Output
pinMode(echoP, INPUT);   // Sets the echoPin as an Input
pinMode(inputPin, INPUT);
WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
Serial.print("connecting");
while (WiFi.status() != WL_CONNECTED){
    Serial.print(".");
    delay(500);
    }
    Serial.println();
    Serial.print("connected: ");
    Serial.println(WiFi.localIP());
    timeClient.begin();
 
    Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
}
String led(String value1,int val1){
  val1 = digitalRead(inputPin1);
  if(val1 == LOW){
    value = "Object has been picked";
  }else{
    value= "Object has been dropped/not picked";
  }
  return value;
}
String led1(String value,int val){
  val = digitalRead(inputPin);
  if(val == LOW){
    value = "Object has been reached";
  }else{
    value= "Object has not been reached";
  }
  return value;
}

void loop() {
timeClient.update();
String hr,mn,sc;
if(timeClient.getHours()<10){
  hr="0"+String(timeClient.getHours());
}else{
  hr=String(timeClient.getHours());
}
if(timeClient.getMinutes()<10){
  mn="0"+String(timeClient.getMinutes());
}else{
  mn=String(timeClient.getMinutes());
}
if(timeClient.getSeconds()<10){
  sc="0"+String(timeClient.getSeconds());
}else{
  sc=String(timeClient.getSeconds());
}
String TimeNow = hr + ":" + mn + ":" + sc;


digitalWrite(trigP, LOW);   // Makes trigPin low
delayMicroseconds(2);       // 2 micro second delay 

digitalWrite(trigP, HIGH);  // tigPin high
delayMicroseconds(10);      // trigPin high for 10 micro seconds
digitalWrite(trigP, LOW);   // trigPin low

duration = pulseIn(echoP, HIGH);   //Read echo pin, time in microseconds
distance= duration*0.034/2;        //Calculating actual/real distance
if (distance >=20){
  myString = "Object is way to far"; 
}
else {
  myString = String(distance);
}

Serial.println(myString);
String push=led(value,val);
Serial.println(push);
String push1=led1(value1,val1);
Serial.println(push1);
String path = db + "/" + TimeNow + "/" + "Distance";
String path1 = db + "/" + TimeNow + "/" + "Status";
String path2 = db + "/" + TimeNow + "/" + "Picked";
Firebase.setString(path,myString);
Firebase.setString(path1,push);
Firebase.setString(path2,push1);


delay(500);
if(Firebase.failed()){
  Serial.print("Pushing failed");
  Serial.println(Firebase.error());
  return;
}                    //Pause for 3 seconds and start measuring distance again
}
