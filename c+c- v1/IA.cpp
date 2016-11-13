#include "stdafx.h"
#include "IA.h"


IA::IA(std::string params) //std::string neuronBase = "0:0!0|0:0!0|0:0!0|0:0!0|0:0!0|";
{
	bool end = false;
	unsigned int nbChar = 2;
	int nbCol = 0;
	int nbNeuron = -1;
	int mode = 1; //0 = col, 1 = nbN, 2 = liaison
	int modeNeuron;
	int liaisonNum;
	std::string msg = "";
	std::vector<Neurons> n0;
	neuronsLs.push_back(n0);
	while (!end)
	{
		switch (mode)
		{
		case 0:
			while (params[nbChar] != ':')
			{
				msg += params[nbChar];
				nbChar++;
			}
			nbCol = atoi(msg.c_str());
			nbChar++;
			msg = "";
			break;
		case 1:
			while (params[nbChar] != '!')
			{
				msg += params[nbChar];
				nbChar++;
			}
			nbNeuron++;
			nbChar++;
			modeNeuron = atoi(msg.c_str());
			msg = "";
			mode = 2;
			neuronsLs[nbCol].push_back(Neurons(modeNeuron, nbCol, nbNeuron));
			break;
		case 2:
			while (params[nbChar] != '|')
			{
				while (params[nbChar] != ',' && params[nbChar] != '|')
				{
					msg += params[nbChar];
					nbChar++;
				}
				liaisonNum = atoi(msg.c_str());
				msg = "";
				if (params[nbChar] != '|')
					nbChar++;
				neuronsLs[nbCol][nbNeuron].makeLiaison(liaisonNum);
			}
			nbChar++;
			if (params.size() > nbChar)
				mode = 0;
			else
				end = true;
			break;
		}
	}
}

void IA::update()
{

}

IA::~IA()
{
}
