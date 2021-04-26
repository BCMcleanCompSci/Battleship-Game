#include <iostream>
#include <random>
#include "Random_Player.h"
using namespace std;

Move Random_Player::makeMove(Board &board){
    std::random_device device;
    std::mt19937 twister (device());
    std::uniform_int_distribution<uInt> range(0,99);
    uInt index = range(twister);
    cout << index;
    getchar();
    char coll = 'A' + index%10;
    uInt row = index/10;
    Move m{coll,row};
    return m;
}
