# battleship_in_c
Battleship game made in C

# Introduction
Once in my IT classes, when we were learning some programming logic, my teatcher asked us to make a battleship game using a pseudocode called Portugol.
Now, in the University I decided to put my memory and skills in work, to make another battleship game, but now, in C language.
Check out some other infos about the project bellow.

# Battleship rules
Before entering any deeper in the code, It's pretty important to understand the rules of the game, wich are:

- You and your enemy need to place some ships in a 10x10 grid;
- The ships change depending on what version your playing, but for this project I used this Ships:

  qt | type | size |
  --- | --- | --- | 
  5 | destroyiers | 2
  4 | submarines | 3 | 
  3 | cruiser | 3 | 
  2 | battleship | 4 |
  1 | carrier | 5 |
- After that, you need to guess where your enenmy's ships are;
- If you get it right you keep guessing, otherwise its enemy turn;
- The winner is who guess all the ships first.