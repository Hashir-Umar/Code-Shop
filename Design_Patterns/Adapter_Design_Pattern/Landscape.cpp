#include "Landscape.h"
#include <iostream>

Landscape::Landscape(double area)
{
	this->area = area;
}

void Landscape::render()
{
	std::cout << "Rendering Mountain Scene" << std::endl;
}
