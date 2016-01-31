/* (c) Stefan Huber, 2012.
Created for the course "Datenstrukturen and Algorithmen" in SoSe12.
Adapted by Gerhard Mitterlechner for SoSe13 with permission of S.Huber.
*/

#ifndef dlist_h
#define dlist_h

#include <ostream>
#include <iostream>
#include <cassert>



template <typename T>
class DList
{
public:
	class Node
	{ //inner class
		friend class DList<T>; //DList should have access to private members of Node

	private:
		Node* prev;
		Node* next;
	public:
		T value;

		Node(const T& value) :
			prev(0),
			next(0),
			value(value)
		{
		}

		//returns 0 if no previous node exists
		Node* getPrev() const
		{
			return prev;
		}
		//returns 0 if no next node exists
		Node* getNext() const
		{
			return next;
		}
	};


private:
	Node* head;
	Node* tail;

public:
	DList() :
		head(0),
		tail(0)
	{
	}

	DList(const DList<T>& l) :
		head(0),
		tail(0)
	{
		append(l);
	}

	virtual ~DList()
	{
		clear();
	}

	DList<T>& operator=(const DList<T>& l)
	{
		if (this == &l) //self assignment check
			return *this;

		clear();
		append(l);
		return *this;
	}

	DList<T>& operator+=(const DList<T>& l)
	{
		append(l);
		return *this;
	}

	void push_front(const T& value)
	{
		Node* n = new Node(value);
		n->next = head;
		n->prev = 0;

		if (head != 0)
			head->prev = n;
		else
			tail = n;
		head = n;
	}

	void push_back(const T& value)
	{
		Node* n = new Node(value);
		n->prev = tail;
		n->next = 0;

		if (tail != 0)
			tail->next = n;
		else
			head = n;
		tail = n;
	}

	Node* front() const
	{
		return head;
	}

	Node* back() const
	{
		return tail;
	}

	//removes the first node (assertion fails, when empty)
	void pop_front()
	{
		assert(head != 0);

		Node* n = head;
		if (head == tail)
		{
			head = tail = 0;
		}
		else
		{
			head = head->next;
			head->prev = 0;
		}
		delete n;
	}

	//removes the last node (assertion fails, when empty)
	void pop_back()
	{
		assert(tail != 0);

		Node* n = tail;
		if (head == tail)
		{
			head = tail = 0;
		}
		else
		{
			tail = tail->prev;
			tail->next = 0;
		}
		delete n;
	}

	bool isEmpty() const
	{
		//check integrity of dlist
		assert(head != 0 || tail == 0);
		assert(tail != 0 || head == 0);
		return head == 0;
	}

	void clear()
	{
		while (!isEmpty())
			pop_front();
	}

	void append(const DList<T>& l)
	{
		if (l.isEmpty())
			return;

		// Maybe, l==*this, and hence, we need to recall the original tail
		// to which we walk through.
		DList<T>::Node* n = l.front();
		DList<T>::Node* last = l.back();

		while (true)
		{
			assert(n != 0);
			push_back(n->value);
			if (n == last) break;
			n = n->next;
		}
	}

	//removes the node to which we have already a pointer
	void remove(Node* n)
	{
		if (n == head)
		{
			pop_front();
		}
		else if (n == tail)
		{
			pop_back();
		}
		else
		{
			Node* prev = n->prev;
			Node* next = n->next;
			prev->next = next;
			next->prev = prev;
			delete n;
		}
	}

	//insert a node after a given node 
	void insertAfter(Node* pre, const T& val)
	{
		if (pre == back())
			push_back(val);
		else
		{
			Node* next = pre->next;
			Node* n = new Node(val);
			n->prev = pre;
			n->next = next;
			pre->next = n;
			next->prev = n;
		}
	}
};

template<typename T>
std::ostream& operator<<(std::ostream& os, const DList<T>& l)
{
	os << "[ ";
	for (typename DList<T>::Node* n = l.front(); n != 0; n = n->getNext())
	{
		os << n->value << " ";
	}
	os << "]";
	return os;
}

#endif
