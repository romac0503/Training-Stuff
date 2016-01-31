#include "UpperCaseStringPrinter.h"
#include <algorithm>
#include <iostream>
#include <string>


void UpperCaseStringPrinter::print()
{
	std::transform(_s.begin(), _s.end(), _s.begin(), ::toupper);
	std::cerr << _s << std::endl;
}

void UpperCaseStringPrinter::info()
{
	std::cerr << "Das ist ein UpperCase StringPrinter." << std::endl;
}

