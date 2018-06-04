#include "FlightSimulator.h"


FlightSimulator::FlightSimulator(Scene *s)
{
	scene = s;
}

void FlightSimulator::drawScene()
{
	scene->draw();
}

FlightSimulator::~FlightSimulator()
{
	delete scene;
}
