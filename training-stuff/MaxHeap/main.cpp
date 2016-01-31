// MaxHeap.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "maxheap.h"

MaxHeap<unsigned> myMaxHeap;

void init()
{
	myMaxHeap.enqueue(30);
	myMaxHeap.enqueue(40);
	myMaxHeap.enqueue(35);
	myMaxHeap.enqueue(2);
	myMaxHeap.enqueue(8);
	myMaxHeap.enqueue(6);
	myMaxHeap.enqueue(12);
	myMaxHeap.enqueue(16);
	myMaxHeap.enqueue(20);
	myMaxHeap.enqueue(10);
	myMaxHeap.enqueue(21);
	myMaxHeap.enqueue(23);
}

void TestParentIdx()
{
	MaxHeap<unsigned int> myMaxHeap;

	// check empty MaxHeap
	assert(myMaxHeap.parentIdx(0) == 0);

	init();
	assert(myMaxHeap.parentIdx(6) == 2);
	cout << "Test Parent Idx completed" << endl;
	cin.get();
}

void TestLeftChildIdx()
{
	assert(myMaxHeap.getValue(myMaxHeap.leftChildIdx(5) == 2));
	assert(myMaxHeap.leftChildIdx(2) == 5);
	assert(myMaxHeap.getValue(myMaxHeap.leftChildIdx(6)) == NULL);
	cout << "Test Left Child Index completed" << endl;
	cin.get();
}

void TestRightChildIdx()
{
	assert(myMaxHeap.getValue(myMaxHeap.rightChildIdx(0) == 35));
	assert(myMaxHeap.rightChildIdx(2) == 6);
	assert(myMaxHeap.getValue(myMaxHeap.rightChildIdx(6)) == NULL);
	cout << "Test Right Child Index completed" << endl;
}

int main(int argc, char* argv[])
{
	TestParentIdx();
	TestLeftChildIdx();
	TestRightChildIdx();
	cin.get();

	return 0;
}

