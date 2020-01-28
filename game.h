#include "std_lib_facilities.h"

struct Player {
    string name;
    char symbol;
};

class TicTacToe {
private:
    array<Player, 2> players;
    array<array<char, 3>, 3> board;

    void printBoard() const;
    bool isLegalCoordinate(int x, int y) const;
    bool isFull() const;
    bool hasWon(int x, int y) const;
    pair<int, int> getPlayerInput() const;
    bool playerTurn(const Player &player);

public:
    TicTacToe(const Player &first, const Player &second);
    void play();
};
