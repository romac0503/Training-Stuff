/*
Creational Pattern: SINGLETON
Author: Rajesh V.S
Language: C++
Email: rajeshvs@msn.com
*/

#include <iostream>

using namespace std;

class Singleton
{
private:
	static Singleton *single;
	static int numAccesses;
	Singleton()
	{
		//private constructor
	}
public:
	static Singleton* getInstance();
	void method();
	static int getNumAccesses();
	~Singleton()
	{
		numAccesses--;
	}
};

Singleton* Singleton::single = NULL;

Singleton* Singleton::getInstance()
{
	if (single == NULL)
	{
		single = new Singleton();
		numAccesses++;
		return single;
	}
	else
	{
		numAccesses++;
		return single;
	}
}

void Singleton::method()
{
	cout << "Method of the singleton class" << endl;
	cout << "Address of the singleton instance: " << this << endl;
}

int Singleton::getNumAccesses()
{
	return numAccesses;
}

int Singleton::numAccesses = 0;

int main()
{
	Singleton *sc1, *sc2;
	sc1 = Singleton::getInstance();
	cout << "number Accessess: " << sc1->getNumAccesses() << endl;
	sc1->method();
	sc2 = Singleton::getInstance();
	cout << "number Accessess: " << sc2->getNumAccesses() << endl;
	sc2->method();

	delete sc2;
	cout << "deleted one Instance" << endl;
	cout << "number Accessess: " << sc2->getNumAccesses() << endl;

	cout << "Copy-Constructor" << endl;
	Singleton* sc3 = &Singleton(*sc1);
	sc3->method();
	cout << "number Accessess: " << sc2->getNumAccesses() << endl;

	Singleton* sc4 = &Singleton(*sc1);
	sc4->method();
	cout << "number Accessess: " << sc4->getNumAccesses() << endl;

	cin.get();

	return 0;
}
