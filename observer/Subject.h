#pragma once

#include <algorithm>
#include "Observer.h"
#include <vector>
class Subject
{
protected:
	std::vector <class Observer*> list;
public:
	virtual void addOb(Observer*);
	virtual void removeOb(Observer*);
	virtual void notify();
	virtual ~Subject(){}
};

void Subject::addOb(Observer *obs)
{
	list.push_back(obs);
}
void Subject::removeOb(Observer *obs)
{
	list.erase(std::remove(list.begin(), list.end(), obs), list.end());
}
void Subject::notify()
{
	for (int i = 0; i < list.size(); i++)
		list[i]->update(this);
}

