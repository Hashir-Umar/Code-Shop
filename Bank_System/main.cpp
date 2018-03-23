#include "BankSystem.h"
#include "Database.h"

void menu(BankSystem&, Database&);

int main()
{
	Database database("data.txt");

	int choice = 0;

	while (true)
	{
		system("cls");

		cout << "1) Open An Account" << endl;
		cout << "2) Already Have An Account" << endl;
		cout << "3) Show All Record" << endl;
		cout << "4) Exit" << endl;
		cout << "\nPress: ";
		cin >> choice;

		system("cls");

		if (choice == 1)
		{
			while (1)
			{
				system("cls");

				string N;
				int ACN, balance;
				char *name, accountType;

				cout << "Enter Account Details:- " << endl;

				cout << "\n\tAccount Number: ";
				cin >> ACN;

				BankSystem customer;
				database.getCustomerRecord(customer, ACN);

				if (customer.getAccountNumber() == -1)
				{
					cout << "\tName: ";
					cin.ignore();
					getline(cin, N);

					//Cpying Index by index
					int len = N.size();
					name = new char[len + 1];
					for (char i = 0; i < len; i++)	name[i] = N[i];
					name[len] = '\0';

					cout << "\tAccount Type {C:Current, S:Saving}: ";
					cin >> accountType;

					cout << "\tDeposit Some Money: ";
					cin >> balance;

					cout << "\nAccout Has Been Made" << endl;
					customer.setData(name, accountType, ACN, balance);
					database.store(customer);
					break;
				}
				else
				{
					cout << "\nAccount Number Already Present In DataBase......" << endl;
					cout << "Try Another" << endl << endl;
					system("pause");
				}
			}
		}
		else if (choice == 2)
		{
			cout << "Enter Your Account Number: ";
			cin >> choice;

			BankSystem customer;
			database.getCustomerRecord(customer, choice);

			if (customer.getAccountNumber() != -1)
				menu(customer, database);
		}
		else if (choice == 3)
			database.showAll();
		else if (choice == 4)
			return 0;

		system("pause");
	}


	return 0;
}

void menu(BankSystem &customers, Database &database)
{
	int choice = 0;
	while (1)
	{
		system("cls");

		cout << "1) Show Data" << endl;
		cout << "2) Current Balance" << endl;
		cout << "3) Withdraw Amount" << endl;
		cout << "4) Deposit Amount" << endl;
		cout << "5) Main Menu" << endl;
		cout << "\nPress: ";
		cin >> choice;

		if (choice == 2 || choice == 3 || choice == 4)
			cout << "\nYour Current Balance: " << customers.getCurrentBalance() << endl;

		if (choice == 1)
			customers.showData();
		else if (choice == 3)
		{
			cout << "\n\tEnter Withdrwal Amount: ";
			cin >> choice;
			customers.withdraw(abs(choice));
			database.updateBalance(customers);
		}
		else if (choice == 4)
		{
			cout << "\n\tEnter Deposit Amount: ";
			cin >> choice;
			customers.deposit(abs(choice));
			database.updateBalance(customers);
		}
		else if (choice == 5)
			break;

		cout << endl << endl;
		system("pause");
	}
}
