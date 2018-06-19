#include <iostream>
#include <conio.h>
#include "WeatherStation.h"
#include "Mobile.h"
#include <cstdlib>
#include <ctime>
#include <conio.h>


int main()
{
	WeatherStation ws(47);
	Mobile MB[3];

	for (int i = 0; i < 3; i++)
		ws.addOb(&MB[i]);
	
	double t;
	int i = 1;

	while (i++)
	{
		std::cout << "\t\t\t\t\t     Weather Station    \n\n";
		std::cout << "\t\t\t\t\t        ********        \n";
		std::cout << "\t\t\t\t\t     **************     \n";
		std::cout << "\t\t\t\t\t   ******************   \n";
		std::cout << "\t\t\t\t\t  ********************  \n";
		std::cout << "\t\t\t\t\t ********************** \n";
		std::cout << "\t\t\t\t\t************************\n";
		std::cout << "\t\t\t\t\t ********************** \n";
		std::cout << "\t\t\t\t\t  ********************  \n";
		std::cout << "\t\t\t\t\t     **************     \n";
		std::cout << "\t\t\t\t\t        ********        \n";
		std::cout << "\t\t\t\t\t     **************     \n";
		std::cout << "\t\t\t\t\t  ********************  \n";
		std::cout << "\t\t\t\t\t ********************** \n";
		std::cout << "\t\t\t\t\t************************\n\n";
		std::cout << "\t\t\t\t   Weather Station Temperature: ";
		
		if (i == 2)
		{
			std::cin >> t;
			if (t < 9 || t > 99)
				t = 50;
			ws.setTemperature(t);
			ws.notify();
		}
		else
			std::cout << ws.getTemp() << std::endl;

		double t1 = MB[0].getTemperature();
		double t2 = MB[1].getTemperature();
		double t3 = MB[2].getTemperature();

		std::cout << "\n\t\t       Mobile 1       \t        Mobile 2      \t        Mobile 3      \n";
		std::cout << "\t\t**********************\t**********************\t**********************\n";
		std::cout << "\t\t*                    *\t*                    *\t*                    *\n";
		std::cout << "\t\t*   Temperature: " << t1 << "  *\t*   Temperature: " << t2 << "  *\t*   Temperature: " << t3 << "  *\n";
		std::cout << "\t\t*                    *\t*                    *\t*                    *\n";
		std::cout << "\t\t**********************\t**********************\t**********************\n";
		std::cout << "\t\t*  |1|   |2|   |3|   *\t*  |1|   |2|   |3|   *\t*  |1|   |2|   |3|   *\n";
		std::cout << "\t\t*  |4|   |5|   |6|   *\t*  |4|   |5|   |6|   *\t*  |4|   |5|   |6|   *\n";
		std::cout << "\t\t*  |7|   |8|   |8|   *\t*  |7|   |8|   |8|   *\t*  |7|   |8|   |8|   *\n";
		std::cout << "\t\t**********************\t**********************\t**********************\n";
		
		std::cout << "Update Temperature: ";
		std::cin >> t;

		if (t < 9 || t > 99)
			t = 50;
		ws.setTemperature(t);
		ws.notify();

		system("cls");
	}

	return 0;
}