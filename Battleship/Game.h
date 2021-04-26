#ifndef GAME_H_INCLUDED
#define GAME_H_INCLUDED
#include "Board.h"
#include "Human_Player.h"
#include "Random_Player.h"

using namespace std;

class Game{
public:
    Game();
    ~Game();
    void selectPlayers();
    Player* nextPlayer(Player *current) const;
    void play();
    void announceWinner();
    bool isRunning();

private:
    Player *p1;
    Player *p2;
    Board gameBoard;
};


#endif // GAME_H_INCLUDED
