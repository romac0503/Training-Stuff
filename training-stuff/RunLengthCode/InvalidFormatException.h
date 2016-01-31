#include "MyExceptionClass.h"

class InvalidFormatException : public MyExceptionClass
{
private:
	const char* _msg;


public:
	InvalidFormatException(const char* msg) : _msg(msg)
	{
	}
	~InvalidFormatException() throw()
	{
	}

	virtual const char* what() const throw()
	{
		return _msg;
	}
};