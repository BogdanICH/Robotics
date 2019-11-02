//Project made by Iordache Bogdan Mihai

//output for RGB led - digital pins
const int redPin = 11; 
const int bluePin = 10; 
const int greenPin = 9;

//input from potentiometer - analog pins
const int redPot = A0; 
const int greenPot = A1; 
const int bluePot = A2; 

//the value of the colors that will be changed during use
int redVal; 
int greenVal; 
int blueVal; 

//setup pins
void setup() { 
pinMode(redPin, OUTPUT);
pinMode(greenPin, OUTPUT);
pinMode(bluePin, OUTPUT);
pinMode(redPot, INPUT);
pinMode(bluePot, INPUT);
pinMode(greenPot, INPUT);
}

//main program
void loop() { 

//here I read the value from the potentiometers
redVal = analogRead(redPot); 
greenVal = analogRead(greenPot); 
blueVal = analogRead(bluePot); 


//here I map the value, because analogRead gives me value between 0 and 1023
//but the analogWrite wants value between 0 and 255
redVal = map(redVal, 0, 1023, 0, 255); 
greenVal = map(greenVal, 0, 1023, 0, 255); 
blueVal = map(blueVal, 0, 1023, 0, 255);

//here I give the value from potentiometers to RGB led
analogWrite(redPin, redVal); 
analogWrite(greenPin, greenVal); 
analogWrite(bluePin, blueVal); 
}
