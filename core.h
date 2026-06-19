#include <iostream>
#include <ctime>
#include <vector>
#include <cstdlib>
#include <limits>
#include <cctype>
#include "mode3.h"
#ifndef CORE_H
#define CORE_H

using namespace std;

class LightsOut {
private:
    int boardsize;
    vector<vector<bool>> board;// use 2D vector to represent the chessboard

public:
    void displayboard() {
        if (boardsize <= 9) {              // print column numbers
			cout << "  ";
			for (int j = 0; j < boardsize; ++j) {
	        		cout << j + 1 << " ";
	       		}
		} else {
			cout << "   ";
	    		for (int j = 0; j < boardsize; ++j) {
				if (j < 9) {
	        			cout << "0" << j + 1 << " ";
	       			} else {
		     			cout << j + 1 << " ";
				}
	    		}
		}

		cout << endl;
        	// Print row numbers and board state
		for (int i = 0; i < boardsize; ++i) {
	    		if (boardsize > 9) {
				if (i < 9) {
					cout << " " << i + 1 << " ";
				} else {
					cout << i + 1 << " ";
				}
				for (int j = 0; j < boardsize; ++j) {
		     			if (board[i][j]) {
						cout << "\033[31mX \033[0m "; // Print "X" in red
		     			} else {
						cout << "\033[34mO \033[0m "; // Print "O" in blue
		     			}
	    			}
	    		} else {
				cout << i + 1 << " ";                   // print row number
				for (int j = 0; j < boardsize; ++j) {
					if (board[i][j]) {
			    			cout << "\033[31mX \033[0m"; // Print "X" in red
					} else {
				    		cout << "\033[34mO \033[0m"; // Print "O" in blue
					}
				}
			}
			cout << endl;       // change line
	    		
		}
    	}

    void change_light(int row, int col) {
        if (row >= 0 && row < boardsize && col >= 0 && col < boardsize) {
            board[row][col] = !board[row][col];
        }
    }

    void change_cell(int row, int col) {
        change_light(row, col);
        change_light(row - 1, col);
        change_light(row + 1, col);
        change_light(row, col - 1);
        change_light(row, col + 1);
    }

    void gen_board() { // generating the initial state
        int move = boardsize * boardsize / 2; // only half of the grids will be lit
        for (int i = 0; i < move; ++i) {
            int row = rand() % boardsize;
            int col = rand() % boardsize;
            change_cell(row, col);
        }
    }

    bool solved() {
        for (int i = 0; i < boardsize; ++i) {
            for (int j = 0; j < boardsize; ++j) {
                if (board[i][j]) {
                    return false;
                }
            }
        }
        return true; // if all the cells are false(=X=light off), return false
    }

    void clearScreen() {
        if (system("clear")) // Linux and macOS
            system("cls");   // Windows
    }

    void recordSteps(int &n) {
        n += 1;
    }

public:
    LightsOut(int size, int mode) : boardsize(size), board(size, vector<bool>(size, false)) {
        // : is used for member initialization
        // assign boardsize=size
        //initialize a 2D vector with each elements initialized to false(=0=light off)
        // LightsOut here is a constructor which will be automatically called when an object of the class LightsOut is created.
        srand(time(0)); // sets the seed for the random number generator using the current time
        // random numbers generated each time for the initial board state are different.
        gen_board();
    }
    
    void play(int mode, bool& status, int steps) {
        int num = 0;
	string r,c;
	clearScreen();
        while (!solved()) { //if all lights are off, solved()=false and !solved()=true
            if (mode == 1) {
                cout << "Level " << boardsize - 2 << endl;
                cout << endl;
            }
            displayboard();
	    cout << "steps: " << num << endl;
	    if (mode == 3) {
	    	cout << "Your steps limitation: " << steps << endl;
		if (num == steps) {
			cout << "Oops! You went out of steps~ Bye~" << endl;
			status = false;
			return;
		}
	    }

            cout << "Enter the row and column of the X/O to change it: ";
	    cin >> r >> c;
            recordSteps(num);
	    if (r == "q" || r == "Q" || c == "q" || c == "Q") {
		break;
	    }
	    int row = stoi(r);
	    int col = stoi(c);
            while (row < 1 || row > boardsize || col < 1 || col > boardsize) {
                cout << "Invalid input! Please enter row and column as integers within the board size." << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Enter the row and column of the X/O to change it: ";
		cin >> r >> c;
		if (r == "q" || r == "Q" || c == "q" || c == "Q") {
			break;
	    	} 
		row = stoi(r);
	    	col = stoi(c);
            }
            change_cell(row - 1, col - 1);
            clearScreen();
        }
	if (r == "q" || r == "Q" || c == "q" || c == "Q") {
	    cout << "Byebye~ See you next time!" << endl;
	    status = false;
	    return;
	}
        cout << "Congratulations! You won!" << endl;
    }
};


#endif
