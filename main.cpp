#include <iostream>
#include <ctime>
#include <vector>
#include <cstdlib>
#include <unistd.h>
#include <fstream>
#include <limits>
#include "core.h"
#include "mode1.h"
#include "mode3.h"

using namespace std;

ifstream fin;

void opening() {
	system("clear");
	fin.open("story.txt");
	string line;
	cout<<"\033[1;36m";
	while (getline(fin, line))
	{
		cout<<line<<endl;
		sleep(2);   //disable it for faster testing
	}
	cout<<"\033[0m";
	fin.close();
}

int getValidMode() {
    int mode;
    while (true) {
        cout << "Enter the mode: ";
        if (cin >> mode) {
            if (mode == 1 || mode == 2 || mode == 3) {
                break;
            } else {
                cout << "No such mode!" << endl;
            }
        } else {
            cout << "Invalid input! Please enter an integer." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }
    return mode;
}

int getValidBoardSize() {
    int size;
    while (true) {
        cout << "Enter the size of the board (3-20): ";
        if (cin >> size) {
            if (size >= 3 && size <= 20) {
                break;
            } else {
                cout << "Invalid size! Please enter a size between 3 and 20." << endl;
            }
        } else {
            cout << "Invalid input! Please enter an integer." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }
    return size;
}

int main() {
	opening();
	cout<<endl;
	cout << "Mode 1: The game starts with a board size of 3 x 3. After completing it, the board size increases to 4 x 4, 5 x 5, and so on, gradually reaching up to 20 x 20." << endl;
	cout << "Mode 2: The board size is customized by entering the desired dimensions." << endl;
	cout << "Mode 3: The board size is randomly generated, and players have a limited number of moves to solve." << endl;
	int size, mode;
	cout << "Welcome to lightsout!" << endl;
	mode = getValidMode();
	if (mode == 1) {
		modeOne start1;
		start1.running();
	}
	if (mode == 2) {
		size = getValidBoardSize();
		bool status = true;
		cout<<"Turn all the X into O!"<<endl;
		LightsOut game(size, mode);
		game.play(mode, status, 0);
	}
	if (mode == 3) {
		int size = random_size_generator();
		LightsOutGame game(size);
		//int step = game.calculateSteps(std::vector<std::vector<int>>(size, std::vector<int>(size, 0)));
        	int steps = size*size;
		while (steps < 0) {
			size = random_size_generator();
			steps = game.calculateSteps(std::vector<std::vector<int>>(size, std::vector<int>(size, 0)));
		}
		LightsOutGame gameMode(size);
		gameMode.running(size, steps);
	}
}
