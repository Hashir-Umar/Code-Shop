#include "SwimmingPool.h"

SwimmingPool::SwimmingPool(double l, double w, double d, double RF, double RD, double CW)
{
	length = l;
	width = w;
	depth = d;
	rateOfFilling = RF;
	rateOfDraining = RD;
	currntWaterInThePool = CW;
}
SwimmingPool::~SwimmingPool()
{
	length = 0.0;
	width = 0.0;
	depth = 0.0;
	rateOfFilling = 0.0;
	rateOfDraining = 0.0;
    	currntWaterInThePool = 0.0;
}

double SwimmingPool::getLength()
{
	return length;
}
double SwimmingPool::getWidth()
{
	return width;
}
double SwimmingPool::getDepth()
{
	return depth;
}
double SwimmingPool::getRateOfFilling()
{
	return rateOfFilling;
}
double SwimmingPool::getRateOfDraining()
{
	return rateOfDraining;
}
double SwimmingPool::getCurrentWaterLevel()
{
	return currntWaterInThePool;
}

void SwimmingPool::setLength(double l)
{
	length = l;
}
void SwimmingPool::setWidth(double w)
{
	width = w;
}
void SwimmingPool::setDepth(double d)
{
	depth = d;
}
void SwimmingPool::setRateOfFilling(double rf)
{
	rateOfFilling = rf;
}
void SwimmingPool::setRateOfDraining(double rd)
{
	rateOfDraining = rd;
}
void SwimmingPool::setCurrentWaterLevel(double c)
{
	currntWaterInThePool = c;
}

double SwimmingPool::getCapacityOfThePool()
{
	return (length * width * depth)*7.48052;
}
double SwimmingPool::getCapacityOfThePool(double filled)
{
	return getCapacityOfThePool() - filled;
}
double SwimmingPool::getTimeToFillThePool()
{
	return getCapacityOfThePool() / rateOfFilling;
}
double SwimmingPool::getTimeToDrainThePool()
{
	return currntWaterInThePool / rateOfDraining;
}
double SwimmingPool::addWaterInSpecificTime(double givinTime)
{
	double addedWater = rateOfFilling * givinTime;	//Stooring The Water In Another Variable for Later Use
	currntWaterInThePool = currntWaterInThePool + (addedWater);
    	double poolCapacity = getCapacityOfThePool();
	//In case Of Overflow This If statement Will be Executed
   	if (currntWaterInThePool > poolCapacity)    currntWaterInThePool = poolCapacity;
	return currntWaterInThePool;
}
double SwimmingPool::drainWaterInSpecificTime(double givinTime)
{
	double drainedWater = rateOfDraining * givinTime;		//Stooring The Water In Another Variable for Later Use
	currntWaterInThePool = currntWaterInThePool - (drainedWater);
	//In case Of Underflow This If statement Will be Executed
	if (currntWaterInThePool < 0)  currntWaterInThePool = 0;
	return currntWaterInThePool;
}
