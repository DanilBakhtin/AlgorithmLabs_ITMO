#pragma once
#include <iostream>
#include "Shop.h"
using namespace std;


class Round
{
public:
	//Текущее количество жителей
	int currentCitizens;
	//Текущее количество бушелей пшеницы
	int currentWheat;
	//Текущее количество акров земли
	int currentSquare;
	//Цена акра
	int priceAcre;
	//Номер раунда
	int numberRound;

	void newGame(int currentCitizens, int currentWheat, int currentSquare);
	int simRound(int currentSquare, int currentWheat,int wheatAcre, int wheatForEat);
	void PrintInfo();
	void continueGame(int currentCitizens, int currentWheat, int currentSquare, int numberRound, int priceAcre);

	//Процент умерших от голода
	int getProcentDead();
	//Количество акров на одного жителя
	int getAcreCitizen();

private:
	//Количество людей, умерших за раунд
	int deadCitizens;
	//Количество людей, приехавших в город
	int newCitizens;
	//Была ли в раунде чума
	bool isPlague;
	//Количество собранной пшеницы с одного акра
	int wheatProfit;
	//Количество уничтоженной крысами пшеницы
	int wheatDestroyed;
	//Засеянные акры
	int wheatAcre;
	//Сколько еды будет съеденно крестьянами
	int wheatForEat;
	//Процент умерших от голода за все раунды
	int procentDead = 0;

	//Генерация стоимости акра
	void genPriceAcre();
	//Расчет вероятности чумы
	void plague();
	//Расчет прибыших граждан
	void newCitizen();
	//Расчет погибших граждан
	void calcDeadCitizens();
	//Генерация пшеницы с одного акра
	void genWheatProfit();
	//Генерация уничтоженной крысами пшеницы
	void genWheatDestroyed();
	//Случайное число от min до max
	int myRandom(int min, int max);
};

