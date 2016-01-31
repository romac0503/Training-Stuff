#include "StarFrameStringPrinter.h"


/* Methods */
void StarFrameStringPrinter::print()
{	
	if (_s.capacity() != 0)
	{
		unsigned int size = _s.capacity();

		/*
		* upper stars
		*/
		std::cerr << "********";
		for (unsigned i = 0; i < _s.capacity(); i++)
		{
			std::cerr << "*";
		}	
		std::cerr << "**********" << std::endl;

		std::cerr << "*\t\t";
		std::cerr << _s;
		
		std::cerr << "\t\t*" << std::endl;

		/*
		* lower stars
		*/
		std::cerr << "*****";
		for (unsigned i = 0; i < _s.capacity(); i++)
		{
			std::cerr << "*";
		}
		std::cerr << "*************" << std::endl;
	}
}

void StarFrameStringPrinter::info()
{
	std::cerr << "Das ist ein mit Sternen formatierter Text." << std::endl;
}