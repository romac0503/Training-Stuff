// Article.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Article.h"
#include "Book.h"
#include "DVD.h"
#include "PC.h"
#include <list>
#include "MyException.h"

//enum Infos { NO_NAME, NO_PRICE, NO_ARTNUMBER, NO_AUTHOR, NO_GENRE, NO_OS };
enum Genres{ ACTION, WESTERN, DRAMA, COMEDY, SIFI, HORROR };
enum OS_Selection { WINDOWS, MAC, LINUX };


using namespace std;

void showOptions()
{
	cout << "##############################" << endl;
	cout << "########## options ###########" << endl << endl;
	cout << "choose 1 to add a new book: " << endl;
	cout << "choose 2 to add a new dvd: " << endl;
	cout << "choose 3 to add a new pc: " << endl;
	cout << "choose 4 to print all articles: " << endl;
	int option = cin.get();
	switch (option)
	{
	case 1:
		cout << "you want to add a new book" << endl;
		break;
	case 2:
		cout << "you want to add a new dvd" << endl;
		break;
	case 3:
		cout << "you want to add a new pc" << endl;
		break;
	case 4:
		cout << "######## all articles #######" << endl;
		break;
	}
	
}

int main(int argc, char* argv[])
{
	list<Article*> articles;

	Book* book = new Book();
	DVD* dvd = new DVD();
	PC* pc = new PC();

	articles.push_back(book);
	articles.push_back(dvd);
	articles.push_back(pc);

	for (list<Article*>::iterator it = articles.begin(); it != articles.end(); ++it)
		(*it)->print();
	cin.get();

	for (list<Article*>::iterator it = articles.begin(); it != articles.end(); ++it)
	{
		try {
			(*it)->getName();
		}
		catch (MyException e)
		{
			cout << e.what() << endl;
			cin.get();
		}
	}

	book->setName("The book of success");
	book->setAuthor("Robert Maciejewski");
	book->setArticleNumber(1);
	book->setPrice(25);
	book->addTax(20);
	book->print();

	dvd->setName("The secret of my success");
	dvd->setGenre(Genres::ACTION);
	dvd->setArticleNumber(1);

	pc->setName("ASUS");
	pc->setOS(OS_Selection::WINDOWS);
	pc->setArticleNumber(1);
	
	try
	{
		pc->setPrice(-3);
	}
	catch (MyException e)
	{
		cout << e.what() << endl;
		cin.get();
	}

	try
	{
		pc->addTax(0);
	}
	catch (MyException e)
	{
		cout << e.what() << endl;
		cin.get();
	}

	try 
	{
		pc->setPrice(900);
		pc->addTax(20);
	}
	catch (MyException e)
	{
		e.what();
		cin.get();
	}

	try
	{
		dvd->getGenre();
	}
	catch (MyException e)
	{
		e.what();
		cin.get();
	}

	try
	{
		dvd->edit();
	}
	catch (MyException e)
	{
		e.what();
		cin.get();
	}

	return 0;
}




