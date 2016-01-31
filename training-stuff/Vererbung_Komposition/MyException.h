#pragma once

#include <string>
#include <iostream>
#include <exception>

class MyException : public std::exception
{
private:
	const char* _msg;

public:
	MyException(const char* msg) :_msg(msg) { }

	virtual const char* that() throw()
	{
		return _msg;
	}
};