#include "stdafx.h"
#include "Neurons.h"


Neurons::Neurons(int mode, int colonne, int id)
{

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

Neurons::~Neurons()
{
}
