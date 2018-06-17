
#include<SoftwareSerial.h>
#include<stdlib.h>
#include<dht.h>

#define DHT11_PIN 7

dht DHT;

int ledPin=13;
int ledAlert=8;
int tempAlarm = 25 ; 
String apiKey="LAW1ILC67XHZS698";
SoftwareSerial ser(10,11);
 
void setup() {
  // put your setup code here, to run once:
  pinMode(ledPin,OUTPUT);
  pinMode(ledAlert,OUTPUT);
  Serial.begin(115200);u
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(ledPin,HIGH);
  delay(200);
  digitalWrite(ledPin,LOW);
  
  int val=0;
  val=DHT.read11(DHT11_PIN);
  delay(500);

  Serial.print("Temperature in C= ");
  Serial.print(DHT.temperature);
  Serial.print(" *C Temperature in F= ");
  Serial.print((1.8*DHT.temperature)+32);
  Serial.print(" F  Humidity = ");
  Serial.print(DHT.humidity);
  Serial.println(" %");

  if(DHT.temperature > tempAlarm){
    digitalWrite(ledAlert,HIGH);
  }else{
    digitalWrite(ledAlert,LOW);
  }
  String cmd="AT+CIPSTART=\"TCP\",\"";
  cmd+="184.106.153.149";
  cmd+="\",80";
  ser.println(cmd);

  if(ser.find("Error")){
    Serial.println("AT+CIPSTART error");
    return;
  }
  int t =(1.8*DHT.temperature)+32;
  String getStr="GET /update?api_key=";
  getStr+=apiKey;
  getStr+="&field1=";
  getStr+=String(DHT.temperature);
  getStr+="&field2=";
  getStr+=String(DHT.humidity);
  getStr+="&field3=";
  getStr+=String(t);
  getStr+="\r\n\r\n";

  //send data length
  cmd="AT+CIPSEND=";
  cmd+=String(getStr.length());
  ser.println(cmd);

  if(ser.find(">")){
    ser.print(getStr);
  }
  else{
    ser.println("AT+CIPCLOSE");
    Serial.println("AT+CIPCLOSE");
  }

  delay(16000);
}
