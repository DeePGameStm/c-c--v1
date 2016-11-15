#pragma once

#include <cstdlib>
#include <time.h>

class Game
{
public:
	Game();

	void init(int nbMinF, int nbMaxF, int nbTourF);

	~Game();

	int play(int input);

	bool work = false;
	int nbMin;
	int nbMax;
	int nbTour;
	int nbF;
};

