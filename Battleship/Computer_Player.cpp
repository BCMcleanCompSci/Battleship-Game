#include "Computer_Player.h"

    Computer_Player::Computer_Player(uInt num):Player("Computer " + compName,num){
        if (compName == 'Z')
            compName = 'A';
        else ++compName;
}
