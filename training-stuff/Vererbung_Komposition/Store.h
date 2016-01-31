// 1210601015
// Robert Maciejewski
// ue03 bsp10

#include <iostream>
#include "Article.h"
#pragma once

using namespace std;

class Store
{
private:
	Article** aptr;
	int size;

public:
	//Konstruktor
	Store();

	//Destruktor
	~Store();

	//Methoden
	void clear();

	//Fügt einen neuen Artikel hinzu in das Array
	void add(Article* a);

	//schlägt eine Steuer auf den Preis auf
	void codeaddTaxes(float percent);

	//gibt alle Informationen der Artikel aus
	void printAll() const;

	//berechnet den Gesamtpreis aller Artikel
	float computeTotalPrice();

	int countBooks() const;

	int countDVDs() const;

	int countPCs() const;

	Article* get_Article(int articlenumber);

	void printStatistics() const;



};

