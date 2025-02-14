# Tic Tac Toe Game

## Overview
This project is a console-based implementation of the classic Tic Tac Toe game in C++. It provides the following gameplay modes:

1. **Play against a basic AI (machine)**
2. **Play against a friend**
3. **Play against a machine with the Minimax algorithm** (to ensure optimal AI moves)

The game uses a numeric key mapping system for board positions, making it intuitive for players to input their moves.

------

## Features

### Game Modes
- **Play with Machine**: Face off against a simple AI.
- **Play with Friends**: Play against another player locally.
- **Play with Machine (Minimax Algorithm)**: Challenge a smarter AI that uses the Minimax algorithm for decision-making.

### Game Rules
- The game is played on a 3x3 grid.
- Players alternate turns, marking their symbol ('O' for Player 1 and 'X' for Player 2).
- The goal is to align three of your symbols horizontally, vertically, or diagonally.
- If the board is full without a winner, the game ends in a tie.

---

## How to Use

### Compile and Run
1. Ensure you have a C++ compiler installed (e.g., g++).
2. Save the code in a file named `tic_tac_toe.cpp`.
3. Compile the code using the following command:
   ```bash
   g++ tic_tac_toe.cpp -o tic_tac_toe
   ```
4. Run the program:
   ```bash
   ./tic_tac_toe
   ```

### Gameplay Instructions
1. **Choose a game mode** from the menu:
   - Enter `1` for playing against a basic AI.
   - Enter `2` for playing against a friend.
   - Enter `3` for playing against the AI with Minimax.

2. **Input your moves** by typing the number corresponding to the desired position on the key map (1-9).

3. The game will display the updated board after every turn and announce the winner or if it's a tie.

### Key Map
| Key | Board Position |
|-----|----------------|
|  1  | Top Left       |
|  2  | Top Center     |
|  3  | Top Right      |
|  4  | Middle Left    |
|  5  | Center         |
|  6  | Middle Right   |
|  7  | Bottom Left    |
|  8  | Bottom Center  |
|  9  | Bottom Right   |

---

## Code Structure

### Functions
- `printBoard()`: Displays the current game board along with the key map.
- `playerInput()`: Handles user input for Player 1.
- `machineInput()`: Implements the basic AI for the machine.
- `friendInput()`: Handles input for Player 2 in two-player mode.
- `refreshPage()`: Clears the screen to refresh the display.
- `resetGame()`: Resets the board and prepares the game for a new round.
- `checkWinner()`: Checks the board to determine if there's a winner or a tie.

### Global Variables
- `int board[9]`: Represents the 3x3 game board (0 for empty, 1 for Player 1, 2 for Player 2/AI).
- `int player`: Tracks the current player (1 or 2).

---

## Sample Output

### Menu
```
	 ********MENU********
	 SELECT 1 : PLAY WITH MACHINE
	 SELECT 2 : PLAY WITH FRIEND
	 SELECT 3 : PLAY WITH MACHINE (MIN MAX ALGO)
	 Enter your choice :
```

## Game Board
```
Game Board          Key Map
*************       *************
* O * X *   *       * 1 * 2 * 3 *
*************       *************
*   * O * X *       * 4 * 5 * 6 *
*************       *************
*   *   * O *       * 7 * 8 * 9 *
*************       *************
```

---

## Improvements
Future enhancements could include:
- A graphical user interface (GUI) for a more interactive experience.
- Online multiplayer support.
- Difficulty levels for the AI.

---

## Acknowledgments
This project demonstrates fundamental concepts of:
- Array manipulation
- Game logic
- Minimax algorithm
- User input handling in C++

