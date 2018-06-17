int LedPin=13;
int LedPin2 = 12;

int switchPin = 5;

int WaitTime=500;

void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(LedPin, OUTPUT);
  pinMode(LedPin2,OUTPUT);
  pinMode(switchPin,INPUT);
  
}

// the loop function runs over and over again forever
void loop() {
  
  int val = digitalRead(switchPin);
  if(val == HIGH){
     digitalWrite(LedPin, HIGH);
  }
  else{
     digitalWrite(LedPin, LOW); 
  }
  /*
  digitalWrite(LedPin, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(WaitTime);                       // wait for a second
  digitalWrite(LedPin, LOW);    // turn the LED off by making the voltage LOW                      // wait for a second
  digitalWrite(LedPin2, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(WaitTime);                       // wait for a second
  digitalWrite(LedPin2, LOW);    // turn the LED off by making the voltage LOW
                         // wait for a second
   */
}
