#include "stdafx.h"
#include "IA.h"


IA::IA(std::string params) //std::string neuronBase = "0:0!0|0:0!0|0:0!0|0:0!0|0:0!0|1:10!0";
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
			mode = 1;
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
			neuronsLs[nbCol].push_back(Neurons(modeNeuron, nbCol, nbNeuron, &neuronsLs));
			if (modeNeuron == 10)
				neuronsLs[nbCol][nbNeuron].outIntP = &outInt;
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

std::string IA::returnADN()
{
	std::string msg = "";
	std::stringstream ss;
	for (unsigned int i(0); i < neuronsLs.size(); i++)
	{
		ss << i;
		ss << ':';
		for (unsigned int y(0); y < neuronsLs[i].size(); y++)
		{
			ss << neuronsLs[i][y].mode;
			ss << '!';
			for (unsigned int z(0); z < neuronsLs[i][y].liaisons.size(); z++)
			{
				ss << neuronsLs[i][y].liaisons[z];
				if ((z + 1) < neuronsLs[i][y].liaisons.size())
					ss << ',';
			}
		}
		ss << '|';
	}
	msg = ss.str();
	return msg;
}

void IA::mutate()
{
	srand(time(NULL));
	for (unsigned int i(0); i < neuronsLs.size() - 1; i++)
	{
		for (unsigned int y(0); y < neuronsLs[i].size(); y++)
		{
			if ((rand() % 1000) == 1)
			{
				neuronsLs[i][y].mode = rand() % maxMode;
				if ((rand() % 100) == 1)
				{
					if ((rand() % 2) == 0) //make liaison
					{
						if (neuronsLs[i][y].liaisons.size() < neuronsLs[i + 1].size())
						{
							int varRandLiaison = 0;
							bool exist = false;
							do {
								varRandLiaison = rand() % neuronsLs[i + 1].size();
								for (unsigned int z(0); z < neuronsLs[i][y].liaisons.size(); z++)
									if (varRandLiaison == neuronsLs[i][y].liaisons[z])
										exist = true;
							} while (exist);
							neuronsLs[i][y].liaisons.push_back(varRandLiaison);
						}
					}
					else //break liaison
					{

					}
				}
			}
		}
	}
}

void IA::output()
{

}

IA::~IA()
{
}
