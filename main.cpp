#include "std_lib_facilities.h"

#include "game.h"

int main()
{
	Player player1{"Alice", 'X'};
	Player player2{"Bob", 'O'};

	TicTacToe game(player1, player2);
	game.play();

	keep_window_open();
//------------------------------------------------------------------------------
}