#pragma once
#include <iostream>
#include <string>
#include "Round.h"
#include "Shop.h"
#include "SaveGame.h"
using namespace std;

class Game
{
public:
	Round round;
	Shop shop;
	SaveGame saveGame;
	void play();
	void outputStartMessage();
	int enteringActions();
	void endMessage(int procentDead, int acreCitizen);
	void printError();
	void messageLose();

private:
	int inputProcessing(string message);
	//Начальное количество жителей
	const long startCitizens = 100;
	//Начальное количество бушелей пшеницы
	const long startWheat = 2800;
	//Начальное количество акров земли
	const long startSquare = 1000;
	//Номер раунда
	int numberRound = 1;
	//Среднегодовой процент умерших от голода 
	int averageDead = 0;
};

