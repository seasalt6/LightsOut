#ifndef MODE3_H
#define MODE3_H

#include <iostream>
#include <queue>
#include <vector>
#include <random>
#include "core.h"

using namespace std;

class LightsOutGame {

public:
	LightsOutGame(int size);
	int calculateSteps(const vector<vector<int>>& initialGrid);
	void toggleCell(int& cell);
	void toggleNeighbors(vector<vector<int>>& grid, int row, int col);
	bool isGridSolved(const vector<vector<int>>& grid);

	void running(int size, int steps) {
		cout << "Turn all the X into O!" << endl;
		bool status = true;
		int mode = 3;
		int n = size;
		LightsOut game(n, mode);
		game.play(mode, status, steps);
	}

private:
	
	int size; // Size of the Lights Out grid
};

int random_size_generator();

int mode3();

#endif  // MODE3_H
