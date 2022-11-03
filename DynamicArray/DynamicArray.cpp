#include <iostream>
#include "MyArray.h"
using namespace std;


int main()
{	
	setlocale(LC_ALL, "Russian");
	
	MyArray<int> a;

	for (int i = 0; i < 10; ++i)
		a.insert(i + 1);

	for (int i = 0; i < a.size(); ++i)
		a[i] *= 2;

	cout << "Array A:\n";
	for (auto it = a.iterator(); it.hasNext(); it.next())
		std::cout << it.get() << std::endl;

	cout << "Reverse Array A:\n";
	for (auto it = a.reverseIterator(); it.hasNext(); it.next())
		std::cout << it.get() << std::endl;
		
}

