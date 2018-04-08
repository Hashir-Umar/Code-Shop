#include "CircularLinkList.h"

CircularLinkList::CircularLinkList()
{
	first = NULL;
}

CircularLinkList::~CircularLinkList()
{
	while (!isEmpty())
		deleteFromEnd();
}

bool CircularLinkList::isEmpty()
{
	return first == NULL;
}

void CircularLinkList::insertFirstNode(int x)
{
	Node *temp = new Node(x);
	first = temp;
	first->next = first;
}

void CircularLinkList::insertAtEnd(int x)
{
	if (!isEmpty())
	{
		Node *temp = new Node(x);
		temp->next = first->next;
		first->next = temp;
		first = temp;
	}
	else
		insertFirstNode(x);
}

void CircularLinkList::insertAtFront(int x)
{
	if (!isEmpty())
	{
		Node *temp = new Node(x);
		temp->next = first->next;
		first->next = temp;
	}
	else
		insertFirstNode(x);
}

int CircularLinkList::deleteIfOneNode()
{
	int deletedValue = first->x;
	delete first;
	first = NULL;
	return deletedValue;
}

int CircularLinkList::deleteFromEnd()
{
	if (isEmpty())
	{
		cout << "List is Empty!!!";
		return -1;
	}

	if (first->next == first)
		return deleteIfOneNode();
	else
	{
		int deletedValue = first->x;

		Node *temp = first->next;

		while (temp->next != first)
			temp = temp->next;

		temp->next = first->next;
		delete first;
		first = temp;
		return deletedValue;
	}
}

int CircularLinkList::deleteFromFront()
{
	if (isEmpty())
	{
		cout << "List is Empty!!!";
		return -1;
	}

	if (first->next == first)
		return deleteIfOneNode();
	else
	{
		int deletedValue = first->x;

		Node *temp = first->next;
		first->next = temp->next;
		deletedValue = temp->x;
		delete temp;

		return deletedValue;
	}

}


Node* CircularLinkList::search(int val, Node *startingNode = NULL)
{
	if (startingNode == NULL && !isEmpty())
		startingNode = first->next;

	if (!isEmpty())
	{
		for (Node* temp = startingNode; 1; temp = temp->next)
		{
			if (temp->x == val)
				return temp;

			if (temp->next == first->next)
				break;
		}
	}

	return NULL;
}

void CircularLinkList::display()
{
	if (!isEmpty())
	{
		if (first->next == first)
			cout << first->x << " ";
		else
		{
			Node *st = first->next;
			while (1)
			{
				cout << st->x << " ";
				
				if (first == st)
					break;

				st = st->next;
			}
		}
		cout << endl;
	}
	else
		cout << "\nList is Empty!!!" << endl;
}