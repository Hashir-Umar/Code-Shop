#pragma once

#include <iostream>
#include "MyLinkedList.h"

using namespace std;

class QueueUsingLL
{
	MyLinkedList obj;
	int max_size;
	int front;
	int rear;

public:
	QueueUsingLL(int);
	~QueueUsingLL();
	bool isEmpty();
	bool isFull();
	void enqueue(int);
	int dequeue();
	void display();
};

