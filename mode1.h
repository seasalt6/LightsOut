#include <iostream>
#include <ctime>
#include <vector>
#include <cstdlib>
#ifndef MODE1_H
#define MODE1_H
#include "core.h"

using namespace std;

class modeOne {

public:
    void running() {
	bool status = true;
        for (int n = 3; n < 21; ++n) {
            int mode = 1;
            cout << "Turn all the X into O!" << endl;
            LightsOut game(n, mode);
            game.play(mode, status, 0);
	    if (status == false) {
		break;
            }
            game.clearScreen();
        }
    }
};

int mode1() {
    modeOne gameMode;
    gameMode.running();

    return 0;
}
#endif 
