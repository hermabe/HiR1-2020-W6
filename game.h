#include "std_lib_facilities.h"

struct Player {
    string name;
    char symbol;
};

class TicTacToe {
private:
    array<Player, 2> players; // array er en vector med fast størrelse
    array<array<char, 3>, 3> board;

    void printBoard() const;
    bool isFull() const;
    bool hasWon(int row, int col) const;
    pair<int, int> getPlayerInput() const;
    bool isLegalCoordinate(int row, int col) const;
    bool playerTurn(const Player &player);

public:
    TicTacToe(const Player &first, const Player &second);
    void play();
};
