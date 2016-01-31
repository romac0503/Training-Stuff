// 1210601015
// Robert Maciejewski
// ue01 bsp01

#include <iostream>
#include <cassert>

#ifndef _INTARRAY_H_
#define _INTARRAY_H_
using namespace std;

class IntArray {
private:
	/** The size of the array */
	unsigned size;
	/** The actual array */
	int* mem;
	/** Remove all elements from the array (free the memory) */
	void clear();


public:
	/** Creates an array of size-many integers */
	IntArray(unsigned size);
	
	/** Copy constructor */
	IntArray(const IntArray& cpy);

	/** Deallocates array */
	~IntArray();

	///** Assignment operator  */
	IntArray& operator=(const IntArray& cpy);

	/** Get reference of integer at specific index */
	int& getAt(unsigned idx);

	/** Set value */
	void setAt(unsigned idx, int val);

	/** Print array to stdout */
	void print();

	/**  Modify-Array */
	void modifyArray(int idx, int value) const;
	
};

#endif
