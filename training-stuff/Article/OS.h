#pragma once

#include <iostream>

class OS
{
public:
	enum OS_Selection { WINDOWS, MAC, LINUX };
	OS_Selection _os;

	OS(){}
	OS(OS_Selection os) :_os(os){}

	void setOS(unsigned int os)
	{
		switch (os)
		{
		case 0:
			_os = OS_Selection::LINUX;
			break;
		case 1:
			_os = OS_Selection::MAC;
			break;
		case 2:
			_os = OS_Selection::WINDOWS;
			break;
		default:
			_os = OS_Selection::WINDOWS;
			break;
		}
	}
};