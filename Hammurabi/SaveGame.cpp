#include "SaveGame.h"

bool SaveGame::checkSaveGame()
{   
	string line;
	string check = "";
	ifstream in(filename); // окрываем файл для чтения
	if (in.is_open())
	{
		while (getline(in, line))
		{
			check += line;
		}
	}
	in.close();     // закрываем файл

	if (check == "") return false;
	else return true;
}

void SaveGame::save(int mass[])
{
	std::ofstream out(filename);
	if (out.is_open())
	{
		for (int i = 0; i < countData; i++)
			out << mass[i] << endl;
	}
	out.close();
}

int* SaveGame::loadGame()
{	
	int outmass[5];
	int ch = 0;

	string line;
	ifstream in(filename); // окрываем файл для чтения
	if (in.is_open())
	{
		while (getline(in, line))
		{
			outmass[ch++] = stoi(line);
		}
	}
	in.close();     // закрываем файл
	return outmass;
}

void SaveGame::deleteGame()
{
	std::ofstream out(filename);
	if (out.is_open())
	{
			out << "";
	}
	out.close();
}
