// SingleChainedList.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "SList.h"
#include "CircularList.h"
#include <iostream>
#include <vld.h>

void TestPushAndPopFront();
void TestPushAndPopBack();
void TestFindFirst();
void TestGetPrevNode();
void TestRemove();
void TestRemoveAfter();
void TestRemoveAll();
void TestClear();
void TestCopyConstructor();
void TestEvenUnevenOperator();
void TestAppend();
void TestGetReversed();
void TestPlusOperator();
void TestSwap();

void TestCircularListInit();
void TestCircularListCount();

int main(int argc, char* argv[])
{
	TestPushAndPopFront();
	TestPushAndPopBack();
	TestFindFirst();
	TestGetPrevNode();
	TestRemove();
	TestRemoveAfter();
	TestRemoveAll();
	TestClear();
	TestCopyConstructor();
	TestEvenUnevenOperator();
	TestAppend();
	TestGetReversed();
	TestPlusOperator();
	TestSwap();

	TestCircularListInit();
	TestCircularListCount();

	cin.get();

	return 0;
}

void TestPushAndPopFront()
{
	SList myList(" dir?");

	myList.push_front(" wie geht es");
	myList.push_front("Hallo,");

	string msg = myList.getVal();

	assert(msg == "Hallo, wie geht es dir?");

	myList.pop_front();

	msg = myList.getVal();
	assert(msg == " wie geht es dir?");

	cout << "Test Push and Pop Front completed" << endl;
	cin.get();
}

void TestPushAndPopBack()
{
	SList myList("Beam");

	myList.push_back(" me up, Scotty!");
	string msg = myList.getVal();
	assert(msg == "Beam me up, Scotty!");

	myList.pop_back();
	msg = myList.getVal();
	assert(msg == "Beam");

	cout << "Test Push and Pop Back completed" << endl;
	cin.get();
}

void TestFindFirst()
{
	SList myList(" Beam");
	myList.push_back(" me up, Scotty!");
	myList.push_front(" here");
	myList.push_front("Kirk");


	Node* n = myList.findFirst(" here");

	assert(n != 0);
	n = myList.findFirst("Spock");
	assert(n == 0);

	cout << "Test Find First completed" << endl;
	cin.get();
}

void TestGetPrevNode()
{
	SList myList("Beam");
	Node n1;
	Node n2;
	Node n3;
	n1.val = " me up, Scotty!";
	n2.val = " here";
	n3.val = " Kirk";

	myList.push_back(n1.val);
	myList.push_back(n2.val);
	myList.push_back(n3.val);

	Node* n4 = myList.getPrevNode(&n3);
	assert(n4->val == n2.val);

	Node n5;
	n5.val = "Spock";
	Node* n6 = myList.getPrevNode(&n5);
	assert(n6 == 0);

	cout << "Test Get Prev Node completed" << endl;
	cin.get();

}

void TestRemove()
{
	SList myList("Beam");
	Node n1;
	Node n2;
	Node n3;
	n1.val = " me up, Scotty!";
	n2.val = " here";
	n3.val = " Kirk";

	myList.push_back(n1.val);
	myList.push_back(n2.val);
	myList.push_back(n3.val);

	Node* n4 = myList.remove(n1);

	string msg = myList.getVal();
	assert(n4->val == n2.val);

	Node n6;
	n6.val = "Khan";
	Node* n7 = myList.remove(n6);
	assert(n7 == 0);

	cout << "Test Remove completed" << endl;
	cin.get();

}

void TestRemoveAfter()
{
	SList myList("Beam");
	Node n1;
	Node n2;
	Node n3;
	n1.val = " me up, Scotty!";
	n2.val = " here";
	n3.val = " Kirk";

	myList.push_back(n1.val);
	myList.push_back(n2.val);
	myList.push_back(n3.val);

	assert(myList.removeAfter(&n1));
	assert(myList.removeAfter(&n2) == 0);

	cout << "Test Remove after completed" << endl;
	cin.get();
}

void TestRemoveAll()
{
	SList myList("Here");
	Node n1;
	Node n2;
	Node n3;
	n1.val = " Scotty! ";
	n2.val = "Here";
	n3.val = " Kirk.";

	myList.push_back(n1.val);
	myList.push_back(n2.val);
	myList.push_back(n3.val);

	myList.removeAll(n2.val);
	string msg = myList.getVal();
	assert(msg == " Scotty!  Kirk.");

	SList myList2("Test ");
	Node newNode1;
	Node newNode2;
	Node newNode3;

	newNode1.val = "Test ";
	newNode2.val = "Test ";
	newNode3.val = "Test ";

	myList2.push_back(newNode1.val);
	myList2.push_back(newNode2.val);
	myList2.push_back(newNode3.val);

	myList2.removeAll(newNode1.val);
	string msg2 = myList2.getVal();
	assert(msg2 == "");

	cout << "Test Remove all completed" << endl;
	cin.get();
}

void TestClear()
{
	SList myList("Here");
	Node n1;
	Node n2;
	Node n3;
	n1.val = " Scotty! ";
	n2.val = "Here";
	n3.val = " Kirk.";

	myList.push_back(n1.val);
	myList.push_back(n2.val);
	myList.push_back(n3.val);

	myList.clear();
	string msg = myList.getVal();

	assert(msg == "");
	cout << "Test Clear completed" << endl;
	cin.get();
}

void TestCopyConstructor()
{
	SList list1("Hello");
	list1.push_back(" my dear.");
	SList list2(list1);

	list2.push_back(" Baby!");

	string msg1 = list1.getVal();
	string msg2 = list2.getVal();

	assert(msg1 != msg2);
	cout << "Test Copy Constructor completed" << endl;
	cin.get();
}

void TestEvenUnevenOperator()
{
	SList list1("Hello");
	SList list2("Hello");

	assert(list1 == list2);

	SList list3("hello");
	assert(list1 != list2);

	list2.push_back(" Frank!");
	assert(list1 != list2);

	cout << "Test Even/Uneven Operator completed" << endl;
	cin.get();
}

void TestAppend()
{
	SList list1("Nanananananananana");
	SList list2(" BATMAN!!!");

	list1.append(list2);
	string msg = list1.getVal();

	cout << "Test Append completed" << endl;
	cin.get();
}

void TestGetReversed()
{
	SList list1("This ");
	list1.push_back("is ");
	list1.push_back(" awesome!");

	SList list2 = list1.getReversed();
	string msg = list2.getVal();

	cout << "Test Get Reversed completed" << endl;
	cin.get();
}

void TestPlusOperator()
{
	SList list1("Hello");
	SList list2;
	SList list3("Hello");
	Node n1;
	Node n2;
	n1.val = " Bro!";
	n2.val = " Chica!";

	list1 = list1 + list2;
	assert(list1 == list3);

	SList list4(" What's up?");
	list1 += list4;
	string msg = list1.getVal();
	assert(msg == "Hello What's up?");

	list1 = list1 + n1;
	msg = list1.getVal();
	assert(msg == "Hello What's up? Bro!");

	list1.pop_back();
	list1 += n2;
	msg = list1.getVal();
	assert(msg == "Hello What's up? Chica!");

	cout << "Test Plus Operator completed" << endl;
	cin.get();
}

void TestSwap()
{
	Node* n0 = new Node;
	Node* n1 = new Node;
	Node* n2 = new Node;
	Node* n3 = new Node;
	Node* n4 = new Node;
	Node* n5 = new Node;

	n0->val = " 0";
	n1->val = " 1";
	n2->val = " 2";
	n3->val = " 3";
	n4->val = " 4";
	n5->val = " 5";

	SList myList(n0);

	myList.push_back(n1);
	myList.push_back(n2);
	myList.push_back(n3);
	myList.push_back(n4);
	myList.push_back(n5);

	string msg = myList.getVal();

	// Test swapping first and second Node
	myList.swap(n1, n0);
	msg = myList.getVal();
	assert(msg == " 1 0 2 3 4 5");

	// Test swapping with reversed parameters
	myList.swap(n0, n1);
	msg = myList.getVal();
	assert(msg == " 0 1 2 3 4 5");

	myList.swap(n1, n0);
	msg = myList.getVal();
	assert(msg == " 1 0 2 3 4 5");

	myList.swap(n0, n1);

	// Test swapping Nodes that are not next to each other
	myList.swap(n2, n5);
	msg = myList.getVal();
	assert(msg == " 0 1 5 3 4 2");

	myList.swap(n2, n5);

	// Test swapping the last two Nodes
	myList.swap(n4, n5);
	msg = myList.getVal();
	assert(msg == " 0 1 2 3 5 4");

	myList.swap(n4, n5);

	// Test swapping the first in the list and the last in the list
	myList.swap(n0, n5);
	msg = myList.getVal();
	assert(msg == " 5 1 2 3 4 0");

	myList.swap(n0, n5);

	// Test swapping the nodes when just two nodes in the list
	myList.pop_back();
	myList.pop_back();
	myList.pop_back();
	myList.pop_back();

	myList.swap(n0, n1);
	msg = myList.getVal();
	assert(msg == " 1 0");

	cout << "Test Swap completed" << endl;
	cin.get();
}

void TestCircularListInit()
{
	CircularList myCircularList1;
	CircularList myCircularList2("Trevor");

	Node* n1 = new Node;
	n1->val = "Micheal";
	CircularList myCircularList3(n1);

	string msg1 = myCircularList1.getVal();
	string msg2 = myCircularList2.getVal();
	string msg3 = myCircularList3.getVal();

	cout << "List 1: " << msg1 << endl;
	cout << "List 2: " << msg2 << endl;
	cout << "List 3: " << msg3 << endl;
	cin.get();
}

void TestCircularListCount()
{
	CircularList myCircularList;
	myCircularList.push_front("Johnny");
	myCircularList.push_front("Franklin");
	myCircularList.push_front("Trevor");
	myCircularList.push_front("Micheal");

	myCircularList.count(5);
	cin.get();
}

