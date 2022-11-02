#include "Round.h"

void Round::newGame(int currentCitizens, int currentWheat, int currentSquare)
{   
    numberRound = 0;
    Round::currentCitizens = currentCitizens;
    Round::currentWheat = currentWheat;
    Round::currentSquare = currentSquare;
    genPriceAcre();
}

void Round::continueGame(int currentCitizens, int currentWheat, int currentSquare, int numberRound, int priceAcre)
{
    Round::currentCitizens = currentCitizens;
    Round::currentWheat = currentWheat;
    Round::currentSquare = currentSquare;
    Round::numberRound = numberRound;
    Round::priceAcre = priceAcre;
}

int Round::simRound(int currentSquare, int currentWheat,int wheatAcre, int wheatForEat)
{   
    numberRound++;

    Round::currentSquare += currentSquare;
    Round::currentWheat = currentWheat;
    Round::wheatAcre = wheatAcre;
    Round::wheatForEat = wheatForEat;

    calcDeadCitizens();
    int currentProcentDead = float(deadCitizens / float(currentCitizens + deadCitizens)) * 100;
    if (numberRound == 1)
        procentDead = currentProcentDead;
    else 
        procentDead = (procentDead + currentProcentDead) / 2;
    newCitizen();
    plague();
    if (isPlague)
        currentCitizens /= 2;

    genPriceAcre();
    genWheatProfit();
    genWheatDestroyed();

    return currentProcentDead;
}

void Round::PrintInfo()
{
    cout << "\nМой повелитель, позволь поведать тебе\n в году " << numberRound << " твоего высочайшего правления\n";
    cout << deadCitizens << " умерли с голоду, и " << newCitizens << " человек прибыли в наш великий город;\n";
    if (isPlague)
        cout << "Чума убила половину населения;\n";
    cout << "Население города сейчас составляет " << currentCitizens << " человек;\n";
    cout << "Мы собрали " << wheatProfit * wheatAcre << " бушелей пшеницы, по " << wheatProfit << " бушеля с акра;\n";
    cout << "Крысы истребили " << wheatDestroyed << " бушелей пшеницы, оставив " << currentWheat << " бушеля в амбарах;\n";
    cout << "Город сейчас занимает " << currentSquare << " акров;\n";
    cout << "1 акр земли стоит сейчас " << priceAcre << " бушель.\n";
}

void Round::genPriceAcre()
{
    priceAcre = myRandom(17,26);
}

void Round::genWheatProfit()
{
    wheatProfit = myRandom(1, 6);
    currentWheat += (wheatProfit * wheatAcre);
}

void Round::genWheatDestroyed()
{   
    wheatDestroyed = (float(myRandom(0, 7)) / 100) * currentWheat;

    currentWheat -= wheatDestroyed;
}

void Round::calcDeadCitizens()
{
    deadCitizens = currentCitizens - wheatForEat / 20;
    if (deadCitizens < 0)
        deadCitizens = 0;

    currentCitizens -= deadCitizens;
}

void Round::newCitizen()
{   
    newCitizens = deadCitizens / 2 + (5 - wheatProfit) * currentWheat / 600 + 1;

    if (newCitizens < 0) newCitizens = 0;
    if (newCitizens > 50) newCitizens = 50;

    currentCitizens += newCitizens;
}

void Round::plague()
{
    if (myRandom(1, 100) > 15)
        isPlague = false;
    else isPlague = true;
}

int Round::getProcentDead()
{
    return procentDead;
}

int Round::getAcreCitizen()
{
    return currentSquare / currentCitizens;
}

int Round::myRandom(int min, int max)
{
    srand(time(0));
    return rand() % (max - min + 1) + min;
}
