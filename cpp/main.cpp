#include <iostream>
#include "Game.h"
#include "Simulation.h"

using namespace std;

int main()
{
    Simulation *sim = new Simulation();
    sim->start_random(10000);
	sim->train();
	short winner = sim->sim_CLI();
	cout << winner << endl;
	cout << "end" << endl;
	int nbr = 0;
	while(!nbr)
		cin >> nbr;
    return 0;
}