// c+c- v1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <Windows.h>
#include <iostream>
#include <math.h>
#include <fstream>
#include <sstream>
#include "Game.h"
#include <vector>
#include "IA.h"
#include <algorithm>
#include <conio.h>

using namespace std;

int main()
{
	std::string neuronBase = "0:0!0|0:0!0|0:0!0|0:0!0|0:0!0|1:10!0|";
	IA Lia(neuronBase);
	vector<IA> genom;
	vector<int> score;
	Game game;
	int scoreMax;
	int scoreTemp1;
	int scoreTemp1Case;
	int scoreTemp2;
	int scoreTemp2Case;
	bool wow = false;
	unsigned long nbG;

	IA *tempIa = 0;

	vector<IA> generations;
	generations.push_back(Lia);

	while (1)
	{
		cout << "scoreMax: ";
		cin >> scoreMax;
		if (scoreMax == -1)
			break;
		game.init(0, 101, 50);
		nbG = 0;
		while(1)
		{
			tempIa = new IA(generations[generations.size() - 1].returnADN());
			tempIa->mutate();

			genom.push_back(IA(tempIa->returnADN()));
			genom[genom.size() - 1].gameP = &game;
			score.push_back(0);
			delete tempIa;
			tempIa = 0;
			wow = false;
			while (1)
			{
				if (_kbhit())
				{
					_getch();
					cout << "KBHIT: " << endl << "GENERATION: " << nbG << endl << "ADN: " << generations[generations.size() - 1].returnADN() << endl;
					Sleep(3000);
					cout << "..." << endl;
				}
				if (game.work)
				{
					//cout << "pointerMain: " << genom[genom.size() - 1].neuronsLs.size() << endl;
					genom[genom.size() - 1].update();
				}
				else
				{
					score[score.size() - 1] = game.nbTour;
					if (genom.size() > 99)
					{
						scoreTemp1 = -1; scoreTemp2 = -1;
						for (unsigned int i(0); i < score.size(); i++)
						{
							if (scoreTemp1 < score[i])
							{
								scoreTemp1 = score[i];
								scoreTemp1Case = i;
							}
						}
						if (scoreTemp1 > scoreMax)
						{
							cout << "wow; score: " << scoreTemp1 << endl << "ADN: " << genom[scoreTemp1Case].returnADN() << endl << endl;
							wow = true;
						}
						for (unsigned int i(0); i < score.size(); i++)
						{
							if (scoreTemp2 < score[i] && scoreTemp1Case != i)
							{
								scoreTemp2 = score[i];
								scoreTemp2Case = i;
							}
						}
						if (scoreTemp2 > scoreMax)
						{
							cout << "wow; score: " << scoreTemp2 << endl << "ADN: " << genom[scoreTemp2Case].returnADN() << endl << endl;
							wow = true;
						}

						//fusion
						generations.clear();
						generations.push_back( IA ( Lia.fusion(genom[scoreTemp1Case].returnADN(), genom[scoreTemp2Case].returnADN() ) ) );
						nbG++;
						//cout << "0" << endl;
						genom.clear();
						score.clear();
						if (wow)
						{
							cout << "fusion ADN: " << generations[generations.size() - 1].returnADN() << endl;
							cout << endl << "PAUSE!" << endl << endl;
							break;
						}
						else
							break;
					}
					else
					{
						tempIa = new IA(generations[generations.size() - 1].returnADN());
						tempIa->mutate();

						genom.push_back(IA( tempIa->returnADN() ) );
						genom[genom.size() - 1].gameP = &game;
						score.push_back(0);
						delete tempIa;
						tempIa = 0;
						break;
					}
				}
			} //fin 2
			if (wow)
				break;
		} //fin 1
	}


	cout << "DONE!" << endl;
	system("PAUSE");
    return 0;
}

