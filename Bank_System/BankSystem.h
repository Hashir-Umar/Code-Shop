#pragma once

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class BankSystem
{
	char *name;
	char accountType;
	int accountNumber;
	int balance;
	char *fileName;

public:
	BankSystem(char*, char, int, int);
	BankSystem();
	~BankSystem();

	void showData();
	void withdraw(const int&);
	void deposit(const int&);
	void setName(char*);
	void setData(char*, char, int, int);

	char *getName();
	char getAccountType();
	int getAccountNumber();
	int getCurrentBalance();
};

