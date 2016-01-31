#include "CircularList.h"

CircularList::CircularList()
{
	head = 0;
	tail = 0;
}



CircularList::CircularList(string name)
{
	head = 0;
	tail = 0;


	if (name != "")
	{
		Node* node = new Node;
		node->val = name;
		head = node;
		tail = head;
	}

}

CircularList::CircularList(Node* node)
{
	head = 0;
	tail = 0;

	if (node->val != "")
	{
		head = node;
		tail = head;
	}
}

CircularList::~CircularList()
{
	if (head != 0)
	{
		clear();
	}
}

void CircularList::push_front(string name)
{
	Node* n = new Node;
	n->val = name;

	// check if no element is head
	if (head == 0)
	{
		head = n;
		tail = head;
	}
	else if (head == tail)
	{
		n->next = tail;
		head = n;
		tail->next = head;
	}
	else 
	{
		Node* temp = head;
		head = n;
		head->next = temp;
		tail->next = head;
	}
}

void CircularList::pop_front()
{
	//Works even if list becomes empty
	Node *n = head;
	assert(n != 0);
	if (head == tail)
	{
		delete n;
		head = 0;
		tail = 0;
	}
	else
	{
		head = n->next;
		delete n;
	}
}

Node* CircularList::getPrevNode(Node* curr)
{
	if (head == 0)
	{
		return 0;
	}
	else
	{
		Node* pre = head;
		if (curr->val == pre->val)
		{
			if (head != tail)
			{
				return tail;
			}
			else
			{
				return 0;
			}
		}
		else
		{
			while (pre->next->val != curr->val)
			{
				pre = pre->next;
			}
			return pre;
		}
	}
}

Node* CircularList::remove(Node& curr)
{
	if (head != tail)
	{
		Node* n = head;
		Node* next;

		while (n->val != curr.val)
		{
			n = n->next;
		}
		next = n->next;

		if (n == head)
		{
			head = n->next;
			tail->next = head;
			delete n;
			n = 0;
			return next;
		}
		else
		{
			if (head->next == tail)
			{
				if (n == tail)
				{
					delete n;
					n = 0;
					tail = head;
					return head;
				}
				else
				{
					delete n;
					n = 0;
					head = tail;
					return head;
				}
			}
			Node* pre = getPrevNode(n);
			pre->next = next;
			delete n;
			n = 0;
			return next;
		}
	}
	return 0;
}



void CircularList::clear()
{
	while (head != 0)
	{
		pop_front();
	}
}

string CircularList::getVal()
{
	string val = "";

	if (head == 0)
	{
		return val;
	}
	else if (head == tail && head != 0)
	{
		val = head->val;
		return val;
	}
	else
	{
		Node* n = head;

		do
		{
			val += n->val;
			n = n->next;
		} while (n != tail->next);

		return val;
	}
}

void CircularList::count(unsigned times)
{
	if (head != 0)
	{
		Node* n = head;
		unsigned counter;

		while (head != tail)
		{
			for (counter = 1; counter < times; counter++)
			{
				cout << n->val;
				if (head == tail)
				{
					break;
				}
				if (counter != times - 1)
					cout << " -> ";

				n = n->next;
			}
			cout << " -> " << n->val << endl;
			cout << n->val << " is going to be removed" << endl << endl;
			Node* next = remove(*n);

			if (next != 0)
			{
				n = next;
				counter = 1;
			}
		}
		cout << endl;
		cout << "###########################" << endl;
		cout << "the last survivor is " << head->val << endl;
		cout << "###########################" << endl;
	}
}

