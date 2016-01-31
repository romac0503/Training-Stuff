// 1210601015
// Robert Maciejewski
// ue03 bsp10

#include <iostream>
#include "Store.h"
#include "Book.h"
#include "DVD.h"
#include "PC.h"
#include "Article.h"

using namespace std;

//Konstruktor
Store::Store() : size(0)
{
	aptr = new Article*[size];
}

Store::~Store()
{
	clear();
}

//Methoden
void Store::clear()
{
	delete[] aptr;
	size = 0;
}

// Funktion zum Hinzufügen eines neuen Objektes
void Store::add(Article* a)
{
	int new_size = size + 1;
	Article** temp = new Article*[new_size];

	if (size == 0)
	{
		temp[0] = a;
	}
	else
	{
		for (int i = 0; i < size; i++)
		{
			temp[i] = aptr[i];
		}
		temp[new_size - 1] = a;
	}

	clear();

	size = new_size;
	aptr = temp;

	temp = 0;
	delete[] temp;
}

// Den Artikel mit der jeweiligen Aritkelnummer zurückgeben
Article* Store::get_Article(int articlenumber)
{
	if (size != 0)
	{
		for (int i = 0; i < size; i++)
		{
			if (articlenumber == aptr[i]->getArticleNumber()) return aptr[i];
			else cout << "Der Artikel mit der Arikelnr: " << articlenumber << " ist nicht vorhanden.\n";
			return NULL;
		}
	}
	return NULL;
}

// Funktion zum Aufschlagen der Steuern zum Preis
void Store::codeaddTaxes(float percent)
{
	if (size != 0)
	{
		for (int i = 0; i < size; i++) aptr[i]->addTax(percent);
	}
}

// Funktion die alle Informationen der gesamten Artikel ausgibt
void Store::printAll() const
{
	if (size != 0)
	{
		for (int i = 0; i < size; i++)
		{
			cout << endl;
			cout << "**********************\n";
			aptr[i]->print();
			cout << "**********************\n\n";
		}
	}
}

// Funktion berechnet den Gesamtpreis aller Artikel
float Store::computeTotalPrice()
{
	float totalPrice = 0.0;
	if (size != 0)
	{
		for (int i = 0; i < size; i++) totalPrice += aptr[i]->getPrice();
	}
	return totalPrice;
}

int Store::countBooks() const
{
	int counter = 0;
	
	if (size != 0)
	{
		for (int i = 0; i < size; i++)
		{
			if (aptr[i] == dynamic_cast<Book*>(aptr[i])) counter++;
		}
	}
	return counter;
}


int Store::countDVDs() const
{
	int counter = 0;
	if (size != 0)
	{
		for (int i = 0; i < size; i++)
		{
			if (aptr[i] == dynamic_cast<DVD*>(aptr[i])) counter++;
		}
	}
	return counter;
}

int Store::countPCs() const
{
	int counter = 0;
	if (size != 0)
	{
		for (int i = 0; i < size; i++)
		{
			if (aptr[i] == dynamic_cast<PC*>(aptr[i])) counter++;
		}
	}
	return counter;
}

// Methode zum Ausgeben des prozentuellen Anteils der Artikel in Store
void Store::printStatistics() const
{
	int amountArticle = 0;
	float percentageBooks = 0.0;
	float percentageDVDs = 0.0;
	float percentagePCs = 0.0;
	if (size != 0)
	{
		for (int i = 0; i < size; i++) amountArticle++;
		percentageBooks = ((float)countBooks() / amountArticle) * 100;
		percentageDVDs = ((float)countDVDs() / amountArticle) * 100;
		percentagePCs = ((float)countPCs() / amountArticle) * 100;
		cout << "Anteil an Buechern(in Prozent):\t" << percentageBooks << "%" << endl;
		cout << "Anteil an DVD\'s(in Prozent):\t" << percentageDVDs << "%" << endl;
		cout << "Anteil an PC\'s(in Prozent):\t" << percentagePCs << "%" << endl;
	}
	else
	{
		cout << "Keine Arikel vorhanden.\n";
	}
}
