#include <iostream>
#include <string>
#include <stdlib.h>
#include "Game.h"
using namespace std;

Game::Game(){
    p1 = nullptr;
    p2 = nullptr;

}

Game::~Game(){}


void Game::selectPlayers(){
    char select;
    string name;
    for (uInt i = 1; i < 3; ++i){
        cout << "Select player " << i << ". H for human or C for computer:";
        cin >> select;
        if (select=='H'){
            cout << "Player " << i <<", Enter your name: ";
            cin >> name;
            cout << endl;
            if (i == 1)
                p1 = new Human_Player(name,i);
            else p2 = new Human_Player(name,i);
        }else {
            if (i ==1)
                p1 = new Random_Player(i);
            else p2 = new Random_Player(i);
        }
    }
}

Player* Game::nextPlayer(Player *current) const{
    if (current->getPlayerNumber()==1){
        return p2;
    }else return p1;
}

void Game::play(){
    selectPlayers();
    Player *currentPlayer = p1;
    while (isRunning()){
        uInt playerNum = currentPlayer->getPlayerNumber();
        string playerName = currentPlayer->getPlayerName();
        gameBoard.display(playerNum);
        Move m = currentPlayer->makeMove(gameBoard);
        gameBoard.makeMove(m,playerNum);
        currentPlayer = nextPlayer(currentPlayer);
        getchar();
        getchar();
        system("CLS");
    }

}
void Game::announceWinner(){
    if (gameBoard.winner() == 1)
        cout << p1->getPlayerName() << ", you have won!!!!";
    else cout << p2->getPlayerName() << ", you have won!!!";
}

bool Game::isRunning(){
    return !gameBoard.isFinished();
}


