#pragma once
#include "Subject.h"

class WeatherStation :	public Subject
{
	double temperature;
public:
	WeatherStation(double T){ temperature = T; }
	void setTemperature(double temp){ temperature = temp; }
	double getTemp() { return temperature; }
};


