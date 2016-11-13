#pragma once

#include "Game.h"
#include <vector>
#include "Neurons.h"
#include <iostream>
#include <string>

class IA
{
public:
	IA(std::string params);
	void update();

	~IA();

	std::vector<std::vector<Neurons>> neuronsLs;
};

