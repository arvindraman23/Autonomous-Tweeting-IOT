
#include<dht.h>

dht DHT;

#define DHT11_PIN 7
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}


void loop() {
  // put your main code here, to run repeatedly:
  int chk = DHT.read11(DHT11_PIN);
  Serial.print("Temperature = ");
  Serial.print(DHT.temperature);
  Serial.print(" *C        Humidity = ");
  Serial.print(DHT.humidity);
  Serial.println(" %");
  delay(2000);
}
