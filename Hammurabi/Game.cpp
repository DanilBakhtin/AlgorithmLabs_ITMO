#include "Game.h"

void Game::play()
{	
	string choice = "2";

	if (saveGame.checkSaveGame()) {
		cout << "1) Хотите продолжить игру \n";
		cout << "2) Начать заново\n";
		cin >> choice;
	}

	if (choice == "1") {
		int* saveMass = saveGame.loadGame();
		round.continueGame(saveMass[0], saveMass[1], saveMass[2], saveMass[3], saveMass[4]);
		numberRound = saveMass[3];
	}
	else round.newGame(startCitizens, startWheat, startSquare);

	outputStartMessage();
	
	for (int i = 0; i < 10; i++) {
		numberRound++;
		
		if (enteringActions() >= 45) {
			messageLose();
			break;
		}

		round.PrintInfo();
		
		int inputMass[5] = { round.currentCitizens, round.currentWheat, round.currentSquare, round.numberRound, round.priceAcre };
		saveGame.save(inputMass);
	}

	endMessage(round.getProcentDead(),round.getAcreCitizen());
}

void Game::outputStartMessage()
{
	cout << "Мой повелитель, в вашем городе:\n";
	cout << "Проживает " << round.currentCitizens << " человек\n";
	cout << "В закромах города " << round.currentWheat << " бушелей пшеницы\n";
	cout << "Город занимает " << round.currentSquare << " акров земли\n";
	cout << "1 акр земли стоит сейчас " << round.priceAcre << " бушель\n";
}

int Game::enteringActions()
{	
	unsigned int inputAcre, inputEatWheat, inputSowingWheat;
	cout << "\nЧто пожелаешь, повелитель?\n";

	inputAcre = inputProcessing("Сколько акров земли повелеваешь купить? ");
	inputEatWheat = inputProcessing("Сколько бушелей пшеницы повелеваешь съесть? ");
	inputSowingWheat = inputProcessing("Сколько акров земли повелеваешь засеять? ");

	long newCurrentWheat = shop.buyAcre(round.currentWheat, round.priceAcre, inputAcre);
	int wheatForEat = shop.wheatForEat(newCurrentWheat, inputEatWheat);

	if (newCurrentWheat >= 0 && wheatForEat >= 0 && shop.sowingWheat(round.currentCitizens,newCurrentWheat, round.currentSquare, inputSowingWheat) >= 0) {
		//cout<<endl << newCurrentWheat << endl;
		newCurrentWheat -= wheatForEat;
		newCurrentWheat -= inputSowingWheat * 0.5f;
		//cout << endl << newCurrentWheat << endl;
		return round.simRound(inputAcre, newCurrentWheat, inputSowingWheat, inputEatWheat);
	}
	else {
		printError();
		enteringActions();
	}

	
}

void Game::endMessage(int procentDead, int acreCitizen)
{
	if (procentDead > 33 || acreCitizen < 7)
		cout << "Из - за вашей некомпетентности в управлении, народ устроил бунт, и изгнал вас их города.Теперь вы вынуждены влачить жалкое существование в изгнании\n";
	else if (procentDead > 10 || acreCitizen < 9)
		cout << "Вы правили железной рукой, подобно Нерону и Ивану Грозному.Народ вздохнул с облегчением, и никто больше не желает видеть вас правителем\n";
	else if (procentDead > 3 || acreCitizen < 10)
		cout << "Вы справились вполне неплохо, у вас, конечно, есть недоброжелатели, но многие хотели бы увидеть вас во главе города снова\n";
	else
		cout << "Фантастика! Карл Великий, Дизраэли и Джефферсон вместе не справились бы лучше\n";
}

void Game::printError()
{
	cout << "О, повелитель, пощади нас! У нас только " << round.currentCitizens << " человек, " << round.currentWheat << " бушелей пшеницы и " << round.currentSquare << " акров земли!\n";
	
}

void Game::messageLose()
{
	cout << "\nПовелитель, слишком много человек было потеряно в этом году! Вы были изгнаны из города!\n";
}

int Game::inputProcessing(string message) {


	cout << "\n" << message << " ";
	int corrrectNumber;
	string input;
	try {
		cin >> input;
		corrrectNumber = stoi(input);
		if (corrrectNumber < 0) throw 1;
	}
	catch (invalid_argument) {
		cout << "Повелитель, вы указали не верное значение!";
		return inputProcessing(message);
	}
	catch (int err) {
		cout << "Повелитель, вы число не может быть отрицательным!";
		return inputProcessing(message);
	}

	return corrrectNumber;
}

