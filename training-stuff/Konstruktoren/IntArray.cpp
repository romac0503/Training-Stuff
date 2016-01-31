#include "IntArray.h"
#include <array>

using namespace std;

/***** Konstruktor *******/
IntArray::IntArray(unsigned size) :size(size)
{
	cerr << "Default Konstruktor\n";
	if (mem != 0)
	{
		mem = new int[size];
	}
}

/****** Destruktor *******/
IntArray::~IntArray()
{
	clear();
}

/***** Copykonstruktor *****/
IntArray::IntArray(const IntArray& cpy): mem(0) {
	cerr << "Copykonstruktor aufgerufen\n";
	// Here the assignment operator is called, which
	// does all the work.
	*this = cpy;
	size = cpy.size;
	mem = new int[size];

	for (int i = 0; i < size; i++)
		mem[i] = cpy.mem[i];
}

void IntArray::clear()
{
	cerr << "freed memory\n";
	if (mem != 0){
		delete[] mem;
	}
	mem = 0;
	size = 0;
}

/******* Assignment Operator *******/
IntArray& IntArray::operator=(const IntArray& cpy)
{
	cerr << "Assignment Operator aufgerufen\n";
	if (this == &cpy){
		return *this;
	}

	clear();

	size = cpy.size;
	mem = new int[size];

	for (int i = 0; i < size; i++)
	{
		mem[i] = cpy.mem[i];
	}

	return *this;
}

int& IntArray::getAt(unsigned idx)
{
	if (idx < size && idx >= 0)
	{
		return mem[idx];
	}
}

void IntArray::setAt(unsigned idx, int val)
{
	if (idx < size && idx >= 0)
	{
		mem[idx] = val;
	}
}

void IntArray::print()
{
	for (int i = 0; i < size; i++)
		cout << mem[i] << endl;
}

void IntArray::modifyArray(int idx, int value) const
{
	if (idx >= 0 && idx < size)
		mem[idx] = value;
}

