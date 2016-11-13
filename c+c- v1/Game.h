#pragma once
class Game
{
public:
	Game();

	void init(int nbMinF, int nbMaxF, int nbTourF);

	~Game();

	bool work = false;
	int nbMin;
	int nbMax;
	int nbTour;
};

