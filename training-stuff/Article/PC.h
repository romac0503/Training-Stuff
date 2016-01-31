#pragma once
#include "Article.h"
#include "OS.h"

class PC : public Article
{
private:
	OS _os;

public:
	PC();
	PC(std::string name, int articleNumber, float price, OS os) : Article(name, articleNumber, price){}

	void getOS() const;
	void setOS(unsigned os);
	void edit();
	void print() const;
};