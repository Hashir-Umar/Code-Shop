#pragma once
#include "Observer.h"
#include "WeatherStation.h"

class Mobile :
	public Observer
{
	double temperature;

public:

	void update(Subject *S)  { temperature = ((WeatherStation*)S)->getTemp(); }
	double getTemperature(){ return temperature; }
	~Mobile(){}
};

