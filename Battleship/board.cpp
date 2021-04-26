#include "Board.h"
#include <iostream>
using namespace std;

//Hardcodes the ship positions and resets the damage count to 17 for each player
void Board::reset()noexcept{
    p1Count = 17;
    p2Count = 17;
    for (uInt i = 0; i < 100;++i){
        this->p1Attacks[i]=EnemyPiece::EMPTY;
        this->p2Attacks[i]=EnemyPiece::EMPTY;
        this->p1Ships[i]=PlayerPiece::EMPTY;
        this->p2Ships[i]=PlayerPiece::EMPTY;
    }
    for (uInt i = 0; i < 5; ++i){
        this->p1Ships[10 + i]=PlayerPiece::AIRCRAFT;
        this->p2Ships[10 + i]=PlayerPiece::AIRCRAFT;
    }
    for (uInt i = 0; i < 4; ++i){
        this->p1Ships[30 + i]=PlayerPiece::BATTLESHIP;
        this->p2Ships[30 + i]=PlayerPiece::BATTLESHIP;
    }
    for (uInt i = 0; i < 3; ++i){
        this->p1Ships[50 + i]=PlayerPiece::CRUISER;
        this->p2Ships[50 + i]=PlayerPiece::CRUISER;
    }
    for (uInt i = 0; i < 3; ++i){
        this->p1Ships[70 + i]=PlayerPiece::SUBMARINE;
        this->p2Ships[70 + i]=PlayerPiece::SUBMARINE;
    }
    for (uInt i = 0; i < 2; ++i){
        this->p1Ships[90 + i]=PlayerPiece::PATROL;
        this->p2Ships[90 + i]=PlayerPiece::PATROL;
    }
}


    EnemyPiece Board::makeMove(const Move &m, uInt player){
        uInt index = (m.row-1)*10 + (toupper(m.collumn) - 'A');
        EnemyPiece *attack;
        PlayerPiece *ships;
        uInt *playNumber;
        if (player == 1){
            attack = this->p1Attacks;
            ships = this->p2Ships;
            playNumber = &p1Count;
        }else{
            attack = this->p2Attacks;
            ships = this->p1Ships;
            playNumber = &p2Count;
        }
        if (ships[index]==PlayerPiece::EMPTY){
            cout << "SPLOOOSH. It's a MISS."<<endl;
            attack[index]=EnemyPiece::MISS;
            return attack[index];
        }else{
            cout << "KABEWM!!! It's a HIT!!!!!!"<< endl << endl;
            attack[index]=EnemyPiece::HIT;
            ships[index]=PlayerPiece::EMPTY;
            *playNumber -= 1;
            return attack[index];
        }
    }


void Board::display(uInt player) noexcept{
//Decide which boards to display bassed on player turn.
    EnemyPiece *attack;
    PlayerPiece *ship;
    if (player == 1){
        attack = this->p1Attacks;
        ship = this->p1Ships;
    }
    else {
        attack = this->p2Attacks;
        ship = this->p2Ships;
    }
    uInt index;
    //Create enemy attack board
    cout << "YOUR ATTACKS!!"<<endl;
    for (uInt i = 0; i<10; ++i){
       cout << "\t" << (char)('A'+i) ;
    }
       cout << "\n";
    for (uInt i = 0; i<10; ++i){
        cout << i+1;
        for (uInt j = 0; j<10; ++j){
            index = i*10 + j;
            cout << "\t";

            switch (attack[index]){
            case EnemyPiece::HIT:
                cout << "H";
                break;
            case EnemyPiece::MISS:
                cout << "M";
                break;
            default:
                cout << ".";
            }
        }
        cout << "\n";
        }
        cout << endl;
        //Create player ship board
        cout << "YOUR SHIPS!!" << endl;
        for (uInt i = 0; i<10; ++i){
            cout << "\t" << (char)('A'+i);
        }
        cout << "\n";
        for (uInt i = 0; i<10; ++i){
        cout << i+1;
        for (uInt j = 0; j<10; ++j){
            index = i*10 + j;
            cout << "\t";

            switch (ship[index]){
            case PlayerPiece::AIRCRAFT:
                cout << "A";
                break;
            case PlayerPiece::BATTLESHIP:
                cout << "B";
                break;
            case PlayerPiece::CRUISER:
                cout << "C";
                break;
            case PlayerPiece::SUBMARINE:
                cout << "S";
                break;
            case PlayerPiece::PATROL:
                cout << "P";
                break;
            default:
                cout << ".";
            }
        }
        cout << "\n";
        }
        cout << endl;
}
bool Board::isLegal(const Move &m, uInt player){
    uInt index = (m.row-1)*10 + (toupper(m.collumn) - 'A');
    if (m.collumn < 'A' || m.collumn > 'J')
        return false;
    if (index < 0 || index > 99)
        return false;
    EnemyPiece *attack;
    if (player == 1)
        attack = p1Attacks;
    else
        attack = p2Attacks;
    if (attack[index]!=EnemyPiece::EMPTY)
        return false;
    else return true;
}

bool Board::isFinished(){
    if(p1Count == 0 || p2Count == 0)
        return true;
    else return false;
}

uInt Board::winner(){
    if (p1Count==0)
        return 1;
    else return 2;
}
