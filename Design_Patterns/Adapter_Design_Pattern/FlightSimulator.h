#pragma once
#include "Scene.h"

class FlightSimulator
{
private:
	Scene *scene;

public:
	FlightSimulator(Scene*);
	void drawScene();
	~FlightSimulator();
};

