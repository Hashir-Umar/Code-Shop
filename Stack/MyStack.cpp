#include "MyStack.h"
#include <iomanip>

//Constructor with one Parameter
MyStack::MyStack(const unsigned int& mySize)
{
	index = 0;
	size = mySize;
	if (size == 0) { std::cout << "\nSize can't be Zero :( Size has set to 10"; size = 10; system("pause>nul"); }
	arr = new int[size];
}
//Constructor with no Parameter
MyStack::MyStack()
{
	index = 0;
	size = 10;
	arr = new int[size];

	std::cout << "\nSince You do not give Size of the stack So Stack size is 10";
	system("pause>nul");
}
//Copy Constructor
MyStack::MyStack(const MyStack& st)
{
	index = st.index;
	size = st.size;
	arr = new int[size];

	for (unsigned int i = 0; i < index; i++)
		arr[i] = st.arr[i];
}
MyStack::~MyStack()
{
	delete[] arr;
	index = 0;
	size = 0;
}

//Stack Related Functions
bool MyStack::isEmpty() const
{
	return index == 0;
}
bool MyStack::isFull() const
{
	return size == index;
}
int MyStack::pop()
{
	if (!isEmpty())
		return arr[--index];
	else
	{
		std::cout << "\nStack is Empty!!!" << std::endl;
		system("pause>nul");
		return 0;
	}
}
void MyStack::push(const int &value)
{
	if (!isFull())
		arr[index++] = value;
	else
	{
		std::cout << "\nStack is Full!!!" << std::endl;
		system("pause>nul");
	}
}

//Setters
void MyStack::setSize(const unsigned int &newSize)
{
	if (newSize > index)
	{
		int *temp = new int[newSize];

		for (unsigned int i = 0; i < index; i++)
			temp[i] = arr[i];

		delete[] arr;
		arr = temp;
		size = newSize;
	}
	else
		std::cout << "\nSize is Too Small" << std::endl;
}
void MyStack::fitToCurrentSize()
{
	if (index > 1)
	{
		int *temp = new int[index];

		for (unsigned int i = 0; i < index; i++)
			temp[i] = arr[i];

		delete[] arr;
		arr = temp;
		size = index;
	}
	else
		std::cout << "\nSize Should Be greater then 1" << std::endl;
}

//Getters
unsigned int MyStack::getIndex() const
{
	return index;
}
unsigned int MyStack::getSize() const
{
	return size;
}
void MyStack::getArray()
{
	if (!isEmpty())
	{
		for (int i = index - 1; i >= 0; i--)
		{
			std::cout << std::left << std::setw(10) << "[";
			std::cout << std::left << std::setw(10) << arr[i];
			std::cout << "]" << std::endl;
		}
	}
	else
	{
		std::cout << "\nStack is Empty!!!" << std::endl;
		system("pause>nul");
	}
}