**Game: Lightsout**

Group 168

Team Members: 

•	He Zhiyue

•	Hsieh Tsz Hin

•	Huang Yu Tung

•	Hui Shuk Ying

•	Kong Yu Yuet

**Demo video :** https://youtu.be/7oOvwAudPyg?feature=shared

**Description:**

LightsOut is a puzzle game where the objective is to turn off (or on) all the lights on a grid. 

Each time a player toggles a light, its adjacent lights (the left one, the right one, the upper one, and the lower one) also change their state. 

The goal of the game is to turn off all the lights on a grid. 


**Game Rules:**

•	The game offers three different modes.

Mode 1: The game starts with a board size of 3 x 3. After completing the 3 x 3 Lights Out game, the board size progressively increases to 4 x 4, 5 x 5, and so on, gradually reaching 20 x 20.

Mode 2: The board size is customized by entering the desired dimensions (3 - 20).

Mode 3: The board size is randomly generated, and players have a limited number of moves to solve.

•	The number of steps taken by the player to solve the game is recorded. 

•	Choose your preferred mode, strategize your moves, and aim for the minimum number of steps to conquer the LightsOut game.

•  Input "q q" to leave the game

**Features Implemented:**

1.	Generation of random game sets or events:

•	Random board size

•	Random lights on / off at the start of the game

2.	Data structures for storing game status

•	Arrays are used throughout the program to store and manipulate data: game games, board size, and user inputs.

•	The vector<vector<bool>> data structure is used to represent the board. 

•	The 2D vector data structure is used to store and manipulate the game board's status and the state of each cell.

3.	Dynamic memory management

•	std::vector is used to store and manage the directions vector.

•	The calculateSteps function assigns the grid variable to a copy of the initial grid, and makes modifications during the breadth-first search.

4.	File input/output

•	The ifstream object, fin,  is used to open the file "story.txt". 
It reads the contents of the file line by line using getline.  
The fin.close() statement is used to close the file.

5.	Program codes in multiple files

•	The file core.h contains the core logic and functions for the game.

•	The file mode1.h and mode3.h handles the execution of mode 1 and mode 3 respectively.

•	Each of these files is included in the main program file (main.cpp)


Non-standard C/C++ libraries: 

<unistd.h>: The sleep() function creates a delay of 2 seconds between each line displayed.


**Compilation and execution instructions:**

To compile and execute the game, 

1.	Download the ZIP containing the files.
   
2.	Open a terminal and navigate to the directory where the code files are saved.
   
3.	Compile the code using a C++ compiler. Run the command ‘make’.
   
4.	Run the command './program’ to play the game.
