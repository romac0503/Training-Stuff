// DecimalRepresentation.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

// Convert integer parts into binary real parts
// E.g: "5.5" would return intPartBinaryOut = 101b = 5,
// decPartBinaryOut = 10000000000000000000000000000000b = 2147483648
void convertToBinaryReal(unsigned int intPart,
	unsigned int decPart,
	unsigned long long numberOfDecimalDigits,
	unsigned int *intPartBinaryOut,
	unsigned int *decPartBinaryOut)
{
	// The integer part is already in a form we like; no conversion is actually needed,
	//just copy it across
	*intPartBinaryOut = intPart;
	// The decimal part needs to be converted
	*decPartBinaryOut = 0;
	long long overflowContainer = decPart;
	long long overflowMask = 1;
	for (unsigned long long i = 0; i < numberOfDecimalDigits; ++i) overflowMask *= 10;
	// Run through all the output bits we have, and for each one calculate its state
	for (unsigned int bitIndex = 1; bitIndex <= sizeof(unsigned int)* 8 && overflowContainer != 0; ++bitIndex)
	{
		overflowContainer *= 2;
		if (overflowContainer - overflowMask >= 0)
		{
			*decPartBinaryOut |= 1 << (sizeof(unsigned int)* 8 - bitIndex);
			overflowContainer -= overflowMask;
		}
	}
}


int main(int argc, char* argv[])
{

	return 0;
}



