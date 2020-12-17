# Candy-Crush-Game
This is the game same like Candy Crush using the concepts of Object Oriented Programming (OOP) in C++.

The objective of project is to make a game in which Player swap one gem with an adjacent gemwith the help of mouse(Drag & Drop) to form only horizontal or vertical chain of three or moregems of the same color, (an idea of game can be taken from the screenshot given at end). Bonuspoints are given to player when chains of more than three identical gems are formed, but alsowhen two chains are formed in one swap. When chains are formed, the gems disappear, andgems fall from the top to fill in gaps. Sometimes chain reactions (referred to as cascades) aretriggered, where chains are formed by the falling gems. Cascades are awarded with bonus points.Be creative as you can in drawing gem and game board. Following features should be added to the game:
1)Take Name of player as input.
2)Drawing of game board in the start of game
3)You can match Rows and columns (No diagonal matches allowed)
4)There should be a Hint button, when the player clicks hint button, highlight the gems that canform a chain and the score & progress bar should be depleted.
5)Progress Bar should be displayed.
6)Next Level will require specific amount of points/coins.
7)A menu also be included optioning Levels, Level Modes, Highest scores and Settings etc.a)Levels include List of levels (completed levels should be displayed bright and incompletelevels be dark)0b)Level Modes include difficulty of level (at least two modes)i)Normal ModeIn Normal Mode, the player fills up the progress bar on the bottom of the screen by matchinggems. The game starts with an empty progress bar and the game will not ends in betweenlevel in this mode. When the progress bar is filled up completely, the player goes to the nextlevel. As the level progresses, more points are required to proceed to the next level. As theplayer levels up, they get more points by matching gems (example: Level 1= 100 pts., Level2= 150 pts. etc.).ii)Time Trial Mode In this mode, the gameplay mechanics are like Normal Mode, but the progress bar starts half-way filled. The player must keep the bar filled by matching gems, and they will level up byfilling the progress bar. The game ends if the progress bar is depleted completely.Note: Game difficulty will increase (means more points will be require for completing currentlevel), with the level increase.c)Highest Scores include top 4 highest scores, the player has achieved till thend)Settings will include Music and sound option, Player profile and How to Play options etc.
8)Game must include Play and Pause Button.
9)There should be at least 5 types of gems (max 8 gems), each gem will carry equal points.When four gems chain are formed, player gets bonus triple points (x3). When Player formsfive gems, points will be added 5 times more (x5).
10)Game Control will be Mouse only. While Play/Pause, Hint, Music On/Off, How to play,profile Buttons can be control using some keyboard keys (for example, H key for Hint) File Handling1)Player can resume game (after leaving midway). You need to store name and his current stateof game2)High scores will be stored in files with names.3)Player profile will also be stored in files. In player profile you need to store the name and hishighest level along with the game state of his highest level.
