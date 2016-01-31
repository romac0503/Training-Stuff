// Article.cpp : Defines the entry point for the console application.
//


#include "stdafx.h"
#include <vld.h>
#include "Article.h"
#include "Book.h"
#include "DVD.h"
#include "PC.h"
#include "Store.h"
#include "MyException.h"


//enum Infos { NO_NAME, NO_PRICE, NO_ARTNUMBER, NO_AUTHOR, NO_GENRE, NO_OS };
enum Genres
{
	ACTION, WESTERN, DRAMA, COMEDY, SIFI, HORROR
};
enum OS_Selection
{
	WINDOWS, MAC, LINUX
};


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
	unsigned int x = 1;
	cout << (int)(((char *)&x)[0]) << endl;
	printf("%d", (int)(((char *)&x)[0]));
	cin.get();

	Book book("The book of succes", 1, 25, "Robert Maciejewski");
	DVD dvd("Do it!", 2, 15, Genre::ACTION);
	PC pc("ASUS", 3, 1800, OS::WINDOWS);
	Book book2("The book", 4, 40, "Stephen King");

	book.addTax(20);

	Store store;

	store.add(&book);
	store.add(&book2);
	store.add(&dvd);
	store.add(&pc);

	// just for knowledge!!!!!!
	/*int** arr = new int*[3];

	for (int i = 0; i < 3; i++)
	{
		arr[i] = new int;
		*arr[i] = 1 + i;
		cout << "normal array: " << *arr[i] << endl;
	}

	cin.get();

	int** tmpArr = new int*[4];

	for (int i = 0; i < 3; i++)
	{
		int* tmpInt = new int(*arr[i]);
		tmpArr[i] = tmpInt;
		cout << "tmp Arr: " << *tmpArr[i] << endl;
		cin.get();
	}
	tmpArr[3] = new int;
	*tmpArr[3] = 4;

	for (int i = 0; i < 4; i++)
	{
		cout << "tmpArr: " << *tmpArr[i] << endl;
	}

	cin.get();

	for (int j = 0; j < 3; j++)
	{
		cout << "normal Arr: " << *arr[j] << endl;
		delete arr[j];
	}
	delete[] arr;

	arr = new int*[4];

	for (int i = 0; i < 4; i++)
	{
		int* tmpInt = new int(*tmpArr[i]);
		arr[i] = tmpInt;
		cout << "new arr: " << *arr[i] << endl;
	}

	cin.get();

	for (int i = 0; i < 4; i++)
		delete tmpArr[i];
	delete[] tmpArr;*/
	//**********************************************************

	/*for (list<Article*>::iterator it = articles.begin(); it != articles.end(); ++it)
		(*it)->print();
		cin.get();

		for (list<Article*>::iterator it = articles.begin(); it != articles.end(); ++it)
		{
		try
		{
		(*it)->getName();
		}
		catch (MyException e)
		{
		cout << e.what() << endl;
		cin.get();
		}
		}*/

	/*book->setName("The book of success");
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
	cout << e.that() << endl;
	cin.get();
	}

	try
	{
	pc->addTax(20);
	}
	catch (MyException e)
	{
	cout << e.that() << endl;
	cin.get();
	}

	try
	{
	pc->setPrice(900);
	pc->addTax(20);
	}
	catch (MyException e)
	{
	e.that();
	cin.get();
	}

	try
	{
	dvd->getGenre();
	}
	catch (MyException e)
	{
	e.that();
	cin.get();
	}

	try
	{
	dvd->edit();
	}
	catch (MyException e)
	{
	e.that();
	cin.get();
	}*/

	return 0;
}




