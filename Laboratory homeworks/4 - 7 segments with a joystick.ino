// here I declare the pins for joystick
const int pinSW = 0; // digital pin connected to switch output
const int pinX = A0; // A1 - analog pin connected to X output
const int pinY = A1; // A0 - analog pin connected to Y output

// here I declare the pins for the 4 - 7 segments
const int pinA = 9;
const int pinB = 2;
const int pinC = 3;
const int pinD = 5;
const int pinE = 6;
const int pinF = 8;
const int pinG = 7;
const int pinDP = 4;
const int pinD1 = 10;
const int pinD2 = 11;
const int pinD3 = 12;
const int pinD4 = 13;
const int segSize = 8;

// this are the number of displays and number of digits
const int noOfDigits = 10;
const int noOfDisplays = 4;

// initialize the digits and locked and set the min and max treshold
int digit1 = 0;
int digit2 = 0;
int digit3 = 0;
int digit4 = 0;
int locked = HIGH;
int minThreshold = 400;
int maxThreshold = 600;

// set the joystick
int swstate = LOW;
int lastSwState = LOW;
int index = 0;
int xValue = 0;
int yValue = 0;
bool joyMovedx = false;
bool joyMovedy = false;

int segments[segSize] = {
  pinA, pinB, pinC, pinD, pinE, pinF, pinG, pinDP
};

int displays[noOfDisplays] = {
  pinD1, pinD2, pinD3, pinD4
};

int digits[noOfDisplays] = {
  digit1, digit2, digit3, digit4
};

byte digitMatrix[noOfDigits][segSize - 1] = {
  // a b c d e f g
  {1, 1, 1, 1, 1, 1, 0}, // 0
  {0, 1, 1, 0, 0, 0, 0}, // 1
  {1, 1, 0, 1, 1, 0, 1}, // 2
  {1, 1, 1, 1, 0, 0, 1}, // 3
  {0, 1, 1, 0, 0, 1, 1}, // 4
  {1, 0, 1, 1, 0, 1, 1}, // 5
  {1, 0, 1, 1, 1, 1, 1}, // 6
  {1, 1, 1, 0, 0, 0, 0}, // 7
  {1, 1, 1, 1, 1, 1, 1}, // 8
  {1, 1, 1, 1, 0, 1, 1}  // 9 
};

// function for display a number
void displayNumber(byte digit, byte decimalpoint) {
  for(int i = 0; i < segSize - 1; i++) {
    digitalWrite(segments[i], digitMatrix[digit][i]);
  }

  digitalWrite(segments[segSize - 1], decimalpoint);
}

// function for select a digit
void showDigit(int index) {
  for (int i = 0; i < noOfDisplays; i++) {
    digitalWrite(displays[i], HIGH);
  }
  digitalWrite(displays[index], LOW);
}


void setup() {
 for (int i = 0; i < segSize; i++) {
    pinMode(segments[i], OUTPUT);
  }
  for (int i = 0; i < noOfDisplays; i++) {
    pinMode(displays[i], OUTPUT);
  }
  pinMode(pinSW, INPUT_PULLUP);
  Serial.begin(9600);
}

void loop() {
  
   swstate = digitalRead(pinSW);
   if (swstate !=  lastSwState) {
      if (swstate == LOW) {
          locked = !locked;
      }
    }
   lastSwState = swstate;

  // here I choose the display from that 4
   if(locked == HIGH){
     xValue = analogRead(pinX);

     if (xValue < minThreshold && joyMovedx == false) {
      if (index > 0) {
          index--;
      } 
      else {
          index = 3;
      }
      joyMovedx = true;
    }
    
    if (xValue > maxThreshold && joyMovedx == false) {
      if (index < 3) {
          index++;
      } 
      else {
          index = 0;
      }
      joyMovedx = true;
    }
    if (xValue >= minThreshold && xValue <= maxThreshold) {
      joyMovedx = false;
    }
  }


  // here I choose the number for display index
  if (locked == LOW){
    yValue = analogRead(pinY);
    
    if (yValue < minThreshold && joyMovedy == false) {
      if (digits[index] > 0) {
          digits[index]--;
      }
      else {
          digits[index] = 9;
      }
      
      joyMovedy = true;
    }
    
    if (yValue > maxThreshold && joyMovedy == false) {
     if (digits[index] < 9) {
          digits[index]++;
      } 
      else {
          digits[index] = 0;
      }
      joyMovedy = true;
    }
  
    if (yValue >= minThreshold && yValue <= maxThreshold) {
      joyMovedy = false;
    }
  }
  
  // here I keep the numbers on displays
  for(int i = 0; i < noOfDisplays; i++) {
    showDigit(i);
    displayNumber(digits[i], HIGH);
    if (i == index) {
      digitalWrite(segments[segSize - 1], HIGH);
    }
    else digitalWrite(segments[segSize - 1], LOW);
    delay(5);
  }
  
}
