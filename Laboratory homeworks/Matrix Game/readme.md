Name of the project: Syfe

Story:
We are in evening of the Christmas, outside is beautiful, snow everywhere in the world, but in some places nakes with bombs.
Are missions is to create a safe way for Santa, from his home to world childrens.

                                                  Let's save the Christmas!


Description: 
  In the first 2 second, on the lcd display will be displayed a Welcome message and after that the menu will be shown
  
- Menu(You can go through the menu using the joysttick. In front of the option you will have a ">" and if you want to select it, just press the button of the joystick):
  - Play (on LCD during the game will be displayed score, time, level and lives)
  - High score(will be displayed the high score for every level(1, 2, 3))
  - Settings(where you can set the level for the game and leave the feedback with a note)
  - Info(creator name, game name, github link, @Unibuc Robotics)

- The game:
    - before the game, a map with bombs will be choose random
    - for 5 seconds, all the bombs(the number depends by level) on the map will be displayed, so remember where they are planted(you can't move in this 5 seconds)
    - after these 5 seconds, you will be placed in the upper left corner and you will have to reach the opposite corner without dropping too many bombs
    - depending on the level, the number of bombs on the map will increase, and the game will become harder,
and you can enter a maximum of 1 bomb, so you have just one extra life
    - if you hit a bomb, you will lose 5 points from score and for 3 seconds the rest of the bombs will be displayed(you can't move in this 3 seconds)
    - when the game starts(after that 5 seconds), you will have 20 seconds to finish the game
    - here is a schema(for level 1): https://imgur.com/SIkAOj7 (it's also in Matrix Game folder)
  
 - The levels:
    - there are 3 levels, and each level has 5 bombs in addition to the one in front
        - level 1: 10 bombs
        - level 2: 15 bombs
        - level 3: 20 bombs
     - you can set the level from the settings
     
 - The feedback:
    - in settings you can give feedback to the game from 1 to 5
     
- The RGB led:
    - if you are one step away from a bomb, the LED will be red
    - if you are two steps away from a bomb or more, the LED will be green
    
 - The distance sensor:
    - because the light of rgb led is pretty strong, the distance sensor will comput the distance from the game to you and 
if you are to close of it, the led will be turn off, so you have to stay a little bit away of the game to see the light
   
 - The score:
    - in order to make a high score, you must go through as many boxes and 
    as few bombs as possible until you reach the bottom right corner
    - you will receive a point on each box
    - you can't get a point on a box you already walked, so each one is unique
    - if you step on a bomb, you will lose 5 points or if you have less points than 5, your score will be 0
    - in the end of the game, the remaining seconds will be transformed in points(5 seconds remaining, 5 points add to final score)
    - high score for each level will be stored in EEPROM
    
 - End of the game:
    - at the end of the game, will be display a "Congratulations" message and "You made a new high score" only if the player maked
    - after this messages, on LCD display will be shown final score and number of seconds he used on top of LCD and 
in bottom will be Play again and Menu with a ">" in front(you can choose with the joystick what you want)

Video link: https://youtu.be/ZYHMe5cUwU4

How it meets all the technical requirements from Requirements:
  - I will use: 8x8 LED matrix, LCD display, Joystick, MAX7219 Driver, RGB led, arduino board, breadboards, distance sensor, potentiometer, wires, resistors, electrolytic capacitor of 10 μF, ceramic capacitor of 104 pF
  - I have:
    - levels
    - time pressure
    - lives
    - high score in EEPROM(3, one for each level)
    - Play (on LCD during the game will be displayed score, time, level and lives)
    - Settings(where you can set the level for the game and leave the feedback with a note)
    - High Score(saved in EEPROM, I will save 3 high score, meaning one for each level, inital is 0)
    - Info(creator name, github link, game name, @UnibucRobotics)
    - Welcome in the begining and congratulations message in the end of each game + "You made a new high score", if they do
 
In conclusion, the game meets all the requirements.
