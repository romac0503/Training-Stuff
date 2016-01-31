#include "Article.h"
#include "MyException.h"
#include <assert.h>
#include <iostream>
#include <sstream>
#include <string>

Article::Article()
{
}

Article::Article(std::string name, int articleNumber, float price) :_name(name), _articleNumber(articleNumber), _price(_price){}

Article::~Article(){}

float Article::getPrice() const
{
	return _price;
}

void Article::setPrice(float price)
{
	if (price <= 0)
	{
		throw new MyException("the price can't be zero or negative!");
	}
	_price = price;
}

int Article::getArticleNumber() const
{
	return _articleNumber;
}

void Article::setArticleNumber(unsigned number)
{
	if (number <= 0)
	{
		throw new MyException("the article number can't be zero or negative!");
	}
	_articleNumber = number;
}

std::string Article::getName() const
{
	if (_name.empty())
	{
		throw new MyException("the name of this article is not set yet!");
		return "";
	}
	return _name;
}

void Article::setName(std::string name)
{
	_name = name;
}

void Article::print() const
{
	std::cout << "######################################" << std::endl;
	std::cout << "# Article name:\t" << _name << std::endl;
	std::cout << "# Article number:\t" << _articleNumber << std::endl;
	std::cout << "# Price:\t" << _price << std::endl;
}

void Article::addTax(float p)
{
	if (p <= 0)
	{
		throw new MyException("the value can't be zero or negative!");
		return;
	}

	float tmpPrice = 0;
	tmpPrice = (_price / 100)*p;
	_price += tmpPrice;
}

void Article::edit()
{
	std::cout << "Do you want to edit the name of this article? j/n" << std::endl;

	bool tmpChoice = checkAnswer();
	if (tmpChoice)
	{
		checkName();
	}

	std::cout << "Do you want to edit the price? j/n" << std::endl;

	tmpChoice = checkAnswer();
	if (tmpChoice)
	{
		checkPrice();
	}

	std::cout << "Do you want to edit the article number? j/n" << std::endl;

	tmpChoice = checkAnswer();
	if (tmpChoice)
	{
		checkArticleNumber();
	}
}

bool Article::checkAnswer()
{
	std::string input = "";

	// How to get a single char.
	char myChar = { 0 };

	while (true) {
		std::cout << "Please choose if you want to edit: ";
		std::getline(std::cin, input);

		if (input.length() == 1 && (myChar != 'j' || myChar != 'J' || myChar != 'n' || myChar != 'N')) {
			myChar = input[0];
			break;
		}

		std::cout << "Invalid character, please try again" << std::endl;
	}
	std::cout << std::endl;
	std::cout << "You entered: " << myChar << std::endl;

	if (myChar == 'j' || myChar == 'J') return true;
	else if (myChar == 'n' || myChar == 'N') return false;
	else return false;
}

void Article::checkName()
{
	std::string input = "";

	while (true) {
		std::cout << "Please write the name of this article and press enter: ";
		std::getline(std::cin, input);

		if (input.length() >= 1 ) {
			break;
		}

		std::cout << "Invalid character, please try again" << std::endl;
	}
	std::cout << std::endl;
	std::cout << "You entered: " << input << std::endl;
	setName(input);
}


void Article::checkPrice()
{
	std::string input = "";

	// How to get a number.
	int myNumber = 0;

	while (true) {
		std::cout << "Please enter a valid price (no negative numbers): ";
		getline(std::cin, input);

		// This code converts from string to number safely.
		std::stringstream myStream(input);
		if (myStream >> myNumber && myNumber > 0 && myNumber < MAXPRICE)
			break;
		std::cout << "Invalid price, please try again" << std::endl;
	}
	std::cout << "You entered: " << myNumber << std::endl;
	setPrice(myNumber);
}

void Article::checkArticleNumber()
{
	std::string input = "";

	// How to get a number.
	int myNumber = 0;

	while (true) {
		std::cout << "Please enter a valid number (no negative numbers): ";
		getline(std::cin, input);

		// This code converts from string to number safely.
		std::stringstream myStream(input);
		if (myStream >> myNumber && myNumber > 0)
			break;
		std::cout << "Invalid number, please try again" << std::endl;
	}
	std::cout << "You entered: " << myNumber << std::endl;
	setArticleNumber(myNumber);
}
