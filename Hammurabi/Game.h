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
	//��������� ���������� �������
	const long startCitizens = 100;
	//��������� ���������� ������� �������
	const long startWheat = 2800;
	//��������� ���������� ����� �����
	const long startSquare = 1000;
	//����� ������
	int numberRound = 1;
	//������������� ������� ������� �� ������ 
	int averageDead = 0;
};

