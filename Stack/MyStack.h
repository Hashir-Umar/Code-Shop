#pragma once
#include <iostream>

class MyStack
{	
	int *arr;
	unsigned int size;
	unsigned int index;

public:
	
	//Constructors
	MyStack();	//Constructor with no Parameter
	MyStack(const unsigned int&);		//Copy Constructor
	MyStack(const MyStack&);			//Constructor with one Parameter
	~MyStack();	//Destructor

	//Stack Related Functions
	int pop();
	void push(const int&);
	bool isEmpty() const;
	bool isFull() const;
	
	//setters
	void fitToCurrentSize();
	void setSize(const unsigned int&);

	//getters
	unsigned int getIndex() const;
	unsigned int getSize() const;
	void getArray();
};

