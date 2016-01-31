#include "SList.h"

SList::SList()
{
	head = 0;
	tail = 0;
}

SList::SList(string val)
{
	head = 0;
	tail = 0;

	Node* n = new Node;
	n->val = val;
	n->next = tail;

	head = n;
	tail = n;
	tail->next = 0;
}

SList::SList(Node* node)
{
	head = node;
	tail = node;
	tail->next = 0;
}

SList::~SList()
{
	if (head != 0)
	{
		clear();
	}
}

SList& SList::operator=(const SList& other)
{
	if (this == &other)
	{
		return *this;
	}

	head = 0;
	tail = 0;
	Node* otherNode = other.head;

	while (otherNode != other.tail)
	{
		push_back(otherNode->val);
		otherNode = otherNode->next;
	}

	if (otherNode == other.tail)
	{
		push_back(otherNode->val);
	}

	if (other.head == other.tail)
	{
		Node* n = new Node;
		n->val = other.head->val;
		head = n;
		tail = head;
		tail->next = 0;
	}
	otherNode = 0;

	return *this;
}

bool SList::operator==(const SList& other)
{
	if (head != 0 && other.head != 0)
	{
		Node* pre = head;
		Node* preOther = other.head;

		while (pre != tail || preOther != other.tail)
		{
			if (pre->val == preOther->val)
			{
				pre = pre->next;
				preOther = preOther->next;

				if ((pre->next == tail && preOther->next != other.tail)
					|| pre->next != tail && preOther->next == other.tail)
				{
					return false;
				}
			}
			else
			{
				return false;
			}
		}
		if (pre->val == preOther->val)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	else
	{
		return false;
	}
}

bool SList::operator!=(const SList& other)
{
	if (head != 0 && other.head != 0)
	{
		Node* pre = head;
		Node* preOther = other.head;

		while (pre != tail || preOther != other.tail)
		{
			if (pre->val != preOther->val)
			{
				return true;

				pre = pre->next;
				preOther = preOther->next;
			}
			else if (pre->val == preOther->val)
			{
				if (((pre->next == tail && preOther->next != other.tail)
					|| pre->next != tail && preOther->next == other.tail))
				{
					return true;
				}
				pre = pre->next;
				preOther = preOther->next;
			}
		}
	}
	else
	{
		return true;
	}
}

SList& SList::operator+(const Node& node)
{
	if (node.val == "")
	{
		return *this;
	}
	else
	{
		push_back(node.val);
	}
	return *this;
}

SList& SList::operator+(const SList& other)
{
	if (other.head != 0)
	{
		this->append(other);
		return *this;
	}
	return *this;
}

SList& SList::operator+=(const Node& node)
{
	if (node.val == "")
	{
		return *this;
	}
	else
	{
		push_back(node.val);
	}
	return *this;
}

SList& SList::operator+=(const SList& other)
{
	if (other.head != 0)
	{
		this->append(other);
		return *this;
	}
	return *this;
}

SList::SList(const SList& other)
{
	*this = other;
}

void SList::push_front(string val)
{
	Node* n = new Node;
	n->val = val;
	n->next = head;
	head = n;

	if (n->next == 0)
	{
		tail = n;
	}
}

void SList::push_front(Node* n)
{
	n->next = head;
	head = n;

	if (n->next == 0)
	{
		tail = n;
	}
}

Node* SList::findFirst(string val)
{
	if (head == 0 || head == tail)
	{
		return 0;
	}
	else
	{
		Node* first = head;
		while (first->val != val)
		{
			first = first->next;
			if (first->next == tail)
			{
				return 0;
			}
		}
		return first;
	}
}

void SList::pop_front()
{
	//Works even if list becomes empty
	Node *n = head;
	assert(n != 0);
	head = n->next;
	delete n;
}

void SList::push_back(string val)
{
	if (head != 0)
	{
		Node* pre = head;

		while (pre != tail)
		{
			pre = pre->next;
		}

		Node* n = new Node;
		n->val = val;
		n->next = 0;
		tail->next = n;
		tail = n;
	}
	else if (head == 0)
	{
		Node* n = new Node;
		n->val = val;
		n->next = 0;
		this->head = n;
		this->tail = n;
	}
}

void SList::push_back(Node* n)
{
	if (head != 0)
	{
		Node* pre = head;

		while (pre != tail)
		{
			pre = pre->next;
		}

		n->next = 0;
		tail->next = n;
		tail = n;
	}
	else if (head == 0)
	{
		n->next = 0;
		head = n;
		tail = n;
	}
}

void SList::pop_back()
{
	if (head != 0)
	{
		Node* n = tail;
		Node* pre = head;

		if (head == tail)
		{
			pop_front();
		}
		else
		{
			while (pre->next != n)
			{
				pre = pre->next;
			}

			delete n;
			n = 0;

			tail = pre;
			pre->next = 0;
		}
	}
}

Node* SList::getPrevNode(Node* curr)
{
	if (head == 0)
	{
		return 0;
	}
	else if (curr == head)
	{
		return head;
	}
	else
	{
		Node* pre = head;

		while (pre->next != 0)
		{
			if (pre->next->val == curr->val)
			{
				return pre;
			}
			pre = pre->next;
		}
		return 0;
	}
}

Node* SList::remove(Node& curr)
{
	if (head == 0)
	{
		return 0;
	}

	Node* n = head;

	while (n->val != curr.val)
	{
		if (n == tail)
		{
			return 0;
		}
		n = n->next;
	}
	Node* pre = getPrevNode(n);
	pre->next = n->next;
	delete n;
	n = 0;

	return pre->next;
}

bool SList::removeAfter(Node* curr)
{
	if (head == 0 || head == tail)
	{
		return 0;
	}

	Node* after = head;
	Node* n = head;

	while (after->val != curr->val)
	{
		if (after == tail)
		{
			return 0;
		}
		after = after->next;
		n = n->next;
	}

	// checking if after isn't tail
	if (after != tail)
	{
		after = after->next;
		if (after == tail)
		{
			pop_back();
			return 1;
		}
		else
		{
			Node* temp = remove(*after);
			n->next = temp;
			return 1;
		}
	}
	else
	{
		return 0;
	}
}

bool SList::removeAll(string& val)
{
	if (head == 0)
	{
		return 0;
	}

	Node* pre = head;
	Node* curr = 0;

	while (pre->next != tail)
	{
		if (pre->val == val)
		{
			pop_front();
			pre = head;
		}
		if (pre->next->val == val)
		{
			Node* toDelete = 0;
			toDelete = pre->next;
			curr = toDelete->next;
			delete toDelete;
			pre->next = curr;
		}
		else
		{
			pre = pre->next;
		}
	}

	if (pre->next == tail && tail->val == val)
	{
		pop_back();
	}
	if (head == tail && head->val == val)
	{
		pop_front();
	}
}

void SList::clear()
{
	while (head != 0)
	{
		pop_front();
	}
}

string SList::getVal()
{
	string val = "";

	Node* n = head;

	for (; n != 0; n = n->next)
	{
		val += n->val;
	}
	return val;
}

SList& SList::append(const SList& other)
{
	if (other.head != 0)
	{
		Node* n = other.head;

		while (n != 0)
		{
			this->push_back(n->val);
			n = n->next;
		}
		return *this;
	}
	return *this;
}

SList SList::getReversed()
{
	if (head != 0 || head != tail)
	{
		SList newList;
		Node* pre = head;

		while (pre != 0)
		{
			newList.push_front(pre->val);
			pre = pre->next;
		}
		return newList;
	}
	else
	{
		return *this;
	}
}

bool SList::isFirst(Node* n1, Node* n2)
{
	for (Node* pre = head; pre != 0; pre = pre->next)
	{
		if (pre == n1)
		{
			return true;
		}
		else if (pre == n2)
		{
			return false;
		}
	}
}

// a helper function that checks
// different cases 
// case 1: the nodes are right after each other
// case 2: the nodes are not next to each other
// case 3: both nodes are at the end of the List
// case 4: both nodes are at the beginning of the List
// case 5: the List consists of just the two nodes

void SList::doSwap(Node* n1, Node* n2)
{
	Node* after1 = n1->next;
	Node* after2 = n2->next;
	Node* pre1 = getPrevNode(n1);
	Node* pre2 = getPrevNode(n2);

	if (n1 == head && after1 == tail)	// checking if List has just Node1 and Node2
	{
		n1->next = 0;
		n2->next = head;
		head = n2;
		tail = n1;
	}
	else if (pre2 == n1)		// check if the nodes are next to each other
	{
		if (n2->next == 0)	 // checks if the n2 is the tail
		{
			n1->next = 0;
			pre1->next = n2;
			n2->next = n1;
			tail = n1;
		}

		else if (n1 == head && after1 == n2)   // check if first Node is head and second Node right next to
		{
			Node* temp = head;
			n1->next = 0;
			n1->next = after2;
			n2->next = n1;
			head = n2;
		}
		else
		{
			n1->next = after2;
			n2->next = 0;
			pre1->next = n2;
			n2->next = n1;
		}
	}
	else
	{
		// here I am checking if first Node is the head and if there are Nodes in between the second Node
		// therefore the pointer at the end has to be handled differently 
		if (n1 == head)
		{
			n1->next = 0;
			n2->next = after1;
			pre2->next = n1;

			if (n2 != tail)
			{
				n1->next = after2;
			}
			head = n2;
		}
		else
		{
			if (n2 == tail)
			{
				n1->next = 0;
				pre2->next = 0;
				n2->next = after1;
				pre1->next = n2;
				pre2->next = n1;
			}
			else
			{
				pre1->next = n2;
				pre2->next = 0;
				n2->next = after1;

				Node* temp = after1;

				while (temp->next != 0)	 // will add all the Nodes between first and second Node
				{
					temp = temp->next;
				}

				n1->next = 0;
				temp->next = n1;
				n1->next = after2;
			}
		}
	}

}

void SList::swap(Node* node1, Node* node2)
{
	if (node1 != node2)
	{
		Node* pre1;
		Node* pre2;
		Node* after1;
		Node* after2;


		if (isFirst(node1, node2))
		{
			pre1 = getPrevNode(node1);
			pre2 = getPrevNode(node2);

		}
		else
		{
			Node* temp = node1;
			node1 = node2;
			node2 = temp;

			after1 = node1->next;
			after2 = node2->next;
			pre1 = getPrevNode(node1);
			pre2 = getPrevNode(node2);
		}

		if (pre1 != 0 && pre2 != 0)
		{
			doSwap(node1, node2);
		}
	}
	else
	{
		cout << "node1 and node2 are the same" << endl;
	}
}