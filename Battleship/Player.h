#ifndef PLAYER_H_INCLUDED
#define PLAYER_H_INCLUDED
#include <iostream>
#include <string>
#include "Board.h"

using namespace std;
class Player {
    string playerName;
    uInt pNumber;

public:
    Player(const string &name,uInt num){playerName = name;pNumber=num;}
    virtual Move makeMove(Board &board) = 0;
    string getPlayerName(){return playerName;}
    uInt getPlayerNumber(){return pNumber;}
};


#endif // PLAYER_H_INCLUDED
