#include "Functions.h"

void DataEntry(Data* (&d), int& n)
{
	cout << "Введите количество данных: ";
	cin >> n;

	d = new Data[n];

	for (int i = 0; i < n; i++) {
		cout << "Введите ФИО: ";
		cin >> d[i]._initial.surname;
		cin >> d[i]._initial.name;
		cin >> d[i]._initial.patronymic;

		cout << "Введите дату (день, месяц, год): ";
		cin >> d[i]._date.day;
		cin >> d[i]._date.month;
		cin >> d[i]._date.year;

		cout << "______________________" << endl;

	}
}

void ReadingData(Data* (&d), int& n, string fileName)
{
	//создаём поток для чтения
	ifstream reading(fileName);

	if (reading) {
		reading >> n;

		d = new Data[n];

		for (int i = 0; i < n; i++) {
			reading >> d[i]._initial.surname;
			reading >> d[i]._initial.name;
			reading >> d[i]._initial.patronymic;

			reading >> d[i]._date.day;
			reading >> d[i]._date.month;
			reading >> d[i]._date.year;
		}
		cout << "Данные считаны!" << endl;
	}
	else
		cout << "Ошибка открытия файла!" << endl;
	reading.close();
}

void Print(Data* d, int n)
{
	for (int i = 0; i < n; i++) {
		cout << "Данные №" << i + 1 << endl;
		cout << "ФИО: " << d[i]._initial.surname << " " << d[i]._initial.name << " " << d[i]._initial.patronymic << endl;
		cout << "Дата: ";
		if (d[i]._date.day <= 9)
			cout << "0" << d[i]._date.day << " ";
		else
			cout << d[i]._date.day << " ";
		if (d[i]._date.month <= 9)
			cout << "0" << d[i]._date.month << " ";
		else
			cout << d[i]._date.month << " ";
		cout << d[i]._date.year << endl;
		cout << "_____________________" << endl;
	}
}

void DataChange(Data* (&d), int n)

{
	int _n;
	cout << "Введите номер элемента (от 1 до " << n << "): ";
	cin >> _n;
	_n--;
	system("cls");

	// проверка, что ввели правильное значение
	if (_n >= 0 && _n < n) {
		cout << "Введите ФИО: ";
		cin >> d[_n]._initial.surname;
		cin >> d[_n]._initial.name;
		cin >> d[_n]._initial.patronymic;

		cout << "Введите дату: ";
		cin >> d[_n]._date.day;
		cin >> d[_n]._date.month;
		cin >> d[_n]._date.year;

		system("cls");

		cout << "Данные изменены!" << endl;
	}
	else
		cout << "Номер введён неверно!" << endl;
}

void DeleteData(Data* (&d), int& n)
{
	int _n;
	cout << "Введите номер элемента (от 1 до " << n << "): ";
	cin >> _n;
	_n--;
	system("cls");

	if (_n >= 0 && _n < n) {
		// временный массив
		Data* buf = new Data[n];

		Copy(buf, d, n);

		// выделяем новую память
		--n;
		d = new Data[n];
		int q = 0;

		// заполняем неудаленные данные
		for (int i = 0; i <= n; i++) {
			if (i != _n) {
				d[q] = buf[i];
				++q;
			}
		}

		system("cls");
		delete[]buf;
		cout << "Данные удалены!" << endl;
	}
	else
		cout << "Номер введён неверно!" << endl;
}

void Copy(Data* (&d_n), Data* (&d_o), int n)
{
	for (int i = 0; i < n; i++) {
		d_n[i] = d_o[i];
	}
}

void Copy(Data& d_n, Data& d_o)
{
	d_n._initial.surname = d_o._initial.surname;
	d_n._initial.name = d_o._initial.name;
	d_n._initial.patronymic = d_o._initial.patronymic;

	d_n._date.day = d_o._date.day;
	d_n._date.month = d_o._date.month;
	d_n._date.year = d_o._date.year;
}

void AddDate(Data* (&d), int& n)
{
	//временный массив данных
	Data* buf;
	buf = new Data[n];

	//сохрание данных во временный массив
	Copy(buf, d, n);

	//выделяем новую память
	n++;
	d = new Data[n];

	//возвращаем данные
	Copy(d, buf, --n);

	cout << "Введите ФИО: ";
	cin >> d[n]._initial.surname >> d[n]._initial.name >> d[n]._initial.patronymic;

	cout << "Введите дату: ";
	cin >> d[n]._date.day >> d[n]._date.month >> d[n]._date.year;

	system("cls");
	cout << "Данные добавлены!" << endl;
	delete[]buf;
}

void DataSorting(Data* d, int n)
{
	//Временная переменная
	Data buf;

	//сортировка методом пузырька
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			if (d[i]._initial.surname > d[j]._initial.surname) {
				Copy(buf, d[j]);
				Copy(d[j], d[i]);
				Copy(d[i], buf);
			}
		}
	}

	cout << "Данные отсортированы!" << endl;
}

void SavingData(Data* d, int n, string fileName)
{
	// создается поток для записи
	// открывает fileName и делает так, чтобы он был пустой
	ofstream record(fileName, ios::out);

	// условие: если файл открылся
	if (record) {
		record << n << endl;

		for (int i = 0; i < n; i++) {
			record << d[i]._initial.surname << endl;
			record << d[i]._initial.name << endl;
			record << d[i]._initial.patronymic << endl;

			record << d[i]._date.day << " ";
			record << d[i]._date.month << " ";
			if (i < n - 1)
				record << d[i]._date.year << endl;
			else
				record << d[i]._date.year;
		}
	}
	else
		cout << "Ошибка открытия файла!" << endl;

	record.close();
}