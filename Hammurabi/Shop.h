#pragma once
class Shop
{
public:
	//������� ����� �����
	long buyAcre(long currentWheat, int priceAcre, int input);
	//������� ����� �����
	int sellAcre(long currentSquare, int priceAcre, int input);
	//�������� �������
	int wheatForEat(long currentWheat, int input);
	//���������� �����
	int sowingWheat(long currentCitizens, long currentWheat, long currentSquare, int input);
};

