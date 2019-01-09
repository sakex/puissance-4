#ifndef SIMULATION_H
#define SIMULATION_H
#include <vector>
#include <stdint.h>

constexpr int NOSCORE = -500000;

struct Move {
	short number;
	int score;
	vector<Move> children;
	Move * parent;
};

class Simulation
{
public:
	Simulation();
	virtual ~Simulation();

	void random_game();
	void start_random(int _count);
	void print_tree(int depth);
	void train();
	short sim_CLI();

protected:

private:
	Move moves;

	static void move_cursor(Move ** cursor, short _move);
	int train_scores(Move * _move);
};

#endif // SIMULATION_H