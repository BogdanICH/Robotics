///// active buzzer 
const int buzzerPin = 11;
int buzzerTone = 500;
//////////////////////////////
const int speakerPin = A0;
int speakerValue = 0;
int knockTime = 0;
unsigned int lastDebounceTime = 0;
unsigned int currentTime = 0; 
int ok = 0;
int okk = 0;
int okkk = 0;
int o = 1;
// set the sensitivity
const int threshold = 1;

const int pushButton = 2;
int buttonState = 0;

void setup() {
  pinMode(buzzerPin, OUTPUT);
  pinMode(pushButton, INPUT);
  Serial.begin(9600);
}
void loop() {
  speakerValue = analogRead(speakerPin);
  
    
  if (speakerValue > threshold) {
    Serial.println("Knock");
    ok = 1;   
  }
  currentTime = millis();
  if (o == 1){
    if (ok == 1){
    lastDebounceTime = millis();
    ok = 0;
    okk = 1;
    }
  }
  
  if (okk == 1){
      if(currentTime - lastDebounceTime >= 5000) {
        lastDebounceTime = currentTime;
        okkk = 1;}
       if (okkk == 1){
       tone(buzzerPin, buzzerTone, 100);
       //buzzerTone += 100;
      } 
    }
    buttonState = digitalRead(pushButton);
  if (buttonState == 1)
    {okk = 0;
    o = 0;}
}
