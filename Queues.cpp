#include "Queues.h"
#include <string>
#include <iostream>
using namespace std;


heap::heap(int array[], int size) : itemCount(size), maxItems(2 * size)
{
	heapArray = new int[maxItems];

	for (int i = 0; i < size; i++) {
		heapArray[i] = array[i];
	}

	heapCreate();
};

void heap::heapRebuild(int root)

{
	int size = itemCount;
	int largest = root;  
	int left = getLeftChild(root); 
	int right = getRightChild(root);  

	if (left < size && heapArray[left] > heapArray[largest]) {
		largest = left;
	}

	if (right < size && heapArray[right] > heapArray[largest]) {
		largest = right;
	}

	if (largest != root) {
		swap(heapArray[root], heapArray[largest]);

		heapRebuild(largest);
	}
};

void heap::heapCreate() 
{
	for (int i = itemCount / 2; i >= 0; i--) {
		heapRebuild(i);
	}
};

void heap::printArray() 
{
	for (int i = 0; i < itemCount; i++) {
		cout << to_string(heapArray[i]);
	}
};

bool heap::remove() 
{
	heapArray[0] = heapArray[itemCount - 1];
	itemCount--;
	heapRebuild(0);
	return true;
};

bool heap::add(int data) 
{
	heapArray[itemCount] = data;

	int newDataIndex = itemCount;
	bool inPlace = false;

	while ((newDataIndex >= 0) && !inPlace) {
		int parentIndex = (newDataIndex - 1) / 2;
		if (heapArray[newDataIndex] <= heapArray[parentIndex]) {
			inPlace = true;
		}
		else{
			swap(heapArray[newDataIndex], heapArray[parentIndex]);
			newDataIndex = parentIndex;
		}
	}
	itemCount++;

	return true;
};
