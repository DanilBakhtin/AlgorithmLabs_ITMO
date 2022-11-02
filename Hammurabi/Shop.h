#pragma once
class Shop
{
public:
	//Покупка акров земли
	long buyAcre(long currentWheat, int priceAcre, int input);
	//Продажа акров земли
	int sellAcre(long currentSquare, int priceAcre, int input);
	//Съедение пшеницы
	int wheatForEat(long currentWheat, int input);
	//Засеивание акров
	int sowingWheat(long currentCitizens, long currentWheat, long currentSquare, int input);
};

