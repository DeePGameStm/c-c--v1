#pragma once

#include <vector>
#include <iostream>

class Neurons
{
public:
	Neurons(int mode, int colonne, int id);
	void makeLiaison(int nbNeuron);
	void breakLiaison(int nbNeuron);

	void activated();

	std::vector<int> liaisons;

	~Neurons();
};

