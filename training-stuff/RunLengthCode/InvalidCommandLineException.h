#include "MyExceptionClass.h"

class InvalidCommandLineException : public MyExceptionClass
{

private:
	const char* _msg;

public:
	InvalidCommandLineException(const char* msg) : _msg(msg)
	{
	}
	~InvalidCommandLineException() throw()
	{
	}

	virtual const char* what() const throw()
	{
		return _msg;
	}

};