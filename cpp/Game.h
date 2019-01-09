#ifndef GAME_H
#define GAME_H
#include <stdint.h>

#define HEIGHT 6
#define WIDTH 7
#define TOTAL HEIGHT*WIDTH

using namespace std;

class Game
{
public:
	Game();

	void printState();

	short play(short number);
	void nextPlayer();
	short CLI();
	short findWinner(short row, short column);
	bool findHorizontal(short row, short column);
	bool findVertical(short row, short column);
	bool findDiagDown(short row, short column);
	bool findDiagUp(short row, short column);
	void delete_last();


protected:

private:
	short rows[HEIGHT][WIDTH] = { 0 };
	short actions[TOTAL][2] = { 0 };
	short player = 1;
	short piecesPlayed = 0;
	short nextPos[WIDTH];
};

#endif // GAME_H
