#include "Book.h"

Book::Book()
{
	_name = "";
	_articleNumber = 0;
	_price = 0;
	_author = "";
}

void Book::edit()
{
	Article::edit();
	std::cout << "Do you want to edit the name of the author? j/n?";
	bool tmpChoice = Article::checkAnswer();

	if (tmpChoice)
	{
		checkAuthor();
	}
}

void Book::print() const
{
	Article::print();
	std::cout << "# Author:\t" << _author << std::endl;
	std::cout << "######################################" << std::endl;
}

void Book::checkAuthor()
{
	std::string input = "";

	while (true) {
		std::cout << "Please enter the name of the author and press enter: ";
		std::getline(std::cin, input);

		if (input.length() >= 1) {
			break;
		}

		std::cout << "Invalid character, please try again" << std::endl;
	}
	std::cout << std::endl;
	std::cout << "You entered: " << input << std::endl;
	setAuthor(input);
}

std::string Book::getAuthor()
{
	if (_author == "")
	{
		throw("the name of the author in not set yet!");
	}
	return _author;
}

void Book::setAuthor(std::string author)
{
	_author = author;
}