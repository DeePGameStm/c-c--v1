#pragma once

#include "Game.h"
#include <vector>
#include "Neurons.h"
#include <iostream>
#include <string>
#include <sstream>
#include <cstdlib>
#include <time.h>

class IA
{
public:
	IA(std::string params);
	void update();

	std::string returnADN();
	bool mutate();

	void output();

	int outInt = -1;

	~IA();

	std::vector<std::vector<Neurons>> neuronsLs;
	int maxMode = 9;
};

