#pragma once
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

class SaveGame
{
public:
	bool checkSaveGame();
	void save(int mass[]);
	int* loadGame();
	void deleteGame();
private:
	int countData = 5;
	string filename = "saveGame.txt";
};

