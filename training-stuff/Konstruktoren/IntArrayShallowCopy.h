// 1210601015
// Robert Maciejewski
// ue01 bsp01

#include <iostream>
#include <cassert>

#ifndef _INTARRAYSHALLOWCOPY_H_
#define _INTARRAYSHALLOWCOPY_H_
using namespace std;

class IntArrayShallowCopy {
private:
	/** The size of the array */
	unsigned size;
	/** The actual array */
	int* mem;


public:
	/** Creates an array of size-many integers */
	IntArrayShallowCopy(unsigned size);

	/** Deallocates array */
	~IntArrayShallowCopy();

	/** Get reference of integer at specific index */
	int& getAt(unsigned idx);

	/** Print array to stdout */
	void print();

	/**  Modify-Array */
	void modifyArray(unsigned idx, int value) const;


private:
	/** Remove all elements from the array (free the memory) */
	void clear();
};

#endif
