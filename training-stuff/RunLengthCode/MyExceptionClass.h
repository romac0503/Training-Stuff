#pragma once 

#include "stdafx.h"
#include <string>
#include <exception>

class MyExceptionClass : public std::exception
{
public:
	MyExceptionClass() { }
	~MyExceptionClass() throw() { }

	virtual const char* what() const throw() = 0;
};