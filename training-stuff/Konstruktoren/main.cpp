#include <iostream>
#include <cassert>
#include "IntArray.h"
#include "IntArrayShallowCopy.h"

using namespace std;

int main(int argc, char* argv[]) {

	cerr << "###################### Debug 1 #######################\n";
	cerr << "Hier wird der Defaultkonstruktor fuer a1(2) aufgerufen\n";
	IntArray* a1 = new IntArray(3);			//Defaultkonstruktor
	cerr << "########################################################\n\n";

	cerr << "###################### Debug 2 #######################\n";
	// mem[0] is set to 1! (because of the reference operator &)
	cerr << "Aufrufen der Funktion getat() von Objekt a1 fuer die Stelle 0 = 1 und 1 = 8\n";
	a1->getAt(0) = 1;
	a1->getAt(1) = 8;
	a1->getAt(2) = 5;
	/*a1.setAt(0, 1);
	a1.setAt(1, 2);*/
	cerr << "########################################################\n\n";

	cerr << "###################### Debug 3 #######################\n";
	cerr << "Hier wird fuer das Objekt a2 der Copykonstruktor aufgerufen und mit den Werten von a1 initialisiert\n";
	cerr << "Fuer a1 wird noch der Assignment-Konstruktor aufgerufen\n";
	IntArray a2(*a1);
	cerr << "Aufrufen der Funktion getat() fuer das Objekt a2 fuer die Stelle 0 = 2\n";
	a2.getAt(0) = 2;
	a1->getAt(0) = 3;
	a1->print();
	a2.print();
	cin.get();
	cerr << "#########################################################\n\n";

	cerr << "###################### Debug 4 #######################\n";
	cerr << "Hier wird der Defaultkonstruktor fuer das Objekt a3 aufgerufen und das Array mit einer groesse von 2 initialisiert\n";
	IntArray* a3 = new IntArray(2);
	cerr << "Hier wird der Assignment Operator aufgerufen und die Werte von a3 mit den Werten von a2 ueberschrieben\n";
	a3 = &a2;
	cerr << "Hier wird a3 an der Stelle 0 der Wert 3 zugewiesen\n";
	a3->getAt(0) = 3;
	cerr << "#########################################################\n\n";

	cerr << "###################### Debug 5 #######################\n";
	//Ausgabe aller Werte von den 3 Objekten
	cerr << "Ausgabe aller Werte der 3 Objekte\n";
	a1->print();
	a2.print();
	a3->print();
	cerr << "#########################################################\n\n";

	cerr << "###################### Debug 6 #######################\n";
	cerr << "Hier wird der Assignment-Konstruktor aufgerufen\n";
	a3 = a3;
	a3->print();
	cerr << "#########################################################\n";

	*a1 = a2 = *a3;
	a1->print();
	a2.print();
	a3->print();

	// Aufgabe d)
	a1->modifyArray(1, 17);
	a1->print();
	a2.print();
	a3->print();

	cerr << "###################### Debug 7 #######################\n";
	cerr << "Erstellen von 2 kuenstlichen Bugs\n";

	// (a) ... bei einer Kopie des Arrays per implizitem default copy constructor die Manipulation der Elemente
	// des Original - Arrays auch zu ver¨anderten Elementen in der Kopie führt!(Bug1)
	IntArrayShallowCopy shallowArr1(2);
	shallowArr1.getAt(0) = 1;
	shallowArr1.getAt(1) = 2;

	IntArrayShallowCopy *shallowArr2 = new IntArrayShallowCopy(shallowArr1);
	shallowArr2->modifyArray(0, 2);
	shallowArr1.print();

	// (b) ... bei einer Zuweisung eines Arrays an ein anderes per assignment operator ebenso eine Änderung
	// des Original - Arrays eine Änderung der Kopie bewirkt. (Bug2)
	IntArrayShallowCopy* shallowArr3 = &shallowArr1;
	shallowArr3->modifyArray(0, 4);
	shallowArr1.print();

	cerr << "#########################################################\n";
	
	return 0;
}
