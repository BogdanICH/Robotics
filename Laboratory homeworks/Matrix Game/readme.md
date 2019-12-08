Name of the project: Syfe

Description: 

- Menu:
  - Play game(on LCD during the game will be displayed score, time, level)
  - High score(will be displayed the best high score for every level)
  - Settings(where you can set the level for the game and leave the feedback with a note)
  - Info(creator name, github link, game name, Unibuc Robotics)

- Start game: 
    - you will be placed in the upper left corner and you will have to reach the opposite corner without dropping too many bombs
    - for 5 seconds, all the bombs on the map will be displayed, so remember where they are planted(you can't move in this 5 seconds)
    - depending on the level, the number of bombs on the map will increase, and the game will become harder,
  and you can enter a maximum of 1 bomb, so you have just one extra life
    - when the game starts(after that 5 seconds), you will have 20 seconds to finish the game
    -here is a schema(level 1): https://imgur.com/SIkAOj7
  
 - The levels:
    - there are 3 levels, and each level has 5 bombs in addition to the one in front
        - level 1: 10 bombs
        - level 2: 15 bombs
        - level 3: 20 bombs
     - you can set the level from the settings
     
- The RGB led:
    - if you are one step away from a bomb, the LED will be red
    - if you are two steps away from a bomb, the LED will be yellow
    - if you are three steps away from a bomb, the LED will be green
   
 - The score:
    - in order to make a high score, you must go through as many boxes and 
    as few bombs as possible until you reach the bottom right corner
    - you will receive a point on each box
    - you can't get a point on a box you already walked, so each one is unique
    
 - The bombs: 
    - if you step on a bomb, you will lose 5 points or if you have less points than 5, your score will be 0
    - when you hit a bomb, all the others will be displayed for 3 seconds and then disappear
    - when you hit a bomb, you can't move for that 3 seconds
    - you can hit only one bomb and the next one will be the end of the game

How it meets all the technical requirements from Requirements:
  - I will use: 8x8 LED matrix, LCD, Joystick, MAX7219 Driver, RGB led, arduino board, breadboards
  - I have:
    - levels
    - time pressure
    - lives
    - high score in EEPROM
    - Play game
    - Settings(where you can set the level for the game and leave the feedback with a note)
    - High Score(saved in EEPROM, I will save 3 high score, meaning one for each level, inital is 0)
    - Info(creator name, github link, game name, Unibuc Robotics)
    - on LCD: score, time, level
    - Congratulations message in the end
 
In conclusion, the game meets all the requirements.
