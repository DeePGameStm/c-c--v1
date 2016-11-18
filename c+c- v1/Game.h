#pragma once

#include <cstdlib>
#include <time.h>
#include <iostream>

class Game
{
public:
	Game();

	void init(int nbMinF, int nbMaxF, int nbTourF, int manual = -1);

	~Game();

	void play(int input);

	bool work = false;
	int nbMin;
	int nbMax;
	int nbTour;
	int nbF;
	int PM = 0;
	bool first = true;
};

