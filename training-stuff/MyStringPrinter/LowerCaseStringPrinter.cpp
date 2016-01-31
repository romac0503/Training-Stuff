#include "LowerCaseStringPrinter.h"
#include <string>
#include <algorithm>

/* Methods */
void LowerCaseStringPrinter::print()
{
	std::transform(_s.begin(), _s.end(), _s.begin(), ::tolower);
	std::cerr << _s << std::endl;
}

void LowerCaseStringPrinter::info()
{
	std::cerr << "Das ist ein lowercase StringPrinter." << std::endl;
}
