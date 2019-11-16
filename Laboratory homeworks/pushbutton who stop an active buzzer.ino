// set the active buzzer to play a soud
const int buzzerPin = 11;
int buzzerTone = 500;

// set the pasiv buzzer
const int speakerPin = A0;
int speakerValue = 0;
unsigned int startTime = 0;
unsigned int currentTime = 0; 
int startCount = 0;
int startCalculate = 0;
int startSound = 0;
int continue = 1;

// set the threshold for knocker
const int threshold = 1;

// set the pushbutton
const int pushButton = 2;
int buttonState = 0;

// set the pins
void setup() {
  pinMode(buzzerPin, OUTPUT);
  pinMode(pushButton, INPUT);
  Serial.begin(9600);
}

// main program
void loop() {
  // read the knock
  speakerValue = analogRead(speakerPin);
  
  // verify if is a knock there and if is, print "knock" and tell the program its time to count 5 seconds
  if (speakerValue > threshold) {
    Serial.println("Knock");
    startCount = 1;
  }
  // if the pushbutton it wasn't press, we continue and set the start time
  if (continue == 1){
    if (startCount == 1) {
        startTime = millis();
        startCount = 0;
        startCalculate = 1;
    }
  }
  // I take the current time
  currentTime = millis();
  
  // here I calculate that 5 seconds and if it pass 5 second, play the sound
  if (startCalculate == 1){
      if(currentTime - startTime >= 5000) {
          startTime = currentTime;
          startSound = 1;
      }
      if (startSound == 1){
          tone(buzzerPin, buzzerTone, 100);
          } 
    }
  
  // here I verify if the pushbutton was pressed
  buttonState = digitalRead(pushButton);
  if (buttonState == 1) {
      startCalculate = 0;
      continue = 0;
  }
}
