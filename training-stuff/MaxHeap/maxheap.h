/* (c) Stefan Huber, 2012.
Created for the course "Datenstrukturen and Algorithmen" in SoSe12.
Adapted by Gerhard Mitterlechner for SoSe13 with permission of S.Huber.
*/

#ifndef maxheap_h
#define maxheap_h

#include <algorithm>
#include "array.h"
#include <iostream>
#include <string>

using namespace std;


template <typename T>
class MaxHeap
{
private:
	Array<T> arr;

	template<class U>
	void swap(U& a, U& b)
	{
		U c = b;
		b = a;
		a = c;
	}

public:
	MaxHeap(unsigned capacity = 0) : arr(Array<T>(capacity))
	{
	}

	bool isEmpty() const
	{
		return arr.isEmpty();
	}

	//adds an element to the heap
	void enqueue(const T& val)
	{
		cout << "before enqueue (" << val << "): " << arr << endl;
		//add the new element at the end
		arr.push_back(val);
		//restore the heap, so that the heap-condition is satisfied
		upheap(getLastIdx());
		//cout << "lastIndex = " << getLastIdx() << endl;
		cout << "after enqueue: " << arr << endl;
	}

	//get the largest element (if empty, assertion fails)
	const T& front() const
	{
		assert(!isEmpty());
		return arr[0];
	}

	//remove the largest element
	void dequeue()
	{
		//cout << "before dequeue: " << arr << endl;
		assert(!isEmpty());

		//put the last element in the beginning (root)
		arr[0] = arr[getLastIdx()];
		//remove the old last element (which is now the root)
		arr.pop_back();

		//restore the heap, so that the heap-condition is satisfied
		if (!isEmpty()) downheap(0);
		//cout << "after dequeue: " << arr << endl;
	}

public:
	//returns the index of the last element 
	//warning: must not be called when empty (what happens?)
	unsigned getLastIdx() const
	{
		if (arr.getCount() > 0)
		{
			return arr.getCount() - 1;
		}
		else return NULL;

	}

	//used for enqueue() to restore the heap, so that the heap-condition is satisfied
	void upheap(unsigned idx)
	{
		//IMPLEMENT!
		// while not already at bottom level
		if (idx != 0)
		{
			unsigned parent_idx = idx;
			while (arr[parentIdx(parent_idx)] < arr[parent_idx])
			{
				swap(arr[idx], arr[parentIdx(idx)]);
				parent_idx = parentIdx(idx);
				if (parent_idx == 0)
				{
					break;
				}
				idx = parentIdx(idx);
			}
		}
	}

	//used for dequeue() to restore the heap, so that the heap-condition is satisfied
	void downheap(unsigned idx)
	{
		// while not already at bottom level
		while (leftChildIdx(idx) <= getLastIdx())
		{
			// get the larger child 
			unsigned childIdx = leftChildIdx(idx);
			// if right child exists and is larger...
			if (rightChildIdx(idx) <= getLastIdx() &&
				arr[rightChildIdx(idx)] > arr[leftChildIdx(idx)])
				childIdx = rightChildIdx(idx);

			// if the child is greater, do the swap, otherwise break loop
			if (arr[childIdx] > arr[idx])
			{
				swap(arr[childIdx], arr[idx]);
				idx = childIdx;
			}
			else break;
		}
	}

	//returns the index of the parent node
	unsigned parentIdx(unsigned idx)
	{
		//IMPLEMENT! must work for arrays with starting index 0!
		if (idx == 0)
		{
			return 0;
		}
		else
		{
			if (idx % 2 == 0)
			{
				return (idx / 2) - 1;
			}
			else
			{
				return idx / 2;
			}
			return 0;
		}
	}

	//returns the index of the left child 
	int leftChildIdx(unsigned idx)
	{
		//IMPLEMENT! must work for arrays with starting index 0!

		unsigned lastIdx = getLastIdx();

		if ((idx * 2) + 1 >= lastIdx) return -1;
		else return (idx * 2) + 1;
	}

	//returns the index of the right child
	int rightChildIdx(unsigned idx)
	{
		//IMPLEMENT! must work for arrays with starting index 0!

		if ((idx * 2) + 2 >= getLastIdx()) return -1;
		else return (idx * 2) + 2;
	}

	T getValue(unsigned idx)
	{
		if (idx < arr.getCount() && !arr.isEmpty())
		{
			return arr.getAt(idx);
		}
		else
		{
			cout << "Debug" << endl;
			return NULL;
		}
	}
};


#endif
