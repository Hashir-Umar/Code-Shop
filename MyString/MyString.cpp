#include "MyString.h"

MyString::MyString():arr(nullptr), size(0) { }

MyString::MyString(const MyString&myArr)
{
	arr = allocate(myArr.arr);
	for (size = 0; myArr.arr[size] != '\0'; size++);
}

MyString::MyString(const char* copy)
{
	arr = allocate(copy);
	for (size = 0; copy[size] != '\0'; size++);
}

MyString::MyString(const char* copy, unsigned int size)
{
	arr = allocate(copy);
	this->size = size;
}

char* MyString::allocate(const char *copy)
{
	int len = 0;
	for (; copy[len] != '\0'; len++);

	char *orignal = new char[len + 1];

	for (int i = 0; i < len; i++)
		orignal[i] = copy[i];

	return orignal;
}

MyString& MyString::operator = (const MyString&copy)
{
	delete[] arr;

	arr = allocate(copy.arr);
	for (size = 0; arr[size] != '\0'; size++);

	return const_cast<MyString&> (copy);
}

MyString MyString::operator+ (const MyString& append)
{	
	unsigned int totalLen = append.size + size;
	char *orignal = new char[totalLen + 1];

	int i = 0;
	for (; i < size; i++)
		orignal[i] = arr[i];

	int j = 0;
	for (; i <= totalLen; i++)
		orignal[i] = append.arr[j++];

	MyString copy(orignal, totalLen);
	delete[] orignal;

	return copy;
}

MyString MyString::operator+ (const char& appendChar)
{
	char *orignal = new char[size + 2];

	int i = 0;
	for (; i < size; i++)
		orignal[i] = arr[i];

	orignal[i++] = ' ';
	orignal[i] = '\0';

	MyString copy(orignal, size+2);
	delete[] orignal;

	return copy;
}

MyString& MyString::operator = (const char *copyArr)
{
	delete[] arr;
	
	arr = allocate(copyArr);
	for (size = 0; copyArr[size] != '\0'; size++);

	return (*this);
}

MyString& MyString::operator = (const char& copyChar)
{
	delete[] arr;

	arr = new char(copyChar);
	size = 1;

	return (*this);
}

unsigned int MyString::getSize() const
{
	return size;
}

std::ostream& operator<<(std::ostream& os, const MyString& myArr)
{
	std::cout << myArr.arr;
	return os;
}


MyString::~MyString()
{
	delete[] arr;
	arr = nullptr;
	size = 0;
}
