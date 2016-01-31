#pragma once

#include <string>
#include <iostream>

#define MAXPRICE 10000

class Article
{
protected:
	float _price;
	int _articleNumber;
	std::string _name;

public:
	Article();
	Article(std::string name, int articleNumber, float price);
	~Article();

	float getPrice() const;

	void setPrice(float price);

	int getArticleNumber() const;

	void setArticleNumber(unsigned number);

	std::string getName() const;

	void setName(std::string name);

	virtual void print() const;

	void addTax(float p);

	void edit();

	bool checkAnswer();

	void checkName();

	void checkPrice();

	void checkArticleNumber();

};