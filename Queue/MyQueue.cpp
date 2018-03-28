#include "MyQueue.h"

//Constructor with one Parameter
MyQueue::MyQueue(const unsigned int& mySize)
{
	rear = 0;
	size = mySize;
	if (size == 0) { std::cout << "\nSize can't be Zero :( Size has been set to 10"; size = 10; system("pause>nul"); }
	arr = new int[size];
}
//Constructor with no Parameter
MyQueue::MyQueue()
{
	rear = 0;
	size = 10;
	arr = new int[size];

	std::cout << "\nSince You dont give Size of the stack Queue size is 10" << std::endl;
	system("pause>nul");
}
//Copy Constructor
MyQueue::MyQueue(const MyQueue& st)
{
	rear = st.rear;
	size = st.size;
	arr = new int[size];

	for (unsigned int i = 0; i < rear; i++)
		arr[i] = st.arr[i];
}
MyQueue::~MyQueue()
{
	delete[] arr;
	rear = 0;
	size = 0;
}

//Queue Related Functions
bool MyQueue::isEmpty() const
{
	return rear == 0;
}
bool MyQueue::isFull() const
{
	return size == rear;
}
int MyQueue::dequeue()
{
	if (!isEmpty())
	{
		int front = arr[0];
		for (unsigned int i = 1; i < rear; i++)
			arr[i - 1] = arr[i];
		rear--;
		return front;
	}
	else
	{
		std::cout << "\nQueue is Empty!!!" << std::endl;
		system("pause>nul");
		return 0;
	}
}
void MyQueue::queue(const int &value)
{
	if (!isFull())
		arr[rear++] = value;
	else
	{
		std::cout << "\nQueue is Full!!!" << std::endl;
		system("pause>nul");
	}
}

//Increases the size of Stack to Given size
void MyQueue::setSize(const unsigned int &newSize)
{
	//Since new size should be greater then orignal size
	if (newSize > size)
	{
		int *temp = new int[newSize];

		for (unsigned int i = 0; i < rear; i++)
			temp[i] = arr[i];

		delete[] arr;
		arr = temp;
		size = newSize;
	}
	else
		std::cout << "\nSize is Too Small" << std::endl;
}

//Shrink Orignal size to current Size
void MyQueue::fitToCurrentSize()
{
	if (rear > 1)
	{
		int *temp = new int[rear];

		for (unsigned int i = 0; i < rear; i++)
			temp[i] = arr[i];

		delete[] arr;
		arr = temp;
		size = rear;
	}
	else
		std::cout << "\nSize Should Be greater then 1" << std::endl;
}

//Getters
int MyQueue::getFrontVal() const
{
	if(!isEmpty())
		return arr[0];

	std::cout << "\nQueue is Empty!!!" << std::endl;
	system("pause>nul");
	return 0;
}
int MyQueue::getRearVal() const
{
	if (!isEmpty())
		return arr[rear-1];

	std::cout << "\nQueue is Empty!!!" << std::endl;
	system("pause>nul");
	return 0;
}
unsigned int MyQueue::getSize() const
{
	return size;
}
void MyQueue::getArray() const
{ 
	if (!isEmpty())
	{
		std::cout << "[ ";
		for (unsigned int i = 0; i < rear - 1; i++)
			std::cout << arr[i] << ", ";
		std::cout << arr[rear - 1] << " ]";
	}
	else
	{
		std::cout << "\nQueue is Empty!!!" << std::endl;
		system("pause>nul");
	}
}
