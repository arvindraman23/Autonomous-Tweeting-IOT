String inputString="";
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
pinMode(13,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(Serial.available())
  {
    while(Serial.available())
    {
      char inChar = (char)Serial.read();
      inputString+=inChar;
    }
    Serial.println(inputString);
    if(inputString=="a"){
      digitalWrite(13,HIGH);
    }
    else if(inputString=="b"){
      digitalWrite(13,LOW);
    }
    inputString="";
  }
}
