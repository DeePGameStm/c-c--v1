#include "stdafx.h"
#include "Game.h"


Game::Game()
{
}

void Game::init(int nbMinF, int nbMaxF, int nbTourF, int manual)
{
	nbMin = nbMinF; nbMax = nbMaxF; nbTour = nbTourF; work = true;
	if (manual == -1)
	{
		nbF = (rand() % nbMax) + nbMin;
	}
	else
		nbF = manual;

	//std::cout << "nbF= " << nbF << std::endl;
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
