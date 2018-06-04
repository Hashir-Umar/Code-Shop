#include "FlightSimulator.h"
#include "MountainScene.h"

int main()
{
	FlightSimulator obj(new MountainScene(10, 20.87));
	obj.drawScene();

	return 0;
}