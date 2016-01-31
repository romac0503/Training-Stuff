/* (c) Stefan Huber, 2012.
Created for the course "Datenstrukturen and Algorithmen" in SoSe12.
Adapted by Gerhard Mitterlechner for SoSe13 with permission of S.Huber.
*/

#ifndef array_h
#define array_h


#include <cassert>
#include <iostream>
#include <ostream>
#include <algorithm>
#include <vector>

using namespace std;

template<class T>
class Array
{
	/** Points to the actual memory */
	T* memory;
	/** Counts the number of elements saved */
	int count;
	/** Counts the number of elements for which we reserved memory */
	int capacity;

	/** helper function for sorting elements */
	bool lowerThan(T elem1, T elem2)
	{
		return (elem1 < elem2); 
	}

public:

	/** Initialize empty array */
	Array(unsigned initialsize = 0);
	/** Copy constructor */
	Array(const Array<T>& cpy);
	/** Initialize array with C-style array */
	Array(T arr[], unsigned size);
	~Array();

	/** Get element at specific position */
	const T& operator[](unsigned idx) const;
	/** Get element at specific position */
	T& operator[](unsigned idx);

	/** Assignment operator */
	Array<T>& operator=(const Array<T>& cpy);
	/** Adding an element to the array */
	Array<T>& operator+=(const T& element);
	/** Concatenate other array */
	Array<T>& operator+=(const Array<T>& other);
	/** Concatenating two elements */
	Array<T> operator+(const Array<T>& cpy) const;

	/** Test auf Elementweise Übereinstimmung **/
	bool operator==(const Array<T>& other) const;

	bool operator!=(const Array<T>& other) const;


	/** gibt zurück wie oft das Element vorkommt **/
	int count_elem(const T& elem);

	/** Return the size of the array */
	unsigned size() const
	{
		return count;
	}

	/** Remove element at specific position */
	void remove(unsigned idx);
	/** Remove all elements and free memory */
	void clear();

	/** dreht die Reihenfolge der Arrays um **/
	void reverse();

	/** gibt die einzelnen Elemente im Array aus **/
	void get_elements();

	/** gibt zurueck ob das Array vollstaendig enthalten ist **/
	int findSubArr(const Array<T>& arr);

	/** gibt ein neues Sub Array zurück*/
	Array<T> getSubArr(unsigned fromIdx, unsigned length);

	/** entfernt alle vorkommende Elemente die im Array vorkommen und schließt die
	Lücken durch elementweise nach vorne kopieren */
	void removeElement(const T& element);

	/** prüft ob alle Elemente nur einmal im Array vorkommen */
	bool allUnique();

	/** prüft ob alle Elemente im Array gleich sind */
	bool allEqual();

	/** gibt jedes n-te element im Array zurück */
	Array<T> getEveryNthElement(unsigned n);

	/** gibt die Anzahl der verschiedenen Elemente zurück */
	int countDistinctElements();

	/** gibt ein Array mit unterschiedlichen Elementen zurück */
	Array<T> getDistinctElements();

private:
	/** Resize the array to new capacity */
	void resize(unsigned newcapacity);

	template<class U>
	friend std::ostream& operator<<(std::ostream& os, const Array<U>& arr);
};


template<class T>
std::ostream& operator<<(std::ostream& os, const Array<T>& arr)
{
	os << "[ " << arr.count << " (" << arr.capacity << ") @ " <<
		arr.memory << ": ";

	for (unsigned i = 0; i<arr.size(); ++i)
	{
		os << arr[i];
		if (i < arr.size() - 1)
			os << ", ";
	}

	return os;
}

template<class T>
Array<T>::Array(unsigned initialsize) :
memory(0),
count(0),
capacity(0)
{
	if (initialsize > 0)
	{
		cout << "Konstruktor aufgerufen" << endl;
		resize(initialsize);
	}	
}


template<class T>
Array<T>::Array(const Array<T>& cpy) :
memory(0),
count(0),
capacity(0)
{
	cout << "Copyconstructor aufgerufen!" << endl;
	// Reserve memory
	resize(cpy.size());

	// Copy data
	count = cpy.count;
	for (int i = 0; i < count; ++i)
		memory[i] = cpy[i];
}


template<class T>
Array<T>::Array(T arr[], unsigned size) :
memory(0),
count(0),
capacity(0)
{
	// Get memory
	resize(size);

	// Copy elements
	count = size;
	for (unsigned i = 0; i<size; ++i)
		memory[i] = arr[i];
}


template<class T>
Array<T>::~Array()
{
	cout << "Destructor aufgerufen" << endl;
	clear();
}


template<class T>
const T& Array<T>::operator[](unsigned idx) const
{
	assert(idx < size());
	return memory[idx];
}


template<class T>
T& Array<T>::operator[](unsigned idx)
{
	assert(idx < size());
	return memory[idx];
}



template<class T>
Array<T>& Array<T>::operator=(const Array<T>& cpy)
{
	cout << "assignment operator aufgerufen" << endl;
	// without the self-assignment check, 
	// if we call 'cpy = cpy', we would clear the array
	if (this == &cpy)
		return *this;

	// Deallocate and allocate memory
	clear();
	cout << "size = " << cpy.size() << endl;
	resize(cpy.size());

	// Copy elements
	count = cpy.size();
	for (unsigned i = 0; i<cpy.size(); ++i)
		memory[i] = cpy.memory[i];

	return *this;
}


template<class T>
Array<T>& Array<T>::operator+=(const T& element)
{
	// If array does not have enough capacity, double the capacity
	// Note that 2*0 is still 0
	if (size() + 1 > capacity)
		resize(1 + 2 * capacity);

	// Save the new element
	memory[count] = element;
	count++;
}


template<class T>
Array<T>& Array<T>::operator+=(const Array<T>& other)
{
	// Increase capacity
	if (size() + other.size() > capacity)
		resize(size() + other.size());

	// Copy elements
	for (unsigned i = 0; i < other.size(); i++)
		memory[i + size()] = other[i];
	count += other.size();
}


template<class T>
Array<T> Array<T>::operator+(const Array<T>& cpy) const
{
	Array<T> old(*this);
	old += cpy;
	return old;
}


/** a) hier wird das Objekt auf Gleichheit verglichen **/
template<class T>
bool Array<T>::operator==(const Array<T>& other) const
{
	if (count != other.count)
	{
		return false;
	}
	else
	{
		for (int i = 0; i<count; i++)
		{
			if (memory[i] != other.memory[i]) return false;
		}
	}
	return true;
}

/** b) hier wird das Objekt auf Ungleichheit verglichen **/
template<class T>
bool Array<T>::operator!=(const Array<T>& other) const
{
	if (*this == other)
		return false;
	else
		return true;
}



template<class T>
void Array<T>::remove(unsigned idx)
{
	assert(idx < size());

	// Move the tail one step to the head
	for (unsigned i = idx; i<size() - 1; i++)
		memory[i] = memory[i + 1];

	// Decrease the size by one
	count--;

	// Free some memory
	// I do not choose capacity/2 since we can force the array to incessantly
	// reallocate memory by a sequence of inserts/removes.
	// I only decrease capacity if capacity is large enough. Otherwise we get
	// many reallocates when the array has only a few elements (If it wouldn't
	// be a demo I would set the lower bound to 4096/sizeof(T) or something
	// similar.
	if (count <= capacity / 2 && capacity > 8)
		resize(capacity / 2 + capacity / 4);
}

/** Ausgeben der Elemente im Array **/
template<class T>
void Array<T>::get_elements()
{
	if (count != 0)
	{
		for (int i = 0; i<count; i++) cout << "Element[" << i << "]\t" << memory[i] << endl;
	}
}

template<class T>
void Array<T>::resize(unsigned newcapacity)
{
	std::cerr << "    [dbg] resize to " << newcapacity << std::endl;

	assert(size() <= newcapacity);

	T* newmem = 0;

	// Reserve new memory, if newcapacity is > 0
	// Note: if newcapacity > 0 ==> size() > 0
	if (newcapacity > 0)
		newmem = new T[newcapacity];

	//Copy old elements -- for basic types, like int, we could use memcpy. But
	//not in general!
	for (unsigned i = 0; i<size(); ++i)
		newmem[i] = memory[i];

	// Remove old memory
	if (capacity > 0)
	{
		assert(memory != 0);
		delete[] memory;
	}

	memory = newmem;
	capacity = newcapacity;
}


/** c) zaehlt die Haeufigkeit der angegebenen Elements **/
template<class T>
int Array<T>::count_elem(const T& element)
{
	int counter = 0;
	for (int i = 0; i < count; i++)
	{
		if (element == memory[i])
		{
			counter++;
		}
	}
	return counter;
}

/** d) dreht die Elemente im Array um **/
template<class T>
void Array<T>::reverse()
{
	T temp;
	if (count != 0)
	{
		for (int i = 0; i<count / 2; i++)
		{
			temp = memory[i];
			memory[i] = memory[(count - 1) - i];
			memory[(count - 1) - i] = temp;
		}
	}
}

/** e) gibt zurueck, ob das vollstaendige Array enthalten ist **/
template<class T>
int Array<T>::findSubArr(const Array<T>& arr)
{

	if (arr.count == 0) return -1;

	if (count == 0) return -1;

	if (arr.count > count) return -1;

	if ((arr.count <= count) && (arr.count != 0))
	{
		for (int i = 0; i<arr.count; i++)
		{
			for (int j = 0; j<count; j++)
			{
				cout << "Debug4\n";
				cout << "memory[" << j << "] = " << memory[j] << endl;
				if (arr.memory[i] != memory[j]) continue;
				else if (arr.memory[i] == memory[j])
				{
					cout << "Debug3\n";
					cout << "arr.memory[" << i << "] = " << arr.memory[i] << endl;
					cout << "memory[" << j << "] = " << memory[j] << endl;
					int k = j;
					int counter = 0;
					for (int l = 0; l <= arr.count; l++)
					{
						cout << "Debug5\n";
						if (counter == arr.count)
						{
							cout << "Debug1\n";
							return k - arr.count;
						}
						if (arr.memory[l] != memory[k])
						{
							cout << "Debug2\n";
							cout << "arr.memory[" << k << "] = " << arr.memory[l] << endl;
							cout << "memory[" << l << "] = " << memory[k] << endl;
							return -1;
						}
						else
						{
							k++;
							counter++;
						}
					}
				}
			}
			cout << "Debug3\n";
			return -1;
		}

	}
}

template<class T>
Array<T> Array<T>::getSubArr(unsigned fromIdx, unsigned length)
{
	if (fromIdx <= size())
	{
		if (length != 0 && (fromIdx + length) < size())
		{
			T* arr = new T[length];

			for (unsigned i = fromIdx, j = 0; j < length; i++, j++)
			{
				arr[j] = memory[i];
			}

			Array<T> newSubArr(arr, length);
			
			delete[] arr;
			arr = 0;
			
			return newSubArr;
		}
	}
}

template<class T>
void Array<T>::removeElement(const T& element)
{
	int counter = 0;
	unsigned int newSize = 0;

	if (memory != 0)
	{
		for (unsigned int i = 0; i < size(); i++)
		{
			if (memory[i] == element)
			{
				counter++;
			}
		}

		if (counter > 0)
		{
			newSize = size() - counter;
			T* newArr = new T[newSize];
			int j = 0;

			for (unsigned int i = 0; i < size(); i++)
			{
				if (memory[i] != element)
				{
					newArr[j] = memory[i];
					j++;
				}
			}

			clear();
			resize(newSize);
			counter = newSize;

			for (unsigned int i = 0; i < newSize; i++)
			{
				memory[i] = newArr[i];
			}

			count = counter;

			delete[] newArr;
			newArr = 0;
		}
	}
}

template<class T>
bool Array<T>::allUnique()
{
	if (count != 0)
	{
		if (count >= 2)
		{
			for (unsigned int i = 0; i < size() - 1; i++)
			{
				for (unsigned int j = i + 1; j < size(); j++)
				{
					if (memory[i] == memory[j])
					{
						return false;
					}
				}
			}
			return true;
		}
		return true;
	}
}

template<class T>
bool Array<T>::allEqual()
{
	T element;

	if (count != 0)
	{
		element = memory[0];

		if (count >= 2)
		{
			for (unsigned int i = 1; i < size(); i++)
			{
				if (element != memory[i])
				{
					return false;
				}
			}
			return true;
		}
	}
}

template<class T>
Array<T> Array<T>::getEveryNthElement(unsigned n)
{
	if (n > 1) 
	{ 
		if (count != 0)
		{
			if (n > size())
			{
				T* tmpArr = new T[1];
				tmpArr[0] = memory[0];

				Array<T> newArr(tmpArr, 1);

				delete[] tmpArr;
				tmpArr = 0;

				return newArr;
			}
			else
			{
				for (unsigned int i = 0; i < size(); i++)
				{
					unsigned newSize = (int)(size() / n);

					if (newSize != 0)
					{
						T* tmpArr = new T[newSize];
						int counter = 0;

						for (int j = 0; j < size(); j++)
						{
							int temp = j + 1;

							if (temp % n == 0 && j <= size())
							{
								tmpArr[counter] = memory[j];
								counter++;
							}
						}

						Array<T> newArr(tmpArr, newSize);

						delete[] tmpArr;
						tmpArr = 0;

						return newArr;
					}

				}
			}
		}
	}
}

template<class T>
int Array<T>::countDistinctElements()
{
	int counter = 0;

	if (size() != 0)
	{
		counter = 1;
		
		vector<T> elements(memory, memory + size());
		T element = elements.at(0);
		sort(elements.begin(), elements.end());

		for (vector<T>::iterator it = elements.begin() + 1; it != elements.end(); ++it)
		{
			if (*it != element)
			{
				element = *it;
				counter++;
			}
		}
	}
	return counter;
}

template<class T>
Array<T> Array<T>::getDistinctElements()
{
	int counter = 0;

	if (size() != 0)
	{
		counter = 1;

		vector<T> elements(memory, memory + size());
		T element = elements.at(0);
		sort(elements.begin(), elements.end());

		for (vector<T>::iterator it = elements.begin() + 1; it != elements.end(); ++it)
		{
			if (*it != element)
			{
				element = *it;
				counter++;
			}
		}

		T* tmpArr = new T[counter + 1];

		int i = 0;

		for (vector<T>::iterator it = elements.begin(); it != elements.end(); ++it)
		{
			if (*it != element)
			{
				tmpArr[i] = *it;
				element = *it;
				i++;
			}
		}

		Array<T> newArr(tmpArr, counter);
		delete[]  tmpArr;
		tmpArr = 0;

		return newArr;
	}
}


template<class T>
void Array<T>::clear()
{
	//Set number of elements to zero so that we can call resize(0)
	count = 0;
	//Resize(0) simply frees old memory
	resize(0);
}



#endif




