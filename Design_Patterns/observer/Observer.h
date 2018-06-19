#pragma once
#include <iostream>

class Subject;

class Observer
{
public:
	virtual void update(Subject*) = 0;
	virtual ~Observer(){}
};