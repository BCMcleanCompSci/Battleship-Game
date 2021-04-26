#ifndef RANDOM_PLAYER_H_INCLUDED
#define RANDOM_PLAYER_H_INCLUDED
#include "Computer_Player.h"
#include <string>
class Random_Player : public Computer_Player {
public:
    Random_Player(uInt num):Computer_Player(num){}
    Move makeMove(Board &board);
};


#endif // RANDOM_PLAYER_H_INCLUDED
