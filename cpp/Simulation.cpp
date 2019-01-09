#include <stdlib.h>
#include <time.h>
#include <iostream>
#include "Game.h"
#include "Simulation.h"
#include "AI.h"

Simulation::Simulation()
{
	vector<Move> vec(WIDTH);
	for (int i = 0; i < WIDTH; i++) {
		vec.push_back(Move());
	}

	moves.number = -1;
	moves.score = NOSCORE;
	moves.children = vec;
	moves.parent = NULL;
}

Simulation::~Simulation()
{
	//dtor
}

void Simulation::move_cursor(Move ** cursor, short _move) {
	short number = (*cursor)->children[_move - 1].number;
	if (number != NULL && number != 0) {
		(*cursor) = &((*cursor)->children[_move - 1]);
	}
	else {
		vector<Move> vec(WIDTH);

		Move newIndex = {
			_move,
			NOSCORE,
			vec,
			*cursor
		};

		(*cursor)->children[_move - 1] = newIndex;
		*cursor = &((*cursor)->children[_move - 1]);
	}
}

void Simulation::random_game() {
	Game * game = new Game();
	short _move, row, winner, number;
	Move * index;
	index = &moves;
	bool finishedColumns[WIDTH] = { false };
	while (true) {
		_move = rand() % WIDTH + 1;
		while (finishedColumns[_move - 1]) {
			_move--;
			if (_move < 1)
				_move = WIDTH;
		}
		row = game->play(_move);
		if (row == -1) {
			finishedColumns[_move - 1] = true;
		}
		winner = game->findWinner(row, _move);
		if (winner) {
			int score;
			switch (winner) {
				case 1:
					score = 1;
					break;
				case 2:
					score = -1;
					break;
				case -1:
					score = 0;
					break;
			}
			index->score = score;
			delete game;
			return;
		}
		game->nextPlayer();
		//move_cursor(&index, _move);
		
		number = index->children[_move - 1].number;
		if (number != NULL && number != 0) {
			index = &(index->children[_move - 1]);
		}
		else {
			vector<Move> vec(WIDTH);

			Move newIndex = {
				_move,
				NOSCORE,
				vec,
				index
			};

			index->children[_move - 1] = newIndex;
			index = &(index->children[_move - 1]);
		}
	}
}

void recursive_print(Move _move, int depth) {
	depth--;
	cout << "{number: " << _move.number
		<< ", score: " << _move.score << ", children: [";
	if (depth > 0) {
		for (vector<Move>::iterator it = _move.children.begin();
			it != _move.children.end(); ++it) {
			if (it->number != NULL) {
				recursive_print(*it, depth);
			}
		}
	}
	cout << "]}, ";
}

void Simulation::print_tree(int depth) {
	cout << "[";
	for (int i = 0; i < WIDTH; ++i) {
		recursive_print(moves.children[i], depth);
	}
	cout << "]" << endl;
}

void Simulation::start_random(int _count) {
	srand(time(NULL));
	for (int i = 0; i < _count; ++i) {
		random_game();
		if (i % 100 == 0)
			cout << i << endl;
	}
}

int Simulation::train_scores(Move * _move) {
	if (_move->score != NOSCORE)
		return _move->score;
	else {
		int score = 0;
		for (int it = 0; it < WIDTH; ++it) {
			if (_move->children[it].number != NULL) {
				score += train_scores(&(_move->children[it]));
			}
		}
		_move->score = score;
		return score;
	}
}

void Simulation::train() {
	train_scores(&moves);
}

short Simulation::sim_CLI() {
	Game * game = new Game();
	bool MARKOV = false;
	int it;
	Move * index;
	Move * temp;
	index = &moves;
	short _move, turn, winner;
	while (true) {
		temp = NULL;
		if (!MARKOV) {
			//Select Higgest score from trained data
			for (it = 0; it < WIDTH; ++it) {
				if (index->children[it].number != NULL) {
					if (temp == NULL) {
						temp = &(index->children[it]);
					}
					else if (index->children[it].score > temp->score) {
						temp = &(index->children[it]);
					}
				}
			}
		}
		cout << endl;
		if (temp == NULL){
			//We ran out of known data, we use deep search
			_move = AI::MDP(game, 8);
		}
		else {
			_move = temp->number;
			index = temp;
		}
		turn = game->play(_move);
		winner = game->findWinner(turn, _move);
		if (winner)
			return winner;
		game->nextPlayer();
		game->printState();
		cout << endl;
		cin >> _move;
		//read input as short
		turn = game->play(_move);
		winner = game->findWinner(turn, _move);
		game->nextPlayer();
		if (winner)
			return winner;
		if (!MARKOV) {
			index = &(index->children[_move - 1]);
			if (index->number == NULL)
				MARKOV = true;
		}
	}
}