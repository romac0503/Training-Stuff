#include <stdio.h>

#pragma once

class MyString
{
private:
	char* data;
	unsigned int size;
	void clear();

public:
	/* Default Constructor */
	MyString();

	MyString(const char* arr);

	/* Copy Constructor */
	MyString(const MyString& other);

	/* Assignment Operatro*/
	MyString& operator=(const MyString& other);

	/* Destructor */
	~MyString();

	/* Methods */
	char get(unsigned int i) const;
	void set(unsigned int i, char c);
	void print() const;
	void append(const MyString& otherStr);
	bool check_index(unsigned int idx) const;
	bool check_IsEmpty() const;

};