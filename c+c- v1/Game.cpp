#include "stdafx.h"
#include "Game.h"


Game::Game()
{
}

void Game::init(int nbMinF, int nbMaxF, int nbTourF)
{
	nbMin = nbMinF; nbMax = nbMaxF; nbTour = nbTourF; work = true;
	srand(time(NULL));
	nbF = (rand() % nbMax) + nbMin;
}

void Game::play(int input)
{
	if (nbTour > 0)
	{
		if (input < nbF)
			PM = 2;
		else if (input > nbF)
			PM = 1;

		if (input == nbF)
		{
			work = false;
		}
		else
			nbTour--;
	}
	else
		work = false;
}

Game::~Game()
{
}
