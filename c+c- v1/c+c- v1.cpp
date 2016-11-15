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

using namespace std;

int main()
{
	std::string neuronBase = "0:0!0|0:0!0|0:0!0|0:0!0|0:0!0|1:10!0|";
	vector<IA> genom;
	IA test(neuronBase);

	Game game;
	game.init(0, 100, 100);

	cout << "ADN: " << test.returnADN() << endl;

	system("PAUSE");
    return 0;
}

