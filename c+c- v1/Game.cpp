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

int Game::play(int input)
{

}

Game::~Game()
{
}
