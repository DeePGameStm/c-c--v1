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

void Neurons::activate() //0 = addition, 1 = multiplication, 2 = division, 3 = soustraction, 4 = &&, 5 = ||, 6 = !, 7 = CONST, 8 = MEM 
{
	int value = 0;
	switch (mode)
	{
	case 0: //+
		for (unsigned int i(0); i < inputs.size(); i++)
			value += inputs[i];
		inputs.clear();
		break;
     case 1: //x
        value = inputs[0];
        for (unsigned int i(1); i < inputs.size(); i++)
			value *= inputs[i];
		inputs.clear();
     break;
     case 2:// /
     value = inputs[0];
        for (unsigned int i(1); i < inputs.size(); i++)
			value /= inputs[i];
		inputs.clear();
     break;
     case 3://-
     value = inputs[0];
        for (unsigned int i(1); i < inputs.size(); i++)
			value -= inputs[i];
		inputs.clear();
     break;
	 case 4: //&&
		 value = 1;
		 for (unsigned int i(0); i < inputs.size() - 1; i++)
			 if (inputs[i] != inputs[i + 1])
				 value = 0;
		 break;
	 case 5: //||
		 for (unsigned int i(0); i < inputs.size(); i++)
			 if (inputs[i] > 0)
				 value = 1;
		 break;
	 case 6: //!
		 for(unsigned int i(0); i < inputs.size(); i++)
			 value += inputs[i];
		 if (value > 0)
			 value = 0;
		 else
			 value = 1;
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
