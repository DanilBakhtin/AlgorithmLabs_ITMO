#include <iostream>
#include <vector>
#include "Dice.h"

using namespace std;


int main()
{
    /*int numberThrows = 3;
	int numberFace = 10;
	int modifier = 0;

	vector<int> results(numberThrows * numberFace, 0);
	
	Dice dice(numberThrows, numberFace, modifier);

	srand(time(NULL));
	for (size_t i = 0; i < 10000; i++) {
		results[dice.throwingDice() - 1]++;
	}

	for (int i = 0; i < results.size(); i++)
		cout << results[i] << endl;*/


	vector<Dice> dices;
	int sizeR = 0;

	dices.push_back(Dice(2,6,2));
	dices.push_back(Dice(3, 10));

	//1+1+1+1+1+2 = 7 минимум
	//6+6+10+10+10+2 = 44 максимум

	for (int i = 0; i < dices.size(); i++) {
		sizeR += dices[i].getFace() * dices[i].getThrows() + dices[i].getModifier();
	}

	vector<int> results(sizeR,0);

	for (size_t i = 0; i < 10000; i++) {
		int res = Dice::multiThrowingDice(dices);
		results[res - 1]++;
	}

	for (int i = 0; i < results.size(); i++)
		cout << results[i] << endl;
}