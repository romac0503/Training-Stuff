#include <iostream>
#include <stdio.h>
#include "MyStringPrinter.h"

#pragma once

class StarFrameStringPrinter : public MyStringPrinter
{
private:
	std::string _s;

public:
	/* Constructor */
	StarFrameStringPrinter(MyString s) : MyStringPrinter(s) { _s = returnString(s); }
	StarFrameStringPrinter(const char* s) : MyStringPrinter(s) { _s = s; }
	StarFrameStringPrinter(std::string s) : MyStringPrinter(s) { _s = s; }

	/* Methods */
	void print();
	void info();

};
