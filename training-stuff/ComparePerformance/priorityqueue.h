/* (c) Stefan Huber, 2012.
Created for the course "Datenstrukturen and Algorithmen" in SoSe12.
Adapted by Gerhard Mitterlechner for SoSe13 with permission of S.Huber.
*/

#ifndef priorityqueue_h
#define priorityqueue_h

#include "dlist.h"

template<typename T>
class PriorityQueue {
private:
	typedef typename DList<T>::Node ListNode;
	DList<T> queue;

public:
	PriorityQueue()
	{};

	bool isEmpty() const {
		return queue.isEmpty();
	}

	void enqueue(const T& val) {
		queue.push_back(val);
	}

	//returns the largest value (assertion fails if empty)
	const T& front() const {
		assert(!queue.isEmpty());
		//get Node with largest value
		ListNode* max = getTopNode();
		return max->value;
	}

	//removes the node with the largest value (assertion fails if empty)
	void dequeue() {
		assert(!queue.isEmpty());
		queue.remove(getTopNode());
	}

private:
	//returns a pointer to the node with the largest value (assertion fails if empty)
	//helper function for dequeue()
	ListNode* getTopNode() const {
		assert(!queue.isEmpty());
		// Get Node with largest value
		ListNode* max = queue.front();
		for (ListNode* n = max->getNext(); n != 0; n = n->getNext())
			if (max->value < n->value)
				max = n;
		return max;
	}
};


#endif
