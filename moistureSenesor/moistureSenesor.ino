

int moistureRead = 0;
int moistureValue = 0;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:

  moistureValue = analogRead(moistureRead);
  Serial.print(moistureValue);
  Serial.println();
  delay(1000);
}
