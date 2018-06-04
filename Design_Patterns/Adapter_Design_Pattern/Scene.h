#pragma once

#include <iostream>

class Scene
{
protected:
	int capture_date;

public:
	Scene(int);
	virtual void draw() = 0;
	virtual ~Scene() { }
};

