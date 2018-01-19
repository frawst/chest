int ledPin = 13;
int blinkRate = 50;
int minBlinkRate = 50;
int maxBlinkRate = 250;
int iterDir = 1;
void setup() {
  // put your setup code here, to run once:
  pinMode(ledPin, OUTPUT);
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {
  if (blinkRate >= maxBlinkRate){
    iterDir = iterDir * -1;
    blinkRate = maxBlinkRate - 1;
  }
  else if ( blinkRate <= minBlinkRate ){
    iterDir = iterDir * -1;
    blinkRate = minBlinkRate + 1;
  }
  else{
    blinkRate += (25 * iterDir);
  }
  // put your main code here, to run repeatedly:
  digitalWrite(LED_BUILTIN, HIGH);
  delay(blinkRate);
  digitalWrite(LED_BUILTIN, LOW);
  delay(blinkRate);
 
}
