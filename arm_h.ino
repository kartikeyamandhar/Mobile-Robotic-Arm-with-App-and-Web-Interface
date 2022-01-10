#include <Servo.h>
Servo myservo1;
Servo myservo2;
Servo myservo3;
Servo myservo4;

String dataString="";
bool dataComplete=false;
String dataString1="";
bool dataComplete1=false;
String dataString2="";
String dataString3="";
String dataString4="";
int data=0;
int data1=0;
int data2=0;
int data3=0;

void setup(){
  Serial.begin(9600);
  myservo1.attach(9);
  myservo2.attach(6);
  myservo3.attach(3);
  myservo4.attach(11);
}
void loop(){
  if (dataComplete){
    data = dataString1.toInt();
    data1 = dataString2.toInt();
    data2 = dataString3.toInt();
    data3 = dataString4.toInt();
    
    task();
    dataString="";
    dataComplete=false;
    dataString2="";
    dataString3="";
    dataString4="";
    dataComplete1=false;
  }
}
void serialEvent(){
  while(Serial.available()){
    char inChar=(char)Serial.read();
    dataString+=inChar;
    
    if(inChar=='\n'){
      dataComplete=true;
    }
    if(dataString.endsWith("999")){
      dataString1=dataString.substring(0,dataString.length()-3);
     
    }else if(dataString.endsWith("666")){
      dataString2=dataString.substring(0,dataString.length()-3);
    }else if(dataString.endsWith("333")){
      dataString3=dataString.substring(0,dataString.length()-3);
    }else if(dataString.endsWith("111")){
      dataString4=dataString.substring(0,dataString.length()-3);
    }
  }
}
void task(){
  myservo1.write(data);
  myservo2.write(data1);
  myservo3.write(data2);
  myservo4.write(data3);
}
