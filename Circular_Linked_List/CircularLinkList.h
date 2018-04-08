#pragma once

#include <iostream>

using namespace std;

struct Node
{
	int x;
	Node *next;

	Node() {}

	Node(int value, Node *n = NULL)
	{
		x = value;
		next = n;
	}
};

class CircularLinkList
{
	Node *first;

public:
	CircularLinkList();
	~CircularLinkList();
	bool isEmpty();
	void insertFirstNode(int);
	void insertAtEnd(int);
	void insertAtFront(int);
	int deleteIfOneNode();
	int deleteFromEnd();
	int deleteFromFront();
	Node* search(int, Node *startingNode);
	void display();

};