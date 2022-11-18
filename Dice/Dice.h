#pragma once
#include <iostream>
#include <random>
#include <vector>

class Dice
{
public:

	Dice(int numberThrows, int numberFace, int modifier) {

		srand(time(NULL));
		this->numberThrows_ = numberThrows;
		this->numberFace_ = numberFace;
		this->modifier_ = modifier;
	}

	Dice(int numberThrows, int numberFace) {

		this->numberThrows_ = numberThrows;
		this->numberFace_ = numberFace;
		this->modifier_ = 0;
	}

	int throwingDice() {

		int result = 0;

		for (int i = 0; i < numberThrows_; i++) {
			result += rrand(1, numberFace_);
		}

		result += modifier_;

		return result;
	}

	static int multiThrowingDice(std::vector<Dice> dices) {

		int result = 0;

		for (int i = 0; i < dices.size(); i++) {
			result += dices[i].throwingDice();
		}

		return result;
	}

	int getThrows() {
		return numberThrows_;
	}

	int getFace() {
		return numberFace_;
	}

	int getModifier() {
		return modifier_;
	}

private:
	//Количество бросков
	int numberThrows_;
	//Количество граней
	int numberFace_;
	//Модификатор
	int modifier_;

	int rrand(int range_min, int range_max) {
		return rand() % (range_max - range_min + 1) + range_min;;
	}

};

