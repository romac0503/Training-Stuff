#pragma once
#include "Article.h"
#include "MyException.h"
#include "Genre.h"

class DVD : public Article
{
private:
	Genre _genre;

public:
	DVD();
	DVD(std::string name, int articleNumber, float price, Genre genre) : Article(name, articleNumber, price){}

	void getGenre() const;
	void setGenre(unsigned genre);
	void print() const;
	void edit();
};