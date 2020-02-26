#include <ColorSensor.h> // built by me
#include <AFMotor.h>
#include <SharpIR.h>
#include <Servo.h>

// Define pins for distance sensors
#define IR1 A0  // define signal pin
#define model1 20150
#define IR2 A5 // define signal pin
#define model2 430

SharpIR disS1(IR1, model1);
SharpIR disS2(IR2, model2);

//DC motor 1 and 2
AF_DCMotor motor1(1);
AF_DCMotor motor2(3);

//Servo that I use
Servo servo1;
Servo servo2;

//This is a class for color sensor
ColorSensor cS(3, 7, 2, 6, 13);

// Sound Sensor
const int soundSensor = A2;

// Push button pin
const int pushButton = A1;

// Variables
unsigned long previousMillis = 0;
int buttonState = 0;
int allBombsUp = 0;
int initState = 0;
int start = 0;
int found = 0;


// If the sensor hear some sound, the speed of the motors will decrease with 25%
int checkSound(int mySpeed) {
  if(digitalRead(soundSensor) == 1) {
    return (mySpeed*75)100;
  } else {
    return mySpeed;  
  }
}

// A function with which I can control fast the speed and the direction of my dc motors
void fastSetDC(int speed1, uint8_t where1, int speed2, uint8_t where2) {
   motor1.setSpeed(checkSound(speed1));
   motor1.run(where1);
   motor2.setSpeed(checkSound(speed2));
   motor2.run(where2); 
}

// A function with which I can run the motors in every direction for a specify time
void setDCMotors(int speed1, uint8_t where1, int speed2, uint8_t where2, int how) {
      motor1.setSpeed(checkSound(speed1));
      motor1.run(where1);
      motor2.setSpeed(checkSound(speed2));
      motor2.run(where2);
      delay(how);
      motor1.setSpeed(checkSound(speed1));
      motor1.run(RELEASE);
      motor2.setSpeed(checkSound(speed2));
      motor2.run(RELEASE);
}

// A function used for 
void wheelsDirection(uint8_t where1, uint8_t where2) {
  if (disS2.distance() < 13) {
     while (disS2.distance() < 13) {
       fastSetDC(120, BACKWARD, 120, BACKWARD);
     }
     fastSetDC(150, RELEASE, 150, RELEASE);
  }
  setDCMotors(50, where1, 50, where2, 300);
}

// A function which will be executed only once at the beginning to make sure that behind the car there is space for turning
void initt() {
   // If I have enough space in front of the car, who not to go a bit in front to make sure that we will have space behind the car
   if ((disS1.distance() > 29) && (initState == 0)) {
      setDCMotors(150, FORWARD, 150, FORWARD, 1000);
      initState++;
  }
  start = 1;
}

// A function where the car will make a 360 rotation and it will descover the most near object
void checkObjects() {
  // If the distance is less than 10 cm, the rotation will not be on anymore
  if (disS2.distance() > 10) {
      if (initState == 1) {
          int minim  = 130;
          int i = 0;
    
          // The car will rotate like 11 times to make sure that this is a 360 rotation
          while (i != 11) {
            int dis = disS1.distance();
            if (dis < 25) { 
               dis = disS2.distance();
            }
           
            if (dis < minim) {
                minim = dis;
            }
            
            unsigned long currentMillis = millis();
            
            // Between every rotation, I will wait 800 s for distance sensor to calculate the distance
            if (currentMillis - previousMillis >= 800) {
                previousMillis = currentMillis;
                setDCMotors(170, FORWARD, 170, BACKWARD, 300);
                setDCMotors(150, RELEASE, 200, RELEASE, 300);
                i++;
            }
           }
           initState++;
           previousMillis = 0;
           
      } else if (initState == 2){
           // Here will search for the minim distance
           int dis = disS1.distance();
           if (dis < 25) { 
              dis = disS2.distance();
           }
           
           unsigned long currentMillis = millis();
           
           if (currentMillis - previousMillis >= 800) {
              previousMillis = currentMillis;
              if (dis > (minim-3) && dis < (minim + 3)) {
                 found = 1;
                 start = 1;
                 initState++;
                 setDCMotors(150, RELEASE, 200, RELEASE, 1000);
              } else {
                 setDCMotors(170, FORWARD, 170, BACKWARD, 300);
                 setDCMotors(150, RELEASE, 150, RELEASE, 300);
              }
          }
      }
  }
}

// A function that controls servo motors and with it, I can take red objects in front of the car
void takeIt() {
  // First arm down
  for (int i = 160; i != 45; i--) {
      servo2.write(i);
      delay(10);
  }
    
   delay(1000);

   // Second arm, catch the object
   for (int i = 45; i < 180; i++) {
       servo1.write(i);
       delay(10);
   }
 
   delay(1000);

   // First arm, go to the first position
   for (int i = 45; i != 160; i++) {
       servo2.write(i);
       delay(10);
   }
    
   delay(1000);

   // Leave the object in the car
   for (i = 180; i != 45; i--) {
       servo1.write(i);
       delay(10);
   }
   delay(1000);
   allBombsUp++;
}

// This is the main function with which I'm looking for red objects
void searchForIt() { 
  // If the object is to far away, check for a new one
  if (disS1.distance() > 50) {
     wheelsDirection(FORWARD, BACKWARD);   
  } else {
    // If I found one, go for it (with first sensor 20 - 150 cm range)
    if (disS1.distance() > 25 && disS1.distance() < 50) {
         fastSetDC(15, FORWARD, 15, FORWARD);
    } else {
        fastSetDC(15, RELEASE, 15, RELEASE);
        
        // If the distance is less than 25, I will work with second distance sensor 4 - 30 cm range)
        if (disS2.distance() > 6 && disS2.distance() < 25) {
              fastSetDC(80, FORWARD, 80, FORWARD);
        } else {
            fastSetDC(20, RELEASE, 20, RELEASE);      
            //now let's check for the color, because if the color of the object is red, I will take it, if not, go and search for another one
            if (cS.getColor() == 1) {
                takeIt();  
            } else {
                wheelsDirection(FORWARD, BACKWARD);
            } 
        }
     }
  }   
}

// Setup function
void setup() {
  Serial.begin(9600);
  cS.PinSetup();
  
  pinMode(pushButton, INPUT_PULLUP);
  
  // turn on motors
  motor1.setSpeed(50);
  motor1.run(RELEASE);
  motor2.setSpeed(50);
  motor2.run(RELEASE);
  servo1.attach(9);
  servo1.write(45);
  servo2.attach(10);
  servo2.write(160);
}

// Loop function
void loop() {
  if (allBombsUp < 3) {
      buttonState = digitalRead(pushButton);
      
      // If the button was presed, the car starts searching
      if (buttonState == 0) {
         initt();
         checkObjects(); 
      }
    
      // Keep searching until the car found the neareast object
      if(initState == 2) {
        checkObjects();  
      }
    
      // The car starts to searching for red objects 
      if (start == 1) {
         searchForIt();
      }  
  }
}
