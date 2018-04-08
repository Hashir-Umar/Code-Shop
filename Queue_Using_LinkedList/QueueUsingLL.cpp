#include "QueueUsingLL.h"

QueueUsingLL::QueueUsingLL(int s)
{
	rear = -1;
	front = 0;
	max_size = s;
}


QueueUsingLL::~QueueUsingLL()
{
	rear = -1;
	front = 0;
	max_size = 0;
}

bool QueueUsingLL::isEmpty()
{
	return obj.isEmpty();
}

bool QueueUsingLL::isFull()
{
	return (rear == max_size - 1 || front == max_size);
}

void QueueUsingLL::enqueue(int item)
{
	if (isFull())
		cout << "\nQueue is Full!!";
	else
	{
		obj.insertAtTail(item);
		++rear;
	}
}

int QueueUsingLL::dequeue()
{
	if (isEmpty())
		cout << "\nQueue is Empty!!";
	else
	{
		if (front != rear + 1)
		{
			front++;
			return obj.deleteFromHead();
		}
		else
			cout << "\nQueue is Empty!!";
	}
	return -1;
}

void QueueUsingLL::display()
{
	obj.display();
}