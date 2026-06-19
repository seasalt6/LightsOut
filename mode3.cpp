#include "mode3.h"

using namespace std;

LightsOutGame::LightsOutGame(int size) : size(size) {}

void LightsOutGame::toggleCell(int& cell) {
    cell = !cell;
}

void LightsOutGame::toggleNeighbors(vector<vector<int>>& grid, int row, int col) {
    static const vector<pair<int, int>> directions = {{0, 0}, {0, -1}, {0, 1}, {-1, 0}, {1, 0}};

    for (const auto& dir : directions) {
        int newRow = row + dir.first;
        int newCol = col + dir.second;

        if (newRow >= 0 && newRow < size && newCol >= 0 && newCol < size) {
            toggleCell(grid[newRow][newCol]);
        }
    }
}

bool LightsOutGame::isGridSolved(const vector<vector<int>>& grid) {
    for (const auto& row : grid) {
        for (int cell : row) {
            if (cell != 0) {
                return false;
            }
        }
    }
    return true;
}

int LightsOutGame::calculateSteps(const vector<vector<int>>& initialGrid) {
    vector<vector<int>> grid = initialGrid;
    queue<pair<vector<vector<int>>, int>> q;
    q.push({grid, 0});

    while (!q.empty()) {
        grid = q.front().first;
        int steps = q.front().second;
        q.pop();

        if (isGridSolved(grid)) {
            return steps;
        }

        for (int row = 0; row < size; ++row) {
            for (int col = 0; col < size; ++col) {
                toggleNeighbors(grid, row, col);
                q.push({grid, steps + 1});
                toggleNeighbors(grid, row, col); // Restore the grid for the next iteration
            }
        }
    }

    return -1; // If no solution is found
}


int random_size_generator() {
	random_device rd;
	mt19937 generator(rd());

	uniform_int_distribution<int> distribution(3, 20);
	int randomsize = distribution(generator);
	return randomsize;
}

int mode3() {
	int size = random_size_generator();
	LightsOutGame game(size);
	//int step = game.calculateSteps(std::vector<std::vector<int>>(size, std::vector<int>(size, 0)));
        int steps = size*size;
	while (steps < 0) {
                size = random_size_generator();
                LightsOutGame game(size);
                steps = game.calculateSteps(std::vector<std::vector<int>>(size, std::vector<int>(size, 0)));
	 }
	LightsOutGame gameMode(size);
	gameMode.running(size, steps);
	
	return 0;
}
