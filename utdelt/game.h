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
    // Oppgavene må deklareres her

public:
    // Oppgavene må deklareres her
};
