

int pin2 = 2;
int pin3 = 9;
 
 
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  
   pinMode(pin2,OUTPUT);
   pinMode(pin3,OUTPUT);
 
}
 
void loop() {
  // put your main code here, to run repeatedly:
 
  if(Serial.available()){
      int ser =0;
      int val=0;
      Serial.println("Called");
      do{
        ser = Serial.read();
        
        if(ser!=-1)
        { 
          val= (val*10)+(ser-48);
        }
        
      }while(ser !=-1);
      
      Serial.println(val);
      triggerPin(val);
    }
}
 
void triggerPin(int pin){
  if(pin<=13 && pin>=0){
    digitalWrite(pin,HIGH);
    delay(1000);
    digitalWrite(pin,LOW);
    delay(1000);
  }
 
}
