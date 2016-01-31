#include "PC.h"

PC::PC()
{
	_name = "";
	_price = 0;
	_articleNumber = 0;
	_os.WINDOWS;
}

PC::~PC()
{
}

void PC::getOS() const
{
	if (_os.LINUX)
		std::cout << "# Operating System = Linux" << std::endl;
	else if (_os.MAC)
		std::cout << "# Operating System = Mac" << std::endl;
	else
		std::cout << "# Operating System = Windows" << std::endl;
}

void PC::setOS(unsigned os)
{
	if (os == 0)
		_os.LINUX;
	else if (os == 1)
		_os.MAC;
	else
		_os.WINDOWS;
}

void PC::print() const
{
	Article::print();
	getOS();
	std::cout << "######################################" << std::endl;
}

void PC::edit()
{
	Article::edit();
	std::cout << "Do you want to change the OS? j/n?";

	bool tmpChoice = Article::checkAnswer();

	if (tmpChoice)
	{
		std::cout << "Type the number for the OS (Linux = 0, Mac = 1, Windows = 2)\t";
		unsigned tmpOS = 2;
		std::cin >> tmpOS;
		setOS(tmpOS);
	}
}