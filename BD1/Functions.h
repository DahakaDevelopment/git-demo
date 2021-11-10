#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <windows.h>

using namespace std;

struct Initial {
	string surname,
		name,
		patronymic;
};

struct Date {
	int day,
		month,
		year;
};

struct Data {
	Initial _initial;
	Date _date;
};

void DataEntry(Data* (&d), int& n);
void ReadingData(Data* (&d), int& n, string fileName);
void Print(Data* d, int n);
void DataChange(Data* (&d), int n);
void DeleteData(Data* (&d), int& n);
void Copy(Data* (&d_n), Data* (&d_o), int n);
void Copy(Data& d_n, Data& d_o);
void AddDate(Data* (&d), int &n);
void DataSorting(Data *d, int n);
void SavingData(Data* d, int n, string fileName);

