FRUIT CATCHER - C CONSOLE GAME
Fruit Catcher is a fun and interactive console-based game written in C, where the player controls a basket to catch falling fruits. The game demonstrates real-time input handling, collision detection, and dynamic speed control using basic programming concepts.

Gameplay
Fruits fall from the top of the screen 🍎
Move the basket left and right to catch them 🧺
Each catch increases your score
Missing a fruit ends the game 💀
Game speed increases as your score grows ⚡

Controls
Press A - Move Left  
Press D - Move Right 

Features
Real-time keyboard input
Smooth console animation
Collision detection
Score tracking system
Increasing difficulty (speed scaling)

Concepts Used
Loops (while) for continuous gameplay
Functions (draw, input, logic) for modular code
Conditional statements (if-else) for game rules
Random number generation (rand()) for fruit placement

How It Works
The screen is redrawn continuously to simulate movement
User input moves the basket
Fruit falls step-by-step
Collision is checked:
    If caught → score increases
    If missed → game over

How to run
Using GCC:
gcc game.c -o game
./game

Using CodeBlocks / Dev C++:
Open the file
Click Run

