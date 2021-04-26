#ifndef COMPUTER_PLAYER_H_INCLUDED
#define COMPUTER_PLAYER_H_INCLUDED
#include "Player.h"
#include <string>
class Computer_Player : public Player {
private:
    static char compName;
public:
    Computer_Player(uInt num);
};
char Computer_Player::compName = 'A';


#endif // COMPUTER_PLAYER_H_INCLUDED
