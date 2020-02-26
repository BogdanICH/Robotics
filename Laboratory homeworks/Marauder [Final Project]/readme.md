# Marauder
*inspired by real life*

<br>


> War time <br>

From here we start, from the coolest event, the war, the one who can be our apocalypse, the one we are all afraid of and for times like these there are people who are thinking of solutions to diminish their power, people like me and my solution is **Marauder** adapted, explained below.

<br>

> The story <br>

The story begins with a city on the globe that wants to start a war and owns nuclear bombs, but the people who want to prevent the war have created a spy car that lands in the city with bombs and collects them in secret.
The operation takes place at night, while the enemies sleep, the spy car will walk through the enemy city and try to find the bombs. When a bomb is found, the car will collect it and continue its search.
Because the city is patrolled at night, the car when it hears the sound of soldiers, will slow down.

<br>

                                                       Let's save the world!
                                                                                
                                                                                
/////////////////////////// ![alt text](https://i.ibb.co/6WJT58v/4.jpg) ///////////////////////////
                                                                                
                                                                                
<br>

## 'How to play' instructions
 - First of all, the car must be placed in a place with walls and after that, the start button that is located on one of the middle poles of the car must be pressed.
 - After the car has been started, it will control itself, not needing another human intervention.
 - The car will stop when it collects all 3 bombs whose existence is known.

                                         
## How the robot works
After the car has been placed in a walled space and the start button has been pressed, it will rotate 360 degrees trying to determine the shortest distance between it and the surrounding objects. After the rotation ends, the car will do one more rotation in which it will try to determine the nearest object based on the distance calculated at the previous point. The second rotation of the car will be done when the object corresponding to the distance found at the first rotation is found.<br>

Immediately after the nearest object has been found, the car will go towards it, up to a distance of maximum 6cm (distance measured with the second sensor that has a range of 4 - 30cm) and will determine its color(with color sensor), and in case the object is red, the arm of the car will start up, it will descend and it will take the red object, after which it will put it in its warehouse.

> While the car is operating, in case it hears a sound, the speed will be with 25% lower.

In case the color is not red or if the red object has been raised, the car will go back until it has a safe distance from the object in front, after which it will move to the right until it finds an object with a distance between it and car less than 50cm (distance measured with the first sensor that has a range of 20 - 150cm). When such an object is found, the car will go forward to a maximum distance of 6 cm and repeat the previous description.

> It is good to know that if the distance between an object and the car is > 25cm, this distance will be calculated with the first sensor(long range) and if the distance is < 25cm, it will be calculated with the second sensor(short range).

The car will stop when it collects all 3 bombs supposed to be on the map.

<br>

- Here is the  [BOM sheet](https://docs.google.com/spreadsheets/d/1Htry010sDG5Vxl1XxuDkIDsEU6a6pIBbHVVmY9l-o_E/edit#gid=1410515179) where you can see what materials I used in my project.
- Here you can find the [video](https://www.youtube.com/watch?v=KrSa0eRxCjA) with my project in action.
