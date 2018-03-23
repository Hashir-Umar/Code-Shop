#pragma once

class SwimmingPool
{
	double width;
	double length;
	double depth;
	double rateOfFilling;
	double rateOfDraining;
	double currntWaterInThePool;


public:
	SwimmingPool(double, double, double, double, double, double = 0);
	~SwimmingPool(); 

	double getLength(); 
	double getWidth();
	double getDepth();
	double getRateOfFilling();
	double getRateOfDraining();
	double getCurrentWaterLevel();
    
  	double getTimeToFillThePool();
	double getTimeToDrainThePool();

	double getCapacityOfThePool();
	double getCapacityOfThePool(double);
    
	void setLength(double);
	void setWidth(double);
	void setDepth(double);
	void setRateOfFilling(double);
	void setRateOfDraining(double);
	void setCurrentWaterLevel(double);

	double addWaterInSpecificTime(double);
	double drainWaterInSpecificTime(double);
};

