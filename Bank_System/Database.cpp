#include <iomanip>
#include "Database.h"

Database::Database(char *file)
{
	filename = NULL;
	setFileName(file);
	records = 0;

	ifstream fin(filename);
	if (!fin.is_open())
	{
		ofstream makeFile(filename);
		makeFile.close();
	}
	else
	{
		countNumberOfRecords();
		fin.close();
	}
}

Database::~Database()
{
	if (filename)
	{
		delete[] filename;
		filename = NULL;
	}
}

void Database::setFileName(char *file)
{
	if (filename != NULL)	delete[] filename;

	int len = strlen(file);
	filename = new char[len + 1];
	for (char i = 0; i < len; i++)	filename[i] = file[i];
	filename[len] = '\0';
}

void Database::countNumberOfRecords()
{
	ifstream fin(filename);
	if (fin.is_open())
	{
		int i = 0;
		string temp;
		while (!fin.eof())
		{
			getline(fin, temp);
			if (temp[0] == '\0')	break;
			i++;
		}
		fin.close();
		records = i;
	}
	else
		records = 0;
}

void Database::getCustomerRecord(BankSystem&obj, int accountNumber)
{
	ifstream fin(filename);

	int ACN = 0, balance;
	char name[20], accountType;
	bool found = false;

	while (!fin.eof())
	{
		fin >> ACN;
		fin >> name;
		if (name[0] == '\0')	break;
		fin >> accountType;
		fin >> balance;

		if (ACN == accountNumber)
		{
			found = true;
			obj.setData(name, accountType, accountNumber, balance);
		}
	}

	fin.close();
	if(!found)
		obj.setData(NULL, '0', -1, -1);
}

void Database::store(BankSystem &obj)
{
	ofstream fout(filename, ios::app);
	fout << obj.getAccountNumber() << " " << obj.getName() << " " << obj.getAccountType() << " " << obj.getCurrentBalance() << endl;
	fout.close();
	records++;
}

void Database::showAll()
{
	ifstream fin(filename);

	int ACN = 0, balance = 0;
	char name[20] = {'\0'}, accountType = 0;

	cout << left << setw(20) << "Account_#" << setw(20) << "Name" << setw(20) << "Type" << "Balance" << endl;
	
	for (int i = 0; i < records; i++)
	{
		fin >> ACN;
		fin >> name;
		if (name[0] == '\0')	break;
		fin >> accountType;
		fin >> balance;

		if(accountType == 's' || accountType == 'S')
			cout << left << setw(20) << ACN << setw(20) << name << setw(20) << "Saving" << balance << endl;
		else
			cout << left << setw(20) << ACN << setw(20) << name << setw(20) << "Current" << balance << endl;
	}
	cout << endl;
	fin.close();
}

void Database::updateBalance(BankSystem &obj)
{
	ifstream fin(filename);
	if (fin.is_open())
	{
		ofstream fout("temp.txt");

		int ACN = 0, balance = 0;
		char name[20] = { '\0' }, accountType = 0;

		for (int i = 0; i < records; i++)
		{
			fin >> ACN;
			fin >> name;
			if (name[0] == '\0')	break;
			fin >> accountType;
			fin >> balance;

			if (ACN != obj.getAccountNumber())
				fout << ACN << " " << name << " " << accountType << " " << balance << endl;
		}
		
		fout << obj.getAccountNumber() << " " << obj.getName() << " " << obj.getAccountType() << " " << obj.getCurrentBalance() << endl;

		fout.close();
		fin.close();
		
		if (remove(filename) != 0)
			cout << "\nDelete operation failed" << endl;

		rename("temp.txt", filename);

	}
}