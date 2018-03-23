#pragma once
#include "BankSystem.h"

class Database
{
	char *filename;
	int records;

public:
	Database(char*);
	~Database();

	void countNumberOfRecords();
	void setFileName(char*);
	void store(BankSystem&);
	void getCustomerRecord(BankSystem&, int);
	void updateBalance(BankSystem&);
	void showAll();
};

