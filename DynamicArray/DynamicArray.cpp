#include <iostream>
#include "MyArray.h"
using namespace std;


int main()
{	
	setlocale(LC_ALL, "Russian");
	
	MyArray<string> a(5);
	a.insert("1");
	a.insert("15");
	a.insert("3");
	a.insert("2");

	a.insert(1,"10");

	cout << "Array A:\n";
	for (auto it = a.iterator(); it.hasNext(); it.next())
		std::cout << it.get() << std::endl;

	cout << "Reverse Array A:\n";
	for (auto it = a.reverseIterator(); it.hasNext(); it.next())
		std::cout << it.get() << std::endl;
		
}

