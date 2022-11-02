#include "Game.h"

void Game::play()
{	
	string choice = "2";

	if (saveGame.checkSaveGame()) {
		cout << "1) ������ ���������� ���� \n";
		cout << "2) ������ ������\n";
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
	cout << "��� ����������, � ����� ������:\n";
	cout << "��������� " << round.currentCitizens << " �������\n";
	cout << "� �������� ������ " << round.currentWheat << " ������� �������\n";
	cout << "����� �������� " << round.currentSquare << " ����� �����\n";
	cout << "1 ��� ����� ����� ������ " << round.priceAcre << " ������\n";
}

int Game::enteringActions()
{	
	unsigned int inputAcre, inputEatWheat, inputSowingWheat;
	cout << "\n��� ���������, ����������?\n";

	inputAcre = inputProcessing("������� ����� ����� ����������� ������? ");
	inputEatWheat = inputProcessing("������� ������� ������� ����������� ������? ");
	inputSowingWheat = inputProcessing("������� ����� ����� ����������� �������? ");

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
		cout << "�� - �� ����� ���������������� � ����������, ����� ������� ����, � ������ ��� �� ������.������ �� ��������� ������� ������ ������������� � ��������\n";
	else if (procentDead > 10 || acreCitizen < 9)
		cout << "�� ������� �������� �����, ������� ������ � ����� ��������.����� �������� � �����������, � ����� ������ �� ������ ������ ��� ����������\n";
	else if (procentDead > 3 || acreCitizen < 10)
		cout << "�� ���������� ������ �������, � ���, �������, ���� ���������������, �� ������ ������ �� ������� ��� �� ����� ������ �����\n";
	else
		cout << "����������! ���� �������, �������� � ���������� ������ �� ���������� �� �����\n";
}

void Game::printError()
{
	cout << "�, ����������, ������ ���! � ��� ������ " << round.currentCitizens << " �������, " << round.currentWheat << " ������� ������� � " << round.currentSquare << " ����� �����!\n";
	
}

void Game::messageLose()
{
	cout << "\n����������, ������� ����� ������� ���� �������� � ���� ����! �� ���� ������� �� ������!\n";
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
		cout << "����������, �� ������� �� ������ ��������!";
		return inputProcessing(message);
	}
	catch (int err) {
		cout << "����������, �� ����� �� ����� ���� �������������!";
		return inputProcessing(message);
	}

	return corrrectNumber;
}

