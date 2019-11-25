#include <LiquidCrystal.h>
#include <EEPROM.h>
// declare all the joystick pins
const int pinSW = 10; // digital pin connected to switch output
const int pinX = A1; // A1 - analog pin connected to X output
const int pinY = A0; // A0 - analog pin connected to Y output


// states of the button press
int swState = LOW;
int lastSwState = LOW;
int switchValue;
int xValue = 0;
int yValue = 0;
bool joyMoved = false;
int minThreshold= 400;
int maxThreshold= 600;

// variable for different functions
int digit = 1;
int openOp = 0;
int startingLevelValue = 0;
int lastStartingLevelValue = 0;
int level = 0;
int highScore = 0;
int highScoreAddress = 0;
int calScore = 0;
int count5s = 0;
int lastDigit = 0;

// variable for time
unsigned long previousMillis = 0;

// varibale for lcd display
const int RS = 12;
const int enable = 11;
const int d4 = 5;
const int d5 = 4;
const int d6 = 3;
const int d7 = 2;
LiquidCrystal lcd(RS, enable, d4, d5, d6, d7);

// here is a function for set the menu
void setMenu() {
  lcd.clear();
  lcd.setCursor(3, 0);
  lcd.print("Start Game");
  lcd.setCursor(1, 1);
  lcd.print("Settings");
  lcd.setCursor(11, 1);
  lcd.print("HighS");  
}

// this function delete the last >
void clearPosition() {
  lcd.setCursor(2, 0);
      lcd.print(" ");
  lcd.setCursor(10, 1);
      lcd.print(" ");   
  lcd.setCursor(0, 1);
      lcd.print(" ");        
}

// this is a function who set the variables for game and set the
// display for game, the key words
void setGame() {
  level = startingLevelValue;
  previousMillis = millis();
  calScore = 0;
  count5s = 0;
  lcd.setCursor(0, 0);
  lcd.print("Lives:3");
  lcd.setCursor(9, 0);
  lcd.print("Level:");
  lcd.setCursor(15, 0);
  lcd.print(startingLevelValue); 
  lcd.setCursor(5, 1);
  lcd.print("Score: ");
  lcd.setCursor(12, 1);
  lcd.print(level);

}
// -------------------------------- GAME -----------------------------
void startGame() {
  lcd.clear();
  setGame();
  // here I do a loop, while the button is pressed, the game is on
  for (int i = 1; i == openOption();) {
    unsigned long currentMillis = millis();
    // every 5 sec I increment the score and the level
    if (currentMillis - previousMillis >= 5000) {
         previousMillis = currentMillis;
         level += 1;
         lcd.setCursor(12, 1);
         calScore = level * 3; 
         lcd.print(calScore);
         lcd.setCursor(15, 0);
         lcd.print(level);     
         count5s++;
      }
      // after 10s, the game is over
      if (count5s == 2) {
         // here I will update the high score and I will write it in EEPROM
         if (calScore > highScore) {
             highScore = calScore;
             EEPROM.put(highScoreAddress, highScore);                
         }
         if (currentMillis - previousMillis >= 2000) {
            previousMillis = currentMillis;
            lcd.clear();

            // here I will show the Congrats message
            for (int i = 1; i == openOption();) {
                lcd.setCursor(0, 0);
                lcd.print("Congratulations!");
                unsigned long currentMillis = millis();

                if (currentMillis - previousMillis >= 3000) {
                    previousMillis = currentMillis;
                    lcd.clear();
                    
                    for (int i = 1; i == openOption();) {
                        lcd.setCursor(2, 0);
                        lcd.print("You finished");
                        lcd.setCursor(4, 1);
                        lcd.print("the game"); 
                        unsigned long currentMillis = millis();

                        // after 3 seconds, I tell the player how to get to the menu
                        if (currentMillis - previousMillis >= 3000) {
                            previousMillis = currentMillis;
                            lcd.clear();
                            
                            for (int i = 1; i == openOption();) {
                                lcd.setCursor(2, 0);
                                lcd.print("Press button");
                                lcd.setCursor(5, 1);
                                lcd.print("to exit");  
                                
                            }
                       }
                    }                   
                 }
              }
            }
         }      
    }
  setMenu();
}

// ----------------------------- Settings --------------------------------

void goToSettings() {
    lcd.clear();

    // whiele the button is pressed, I can choose the value for starting level
    for (int i = 1; i == openOption();) {
        yValue = analogRead(pinY);
        
        if (yValue < minThreshold && joyMoved == false) {
            if (startingLevelValue > 0) {
                startingLevelValue--;
            } else {
                startingLevelValue = 9;
            }
            joyMoved = true;
        }
  
        if (yValue > maxThreshold && joyMoved == false) {
            if (startingLevelValue < 9) {
                startingLevelValue++;
            } else {
                startingLevelValue = 0;
            }
            joyMoved = true;
        }
  
        if (yValue >= minThreshold && yValue <= maxThreshold) {
            joyMoved = false;
        }
        
        lcd.setCursor(0, 0);
        lcd.print("Starting Level");
        lcd.setCursor(6, 1);
        lcd.print(startingLevelValue);
        if (startingLevelValue > lastStartingLevelValue) {
            lastStartingLevelValue = startingLevelValue;
            highScore = 0;
            EEPROM.put(highScoreAddress, highScore);
        }
    }
    setMenu();
}

// ------------------------ High Score --------------------------
void goToHighScore() {
    lcd.clear();
    for (int i = 1; i == openOption();) {
        lcd.setCursor(2, 0);
        lcd.print("High Score");
        lcd.setCursor(7, 1);
        lcd.print(highScore);
    }
    setMenu();
}
// --------------------------------------------------------------

// in this function I change the state for button
int openOption() {
    swState = digitalRead(pinSW);
    if (swState !=  lastSwState) {
        if (swState == LOW) { 
            openOp = !openOp;
        }
    }
    lastSwState = swState;
    return openOp;
} 

// --------------- choose the option ----------------------
void chooseOption() {
    
    xValue = analogRead(pinX);
   
    if (xValue < minThreshold && joyMoved == false) {
        if (digit > 1) {
            digit--;
        } else {
            digit = 3;
        }
        joyMoved = true;
    }

    if (xValue > maxThreshold && joyMoved == false) {
        if (digit < 3) {
            digit++;
        } else {
            digit = 1;
        }
        joyMoved = true;
    } 
  
    if (xValue >= minThreshold && xValue <= maxThreshold) {
        joyMoved = false;
    }

    // if the > are in front of Start Game and button is pressed, I will start the game
    if (digit == 1) {
        if(digit != lastDigit) {
            clearPosition();
            lastDigit = digit;
        }
        lcd.setCursor(2, 0);
        lcd.print(">");
        Serial.println(openOp);
        if (openOption() == 1) {
            startGame();
        }  
    }
    // if the > are in front of Settings and button is pressed, I will go to settings
    if (digit == 2){
      if(digit != lastDigit) {
            clearPosition();
            lastDigit = digit;
        }
        lcd.setCursor(0, 1);
        lcd.print(">");
        Serial.println(openOp);
        if (openOption() == 1) {
            goToSettings();
        }   
    }
    // if the > are in front of High Score and button is pressed, I will show the high score
    if (digit == 3) {
        if(digit != lastDigit) {
            clearPosition();
            lastDigit = digit;
        }
        lcd.setCursor(10, 1);
        lcd.print(">"); 
        if (openOption() == 1) {
            
            goToHighScore();
        }
    }
}
//---------------------------------------------------------

//---------------- setup -----
void setup() {
    pinMode(pinSW, INPUT_PULLUP);
    lcd.begin(16, 2);
    Serial.begin(9600);
    setMenu();
    // here I will get the last highScore from eeprom memory
    EEPROM.get(highScoreAddress, highScore);
    
}

// ---------------- loop -----
void loop() {
  chooseOption();
}
