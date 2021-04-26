#include <iostream>
#include "Human_Player.h"
using namespace std;


Move Human_Player::makeMove (Board &b){
    char col;
    uInt row;
    cout << getPlayerName() << ", enter a valid attack!!";
    cin >> col >> row;
    col = toupper(col);
    Move m {col,row};
    if(b.isLegal(m,getPlayerNumber())){
        return m;
    } else exit(-1);
}
