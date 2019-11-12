// Lab9.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Queues.h"
using namespace std;

int main()
{

	int array1[6] = { 6, 3, 5, 9, 2, 10 };

	heap test(array1, 6);

	test.remove();
	test.add(10);
	test.printArray();
 
}

