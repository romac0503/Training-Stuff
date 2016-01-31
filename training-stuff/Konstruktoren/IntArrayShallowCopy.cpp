#include "IntArrayShallowCopy.h"

using namespace std;

/***** Konstruktor *******/
IntArrayShallowCopy::IntArrayShallowCopy(unsigned int size) :size(size)
{
	if (size != 0)
		mem = new int[size];
}

IntArrayShallowCopy::~IntArrayShallowCopy()
{
	if (mem != 0)
		clear();
	mem = 0;
	size = 0;
}

int& IntArrayShallowCopy::getAt(unsigned int idx)
{
	if (idx < size && idx >= 0)
	{
		return mem[idx];
	}
}

void IntArrayShallowCopy::clear()
{
	if (mem != 0){
		delete[] mem;
	}
	mem = 0;
	size = 0;
}

void IntArrayShallowCopy::modifyArray(unsigned idx, int value) const
{
	if (idx >= 0 && idx < size)
		mem[idx] = value;
}

void IntArrayShallowCopy::print()
{
	if (size != 0)
	{
		for (int i = 0; i < size; i++)
			cout << mem[i] << endl;
	}
	cin.get();
}