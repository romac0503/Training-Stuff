#pragma once

#include <string>
#include <iostream>
#include <exception>

class MyException : public std::exception
{
private:
	const char* msg;

public:

	virtual const char* what();
};