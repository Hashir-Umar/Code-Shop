#include "BankSystem.h"

BankSystem::BankSystem()
{
	name = NULL;
}

BankSystem::BankSystem(char *N, char AT, int AN, int B)
{
	name = NULL;
	setName(N);
	accountType = AT;
	accountNumber = AN;
	balance = B;

}

BankSystem::~BankSystem()
{
	if (name)
	{
		delete[] name;
		name = NULL;
	}
}

char* BankSystem::getName()
{
	return name;
}

void BankSystem::setName(char *N)
{
	if (N)
	{
		int len = strlen(N);
		name = new char[len + 1];
		for (char i = 0; i < len; i++)	name[i] = N[i];
		name[len] = '\0';
	}
}

int BankSystem::getCurrentBalance()
{
	return balance;
}

int BankSystem::getAccountNumber()
{
	return accountNumber;
}

char BankSystem::getAccountType()
{
	return accountType;
}

void BankSystem::setData(char *N, char AT, int AN, int B)
{
	name = NULL;
	setName(N);
	accountType = AT;
	accountNumber = AN;
	balance = B;
}

void BankSystem::showData()
{
	cout << "\n\nCustomer Details:-" << endl;
	cout << "\n\tName: " << name;
	cout << "\n\tAccount Type: ";
	if (accountType == 's' || accountType == 'S')	cout << "Saving";
	else	cout << "Current";
	cout << "\n\tAccount Number: " << accountNumber;
	cout << "\n\tBalance: " << balance;
}

void BankSystem::withdraw(const int &WD)
{
	int temp = balance - WD;
	if (temp < 0)	
		cout << "\tWithdrawal Amount is too large";
	else
	{
		cout << "\tWithdrawal Done!";
		balance = temp;
	}
}

void BankSystem::deposit(const int &DM)
{
	balance += DM;
	cout << "\n\tDeposit Done!";
}

