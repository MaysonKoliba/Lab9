#pragma once


class heap
{
public:

	heap(int array[], int size);
	void printArray();
	bool add(int data);
	bool remove();


private:

	int getLeftChild(int index) { return (2 * index) + 1; };
	int getRightChild(int index) { return (2 * index) + 2; };
	int getParent(int index) { return ((index - 1) / 2); };
	void heapRebuild(int root);
	void heapCreate();

	int* heapArray;
	int itemCount;
	int maxItems;
};