#pragma once

#include <assert.h>
#include <string>
#include <iostream>
#include "NodeStruct.h"

using namespace std;

class CircularList
{

private:
	Node* head;
	Node* tail;


public:
	CircularList();
	CircularList(string val);
	CircularList(Node* node);

	// Destructor
	~CircularList();

	// Deep Copy Constructor
	CircularList(const CircularList& other);

	// Assignment Operator
	CircularList& operator=(const CircularList& other);

	void push_front(string val);
	void push_front(Node* n);
	void pop_front();
	void push_back(string val);
	void push_back(Node* n);
	void pop_back();

	Node* getPrevNode(Node* curr);
	Node* remove(Node& n);
	void clear();
	string getVal();
	void count(unsigned times);

};
