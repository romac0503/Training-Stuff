#pragma once


#include <assert.h>
#include <string>
#include <iostream>
#include "NodeStruct.h"

using namespace std;

class SList
{

private:
	Node* head;
	Node* tail;
	void doSwap(Node* n1, Node* n2);
	bool isFirst(Node* n1, Node* n2);

public:
	SList();
	SList(string val);
	SList(Node* node);

	// Destructor
	~SList();

	// Deep Copy Constructor
	SList(const SList& other);

	// Assignment Operator
	SList& operator=(const SList& other);

	// Even Operator
	bool operator==(const SList& other);

	// Uneven Operator
	bool operator!=(const SList& other);

	// + Operator
	SList& operator+(const Node& node);
	SList& operator+(const SList& other);

	// +/= Operator
	SList& operator+=(const Node& node);
	SList& operator+=(const SList& other);

	void push_front(string val);
	void push_front(Node* n);
	void pop_front();
	void push_back(string val);
	void push_back(Node* n);
	void pop_back();

	Node* findFirst(string val);
	Node* getPrevNode(Node* pre);
	Node* remove(Node& n);
	bool removeAfter(Node* pre);
	bool removeAll(string& val);
	void clear();
	string getVal();
	SList& append(const SList& other);
	SList getReversed();
	void swap(Node* node1, Node* node2);
};

