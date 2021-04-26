/*Project 2 Brad McLean 0103571
The majority of this header is as stated in the project.
2 member varables have been added to keep a count of the damage of the ships
2 funtions have been added to pass information to the Game class.
Okayed by Chris*/

#ifndef BOARD_H_INCLUDED
#define BOARD_H_INCLUDED

typedef unsigned int uInt;
typedef struct {char collumn; uInt row;}Move;
enum class PlayerPiece {AIRCRAFT, BATTLESHIP, CRUISER, SUBMARINE, PATROL, EMPTY};
enum class EnemyPiece {HIT, MISS, EMPTY};

class Board {
public:
    Board(){reset();}
    void reset()noexcept;
    void display(uInt player) noexcept;
    EnemyPiece makeMove(const Move &m, uInt player);
    bool isLegal(const Move &m, uInt player);
    bool isFinished();
    uInt winner();
private:
    EnemyPiece p1Attacks[100];
    PlayerPiece p1Ships[100];
    EnemyPiece p2Attacks[100];
    PlayerPiece p2Ships[100];
    uInt p1Count;
    uInt p2Count;
};


#endif // BOARD_H_INCLUDED
