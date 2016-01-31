// BinaryRepresentation.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <string>
#include <iostream>


int main(int argc, char* argv[])
{
	std::string binaryRepresentation = "";
	unsigned int intPart = 3;
	for (unsigned int bitIndex = 0; bitIndex <= sizeof(unsigned int)* 8; ++bitIndex)
	{
		bool bitSet = (intPart % 2) == 1;
		intPart = intPart / 2;
		binaryRepresentation = std::string(bitSet ? "1" : "0") + binaryRepresentation;
	}

	std::cout << binaryRepresentation << std::endl;
	std::cin.get();

	return 0;
}

