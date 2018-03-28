#pragma once
#include <iostream>

class MyQueue
{
	int *arr;
	unsigned int size;
	unsigned int rear;

public:

	//Constructors
	MyQueue();	//Constructor with no Parameter
	MyQueue(const unsigned int&);		//Copy Constructor
	MyQueue(const MyQueue&);			//Constructor with one Parameter
	~MyQueue();	//Destructor

	//Queue Related Functions
	int dequeue();
	void queue(const int&);
	bool isEmpty() const;
	bool isFull() const;

	//setters
	void fitToCurrentSize();
	void setSize(const unsigned int&);

	//Getters
	int getFrontVal() const;
	int getRearVal() const;
	unsigned int getSize() const;
	void getArray() const;
};
