#include "game.h"

TicTacToe::TicTacToe(const Player &first, const Player &second) : players{first, second} {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            board[i][j] = ' ';
        }
    }
}

void TicTacToe::printBoard() const {
    for (int i = 0; i < 3; i++) {
        cout << "+---+---+---+\n";
        for (int j = 0; j < 3; j++) {
            cout << "| " << board[i][j] << " ";
        }
        cout << "|\n";
    }
    cout << "+---+---+---+\n";
}

bool TicTacToe::isLegalCoordinate(int row, int col) const {
    if (row < 0 || row > 2 || col < 0 || col > 2) {
        return false;
    }
    return board[row][col] == ' ';
}

pair<int, int> TicTacToe::getPlayerInput() const {
    cout << "Enter row and column: ";
    int row, col;
    cin >> row >> col;
    while (!isLegalCoordinate(row, col)) {
        cout << "Invalid coordinates. Please enter again: ";
        cin >> row >> col;
    }
    return make_pair(row, col);
}

bool TicTacToe::hasWon(int row, int col) const {
    if (board[row][0] == board[row][1] && board[row][1] == board[row][2]) return true; // Row
    if (board[0][col] == board[1][col] && board[1][col] == board[2][col]) return true; // Column
    if (board[1][1] != ' ' && board[0][0] == board[1][1] && board[1][1] == board[2][2]) return true; // Diag
    return board[1][1] != ' ' && board[0][2] == board[1][1] && board[1][1] == board[2][0]; // Diag
}

bool TicTacToe::isFull() const {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == ' ') {
                return false;
            }
        }
    }
    return true;

}

bool TicTacToe::playerTurn(const Player& player) {
    cout << player.name << "s turn:\n";
    pair<int, int> input = getPlayerInput();
    board[input.first][input.second] = player.symbol;
    if (hasWon(input.first, input.second)) {
        cout << player.name << " has won!" << endl;
        return true;
    }
    return false;
}

void TicTacToe::play() {
    int playerIndex = 0;
    while (!isFull()) {
        printBoard();
        if (playerTurn(players[playerIndex])) {
            return;
        }
        playerIndex = (playerIndex + 1) % 2;
    }
    cout << "Draw!" << endl;
}
