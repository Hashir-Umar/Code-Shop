#pragma once
#include <iostream>

class MyString
{
	char *arr;
	unsigned int size;
	char* allocate(const char*);

public:
	MyString();
	MyString(const char*);
	MyString(const char*, unsigned int);
	MyString(const MyString&);
	unsigned int getSize() const;
	MyString& operator=(const MyString&);
	MyString& operator=(const char*);
	MyString& operator=(const char&);
	MyString operator+(const MyString&);
	MyString operator+(const char&);
	friend std::ostream& operator<<(std::ostream& os, const MyString&);
	~MyString();
};

