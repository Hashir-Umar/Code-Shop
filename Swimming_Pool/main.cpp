#include <iostream>
#include "SwimmingPool.h"

using namespace std;

int main()
{
	double l, w, d, fR, dR;
	int choice;

	cout << "Enter Details:- " << endl;
	cout << "\n\tLength: ";
	cin >> l;
	cout << "\tWidth: ";
	cin >> w;
	cout << "\tDepth: ";
	cin >> d;
    	cout << "\tFilling Rate: ";
	cin >> fR;
	cout << "\tDraining Rate: ";
	cin >> dR;

	SwimmingPool obj(l, w, d, fR, dR);

	while (true)
	{
		system("cls");
        
		cout << "1) Get Current Water Level" << endl;
		cout << "2) Get total capacity" << endl;
		cout << "3) Add Water" << endl;
		cout << "4) Drain Water" << endl;
		cout << "5) Time to fill complete Pool?" << endl;
		cout << "6) Time to Drain complete Pool?" << endl;
		cout << "7) Exit" << endl;
		cout << "\nPress: ";
		cin >> choice;

		system("cls");

		if(choice == 1)
			cout << obj.getCurrentWaterLevel() << endl;
		else if (choice == 2)
			cout << obj.getCapacityOfThePool() << endl;
		else if (choice == 3)
		{
			cout << "For How Long(Time in minutes): ";
			cin >> l;
			obj.addWaterInSpecificTime(l);
			cout << "New Water Level: " << obj.getCurrentWaterLevel() << endl;
		}
		else if (choice == 4)
		{
			cout << "For How Long(Time in minutes): ";
			cin >> l;
			obj.drainWaterInSpecificTime(l);
			cout << "New Water Level: " << obj.getCurrentWaterLevel() << endl;
		}
		else if (choice == 5)
			cout << "Pool Will be filled in: " << obj.getTimeToFillThePool() << " Minutes." << endl;
		else if (choice == 6)
			cout << "Pool Will be drained in: " << obj.getTimeToDrainThePool() << " Minutes." << endl;
		else if (choice == 7)
			return 0;

		system("pause");
	}

	return 0;
}
