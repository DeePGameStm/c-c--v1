#include "stdafx.h"
#include "Neurons.h"


Neurons::Neurons(int modeTemp, int colonneTemp, int idTemp, std::vector<std::vector<Neurons>> *pointerLsTemp)
{
	pointerLs = pointerLsTemp;
	mode = modeTemp;
	colonne = colonneTemp;
	id = idTemp;
}

void Neurons::makeLiaison(int nbNeuron)
{
	liaisons.push_back(nbNeuron);
}

void Neurons::breakLiaison(int nbNeuron)
{
	std::vector<int> replace;
	for (unsigned int i = 0; i < liaisons.size(); i++)
	{
		if (i != nbNeuron)
			replace.push_back(liaisons[i]);
	}
	liaisons.clear();
	liaisons = replace;
}

void Neurons::activate() //0 = addition, 1 = multiplication, 2 = division, 3 = soustraction, 4 = AND, 5 = OR, 6 = NON, 7 = CONST, 8 = MEM 
{
	int value = 0;
	switch (mode)
	{
	case 0:
		for (unsigned int i(0); i < inputs.size(); i++)
			value += inputs[i];
		inputs.clear();
		break;

	default:
		break;
	}

	for (unsigned int i(0); i < liaisons.size(); i++)
		(*pointerLs)[colonne + 1][liaisons[i]].inputs.push_back(value);
}

Neurons::~Neurons()
{
}
