#pragma once

#include "Game.h"
#include <vector>
#include "Neurons.h"
#include <iostream>
#include <string>
#include <sstream>

class IA
{
public:
	IA(std::string params);
	void update();

	std::string returnADN();

	~IA();

	std::vector<std::vector<Neurons>> neuronsLs;
};

