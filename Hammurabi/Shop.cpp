#include "Shop.h"

long Shop::buyAcre(long currentWheat, int priceAcre, int input)
{
    int summ = input * priceAcre;
   
    if (summ > currentWheat)
        return -1;
    else return currentWheat - summ;
}

int Shop::sellAcre(long currentSquare, int priceAcre, int input)
{   
    long summ = input * priceAcre;

    if (summ > currentSquare)
        return -1;
    else return currentSquare - summ;
}

int Shop::wheatForEat(long currentWheat, int input)
{
    if (currentWheat < input)
        return -1;
    else return input;
    
}

int Shop::sowingWheat(long currentCitizens, long currentWheat, long currentSquare, int input)
{
    if (currentSquare < input && currentWheat < input * 0.5f && currentCitizens * 10 < input)
        return -1;
    else return input;
}
