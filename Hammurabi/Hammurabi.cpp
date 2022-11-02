#include <iostream>
#include "Game.h"
#include <fstream>
using namespace std;

int main()
{	
	setlocale(LC_ALL, "Russian");
	
	Game game;
	game.play();

	return 0;
}