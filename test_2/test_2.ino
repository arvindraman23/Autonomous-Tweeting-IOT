#include <ESP8266WiFi.h>
#include <ESP.h>
#include <DNSServer.h>
#include <ESP8266WebServer.h>
#include <WiFiManager.h>

int incomingByte = 0;   // for incoming serial data
int pinPin = 2;
String thingtweetAPIKey = "H2BDFUJP5MZQ4LF2";
String msg="";
String msg1="I am arya";
String tsData="";
WiFiClient client;

void setup() {
        Serial.begin(115200);     // opens serial port, sets data rate to 9600 bps
        pinMode(pinPin, OUTPUT);
        WiFiManager wifiManager;
         String ap_name = "Prism"+String(ESP.getChipId())+"AP";
        wifiManager.autoConnect(ap_name.c_str());
}

void loop() {

       /* // send data only when you receive data:
        if (Serial.available() > 0) {
                // read the incoming byte:
                
                msg = Serial.readString();
                msg.trim();
                if(msg == "BCD"){
                  digitalWrite(pinPin, LOW);
                  delay(3000);
                  digitalWrite(pinPin, HIGH);
                }
                */
                tsData = "api_key="+thingtweetAPIKey+"&status="+msg1;

                Serial.printf("\n[Connecting to ... just-dustbin.herokuapp.com");
                if (client.connect("api.thingspeak.com", 80)) {
                  Serial.println("connected]");
                  Serial.println("[Sending a request]");
                  client.print(String("POST /apps/thingtweet/1/statuses/update HTTP/1.1\r\n") +
                             "Host: api.thingspeak.com \r\n" +
                             "Connection: close\r\n" +
                             "Content-Type: application/x-www-form-urlencoded\r\n" +
                             "Content-Length:"+tsData.length()+"\r\n" +
                             "api_key: H2BDFUJP5MZQ4LF2&status=I am Arya\r\n" +
                             "\r\n"
                            );
                  Serial.println("[Response:]");
                   while(client.connected()) {
                    if (client.available()) {
                      String line = client.readStringUntil('\n');
                        Serial.println(line);
                      }
                    }
                  }
                  client.stop();
                  Serial.println("\n[Disconnected]");
                // say what you got:
                Serial.print("I received: ");
                Serial.print(msg);
               delay(4000);
       // }
}
 

