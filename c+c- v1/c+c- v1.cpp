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
	std::string neuronBase = "0:0#0!0|0:1#0!0|0:2#0!0|0:3#0!0|0:4#0!0|";
	vector<IA> genom;

	Game game;
	game.init(0, 100, 10);
	while (1)
	{

	}


    return 0;
}

