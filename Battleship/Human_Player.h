#ifndef HUMAN_PLAYER_H_INCLUDED
#define HUMAN_PLAYER_H_INCLUDED
#include "Player.h"
#include <string>


class Human_Player : public Player {
public:
    Human_Player(const string &name, uInt num): Player(name,num){};
    Move makeMove (Board &b);

};


#endif // HUMAN_PLAYER_H_INCLUDED
