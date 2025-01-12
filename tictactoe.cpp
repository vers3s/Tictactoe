#include <bits/stdc++.h>
using namespace std;

void printBoard();
void playerInput();
void machineInput();
void machineInputMinMax();
void friendInput();
void refreshPage();
void resetGame();
int checkWinner();

int board[9] = {0, 0, 0, 0, 0, 0, 0, 0, 0};
int player = 1;

int main() {
    int choice;
    while (choice != 4) {
        
        cout << "\t ********MENU********" << endl;
        cout << "\t SELECT 1 : PLAY WITH MACHINE (EASY)" << endl;
        cout << "\t SELECT 2 : PLAY WITH FRIEND" << endl;
        cout << "\t SELECT 3 : PLAY WITH MACHINE (HARD)" << endl;
        cout << "\t SELECT 4 : EXIT" << endl;
        cout << "\t Enter your choice :" << endl;
        cin >> choice;

        switch (choice) {
            case 1: {
                resetGame();
                while (true) {
                    refreshPage();
                    printBoard();
                    playerInput();
                    if (checkWinner() != 0) break;
                    refreshPage();
                    printBoard();
                    machineInput();
                    if (checkWinner() != 0) break;
                }
                refreshPage();
                printBoard();
                int winner = checkWinner();
                if (winner == 10) cout << "It's a tie!\n";
                else if (winner == player) cout << "You win!\n";
                else cout << "Machine wins!\n";
                break;
            }

            case 2: {
                resetGame();
                while (true) {
                    refreshPage();
                    printBoard();
                    friendInput();
                    if (checkWinner() != 0) break;
                }
                refreshPage();
                printBoard();
                int winner = checkWinner();
                if (winner == 10) cout << "It's a tie!\n";
                else cout << "Player " << winner << " wins!\n";
                break;
            }

            case 3: {
                resetGame();
                while (true) {
                    refreshPage();
                    printBoard();
                    playerInput();
                    if (checkWinner() != 0) break;
                    refreshPage();
                    printBoard();
                    machineInputMinMax();
                    if (checkWinner() != 0) break;
                }
                refreshPage();
                printBoard();
                int winner = checkWinner();
                if (winner == 10) cout << "It's a tie!\n";
                else if (winner == player) cout << "You win!\n";
                else cout << "Machine wins!\n";
                break;
            }
	case 4:{
		cout<<"EXITED, Goodbye...!!"<<endl;
		break;
		}
            default:
                cout << "Invalid choice. Please try again.\n";
                break;
        }
    }
    return 0;
}

void resetGame() {
    fill(begin(board), end(board), 0);
    player = 1; 
}

void refreshPage() {
    system("clear"); // For Unix/Linux systems. Replace with "cls" for Windows.
}

int checkWinner() {
    for (int i = 0; i < 3; i++) {
        if (board[i] != 0 && board[i] == board[i + 3] && board[i] == board[i + 6])
            return board[i];
        int row = i * 3;
        if (board[row] != 0 && board[row] == board[row + 1] && board[row] == board[row + 2])
            return board[row];
    }
    if (board[0] != 0 && board[0] == board[4] && board[0] == board[8])
        return board[0];
    if (board[2] != 0 && board[2] == board[4] && board[2] == board[6])
        return board[2];
    if (all_of(begin(board), end(board), [](int x) { return x != 0; }))
        return 10; // Tie
    return 0; // No winner
}

int minimax(int depth, bool isMaximizing) {
    int score = checkWinner();

    if (score == player) return -10; // Player's win
    if (score == (player == 1 ? 2 : 1)) return 10; // Machine's win
    if (score == 10) return 0; // Tie

    if (isMaximizing) {
        int bestScore = -1000;
        for (int i = 0; i < 9; i++) {
            if (board[i] == 0) {
                board[i] = (player == 1 ? 2 : 1);
                bestScore = max(bestScore, minimax(depth + 1, false));
                board[i] = 0;
            }
        }
        return bestScore;
    } else {
        int bestScore = 1000;
        for (int i = 0; i < 9; i++) {
            if (board[i] == 0) {
                board[i] = player;
                bestScore = min(bestScore, minimax(depth + 1, true));
                board[i] = 0;
            }
        }
        return bestScore;
    }
}

void machineInputMinMax() {
    int bestScore = -1000;
    int bestMove = -1;

    for (int i = 0; i < 9; i++) {
        if (board[i] == 0) {
            board[i] = (player == 1 ? 2 : 1); // Machine's move
            int score = minimax(0, false);
            board[i] = 0; // Undo move
            if (score > bestScore) {
                bestScore = score;
                bestMove = i;
            }
        }
    }

    if (bestMove != -1) {
        board[bestMove] = (player == 1 ? 2 : 1);
        cout << "Machine placed at position " << (bestMove + 1) << "\n";
    }
}

void machineInput() {
    int input = -1;
    for (int i = 0; i < 9; i++) {
        if (board[i] == 0) {
            board[i] = (player == 1 ? 2 : 1);
            if (checkWinner() == board[i]) {
                input = i;
                break;
            }
            board[i] = 0;
        }
    }
    if (input == -1) {
        for (int i = 0; i < 9; i++) {
            if (board[i] == 0) {
                input = i;
                break;
            }
        }
    }
    board[input] = (player == 1 ? 2 : 1);
    cout << "Machine placed at position " << (input + 1) << "\n";
}

void playerInput() {
    int input;
    do {
        cout << "Your turn. Enter a number (1-9): ";
        cin >> input;
        input--;
        if (input < 0 || input >= 9 || board[input] != 0)
            cout << "Invalid input. Try again.\n";
    } while (input < 0 || input >= 9 || board[input] != 0);
    board[input] = player;
}

void friendInput() {
    int input;
    do {
        cout << "Player " << player << "'s turn. Enter a number (1-9): ";
        cin >> input;
        input--;
        if (input < 0 || input >= 9 || board[input] != 0)
            cout << "Invalid input. Try again.\n";
    } while (input < 0 || input >= 9 || board[input] != 0);
    board[input] = player;
    player = (player == 1 ? 2 : 1); // Switch player
}

void printBoard() {
    char displayBoard[9];
    for (int i = 0; i < 9; i++)
        displayBoard[i] = (board[i] == 0) ? ' ' : (board[i] == 1) ? 'O' : 'X';

    cout << "Game Board          Key Map\n";
    cout << "*************       *************\n";
    cout << "* " << displayBoard[0] << " * " << displayBoard[1] << " * " << displayBoard[2] << " *       * 1 * 2 * 3 *\n";
    cout << "*************       *************\n";
    cout << "* " << displayBoard[3] << " * " << displayBoard[4] << " * " << displayBoard[5] << " *       * 4 * 5 * 6 *\n";
    cout << "*************       *************\n";
    cout << "* " << displayBoard[6] << " * " << displayBoard[7] << " * " << displayBoard[8] << " *       * 7 * 8 * 9 *\n";
    cout << "*************       *************\n";
}

