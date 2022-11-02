#pragma once
#include <iostream>
#include "Shop.h"
using namespace std;


class Round
{
public:
	//������� ���������� �������
	int currentCitizens;
	//������� ���������� ������� �������
	int currentWheat;
	//������� ���������� ����� �����
	int currentSquare;
	//���� ����
	int priceAcre;
	//����� ������
	int numberRound;

	void newGame(int currentCitizens, int currentWheat, int currentSquare);
	int simRound(int currentSquare, int currentWheat,int wheatAcre, int wheatForEat);
	void PrintInfo();
	void continueGame(int currentCitizens, int currentWheat, int currentSquare, int numberRound, int priceAcre);

	//������� ������� �� ������
	int getProcentDead();
	//���������� ����� �� ������ ������
	int getAcreCitizen();

private:
	//���������� �����, ������� �� �����
	int deadCitizens;
	//���������� �����, ���������� � �����
	int newCitizens;
	//���� �� � ������ ����
	bool isPlague;
	//���������� ��������� ������� � ������ ����
	int wheatProfit;
	//���������� ������������ ������� �������
	int wheatDestroyed;
	//��������� ����
	int wheatAcre;
	//������� ��� ����� �������� �����������
	int wheatForEat;
	//������� ������� �� ������ �� ��� ������
	int procentDead = 0;

	//��������� ��������� ����
	void genPriceAcre();
	//������ ����������� ����
	void plague();
	//������ �������� �������
	void newCitizen();
	//������ �������� �������
	void calcDeadCitizens();
	//��������� ������� � ������ ����
	void genWheatProfit();
	//��������� ������������ ������� �������
	void genWheatDestroyed();
	//��������� ����� �� min �� max
	int myRandom(int min, int max);
};

