#pragma once
#include "Article.h"

class Book: public Article
{
private:
	std::string _author;

public:
	Book();
	Book(std::string name, int articleNumber, float price, std::string author) : Article(name, articleNumber, price)
	{
		_author = author;
	}

	void edit();

	void print() const;

	void checkAuthor();

	std::string getAuthor();

	void setAuthor(std::string author);
};