#include "Game.h"
#include <iostream>

using namespace std;

Game::Game()
{
	fill_n(nextPos, WIDTH, 5);
}


void Game::printState() {
	for (short i = 0; i < HEIGHT; ++i) {
		for (short j = 0; j < WIDTH; ++j) {
			char * endStr;
			if (j == HEIGHT)
				endStr = "\n";
			else
				endStr = ", ";
			cout << unsigned(rows[i][j]) << endStr << flush;
		}
	}
}

short Game::play(short number) {
	number--;
	if (number > HEIGHT || number < 0)
		return -1;
	short next = nextPos[number];
	if (next != -1) {
		rows[next][number] = player;
		actions[piecesPlayed][0] = next;
		actions[piecesPlayed][1] = number;
		piecesPlayed++;
		nextPos[number]--;
		return next;
	}
	return -1;
}

void Game::nextPlayer() {
	player = (player == 1) ? 2 : 1;
}

bool Game::findVertical(short row, short column) {
	// we never need to go up because
	short vertical = 1;

	//down
	short i = row;
	while (true) {
		++i;
		if (i <= 5 && rows[i][column] == player) {
			vertical++;
		}
		else
			break;
	}

	return vertical >= 4;
}

bool Game::findHorizontal(short row, short column) {
	short horizontal = 1;
	//LEFT
	short i = column;
	while (true) {
		--i;
		if (i >= 0 && rows[row][i] == player) {
			horizontal++;
		}
		else
			break;
	}
	//RIGHT
	i = column;
	while (true) {
		++i;
		if (i <= HEIGHT && rows[row][i] == player) {
			horizontal++;
		}
		else
			break;
	}

	return horizontal >= 4;
}

bool Game::findDiagDown(short row, short column) {
	//DIAG GOING DOWN FROM THE LEFT
	//DIAG UP LEFT
	short diagDown = 1,
		i = row,
		j = column;
	while (true) {
		--i;
		--j;
		if (i >= 0 && j >= 0 && rows[i][j] == player)
			diagDown++;
		else
			break;
	}
	//DIAG DOWN RIGHT
	i = row;
	j = column;
	while (true) {
		++i;
		++j;
		if (i <= 5 && j <= HEIGHT && rows[i][j] == player)
			diagDown++;
		else
			break;
	}
	return diagDown >= 4;
}

bool Game::findDiagUp(short row, short column) {
	//DIAG GOING UP FROM THE LEFT
	//DIAG UP RIGHT
	short diagUp = 1,
		i = row,
		j = column;
	while (true) {
		--i;
		++j;
		if (i >= 0 && j <= HEIGHT && rows[i][j] == player)
			diagUp++;
		else
			break;
	}
	//DIAG DOWN LEFT
	i = row;
	j = column;
	while (true) {
		++i;
		--j;
		if (i <= 5 && j >= 0 && rows[i][j] == player)
			diagUp++;
		else
			break;
	}
	return diagUp >= 4;
}

short Game::findWinner(short row, short column) {
	//repetitive but no way around
	if (piecesPlayed < HEIGHT)
		return 0;
	column--;
	bool cond = findHorizontal(row, column);
	if (cond)
		return player;
	cond = findVertical(row, column);
	if (cond)
		return player;
	cond = findDiagDown(row, column);
	if (cond)
		return player;
	cond = findDiagUp(row, column);
	if (cond)
		return player;
	if (piecesPlayed == 42)
		return -1;
	return 0;
}

short Game::CLI() {
	short pos;
	while (true) {
		cout << "Player " << player << ": " << endl;
		cin >> pos;
		short turn = play(pos);
		if (turn > -1) {
			printState();
			short winner = findWinner(turn, pos);
			if (winner) {
				return winner;
			}
			nextPlayer();
		}
	}
}


void Game::delete_last() {
	if (piecesPlayed > 0) {
		piecesPlayed--;
		short * action = actions[piecesPlayed];
		rows[action[0]][action[1]] = 0;
		nextPos[action[1]]++;
		nextPlayer();
	}
}