#include "stdafx.h"
#include "IA.h"


IA::IA(std::string params) //std::string neuronBase = "0:0!0|0:0!0|0:0!0|0:0!0|0:0!0|1:10!0|";
{
	bool end = false;
	unsigned int nbChar = 0;
	int nbCol;
	std::vector<int> nbColVec;
	bool littleExist = false;
	int nbNeuron = -1;
	int mode = 0; //0 = col, 1 = nbN, 2 = liaison
	int modeNeuron;
	int liaisonNum;
	std::string msg = "";
	std::vector<Neurons> n0;
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
			for (unsigned int c(0); c < nbColVec.size(); c++)
				if (nbCol == c)
					littleExist = true;
			if (!littleExist) {
				neuronsLs.push_back(n0);
				nbColVec.push_back(0);
			}
			else
				littleExist = false;
			msg = "";
			mode = 1;
			break;
		case 1:
			while (params[nbChar] != '!')
			{
				msg += params[nbChar];
				nbChar++;
			}
			nbChar++;
			modeNeuron = atoi(msg.c_str());
			msg = "";
			mode = 2;
			neuronsLs[nbCol].push_back(Neurons(modeNeuron, nbCol, nbColVec[nbCol], &neuronsLs));
			if (modeNeuron == 10)
				neuronsLs[nbCol][nbColVec[nbCol]].outIntP = &outInt;
			nbColVec[nbCol]++;
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
				neuronsLs[nbCol][nbColVec[nbCol] - 1].makeLiaison(liaisonNum);
			}
			nbChar++;
			if (params.size() > nbChar)
				mode = 0;
			else
				end = true;
			break;
		}
	}
	//	std::cout << "neu0: " << neuronsLs[0].size() << std::endl;
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
		for (unsigned int y(0); y < neuronsLs[i].size(); y++)
		{
			ss << i;
			ss << ':';
			ss << neuronsLs[i][y].mode;
			ss << '!';
			for (unsigned int z(0); z < neuronsLs[i][y].liaisons.size(); z++)
			{
				ss << neuronsLs[i][y].liaisons[z];
				if ((z + 1) < neuronsLs[i][y].liaisons.size())
					ss << ',';
			}
			ss << '|';
		}
	}
	msg = ss.str();
	return msg;
}

bool IA::mutate()
{
	bool ret = false;
	srand(time(NULL));
	for (unsigned int i(0); i < neuronsLs.size() - 1; i++)
	{
		for (unsigned int y(0); y < neuronsLs[i].size(); y++)
		{
			if ((rand() % 100) == 1)
			{
				neuronsLs[i][y].mode = rand() % maxMode;
				if ((rand() % 100) == 1) //liaison
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
							neuronsLs[i][y].makeLiaison(varRandLiaison);
							ret = true;
						}
					}
					else //break liaison
					{
						if (neuronsLs[i][y].liaisons.size() > 0)
						{
							neuronsLs[i][y].breakLiaison(rand() % neuronsLs[i][y].liaisons.size()); 
							ret = true;
						}

					}
				}
				if ((rand() % 10) == 1 || 1 == 1) //changement mode
				{
					neuronsLs[i][y].mode = rand() % maxMode;
					ret = true;
				}
			}
		}
		if ((rand() % 100) == 1) //addColonne (+add one neuron)
		{
			std::vector<std::vector<Neurons>> replace;
			std::vector<Neurons> replaceChild;
			for (unsigned int i2(0); i2 < neuronsLs.size(); i2++)
			{
				replace.push_back(neuronsLs[i2]);
				if (i2 == i)
				{
					replace.push_back(replaceChild);
					replace[i2 + 1].push_back(Neurons(rand() % maxMode, i2 + 1, 0, &neuronsLs));
					replace[i2 + 1][0].makeLiaison(0);
				}
			}
			neuronsLs.clear();
			neuronsLs = replace;
			ret = true;
		}
		if ((rand() % 100) == 1) //addNeuron
		{
			neuronsLs[i].push_back(Neurons(rand() % maxMode, i, neuronsLs[i].size(), &neuronsLs));
			ret = true;
		}
	}
	return ret;
}

void IA::output()
{

}

IA::~IA()
{
}
