#include "Functions.h"

int _stateMenu;

void Menu() {
	cout << "Выберите действие:" << endl
		<< "(0) Выход из программы" << endl
		<< "(1) Ввод данных" << endl
		<< "(2) Вывод" << endl
		<< "(3) Изменение" << endl
		<< "(4) Выборочное удаление" << endl
		<< "(5) Удаление всех файлов" << endl
		<< "(6) Добавление" << endl
		<< "(7) Сортировка по фамилии" << endl
		<< "(8) Сохранение в Input.txt" << endl
		<< "Ваш выбор: ";
	cin >> _stateMenu;
}

int main() {
	// руссификация консоли ввода и вывода 
	SetConsoleCP(1251); // установка кодовой страницы win-cp 1251 в поток ввода
	SetConsoleOutputCP(1251); // утсановка кодов страницы win-cp 1251 в поток вывода

	Menu();

	// инициализация данных
	int _actions,
		amountOfData = 0;
	string fileName;

	// массив данных
	Data* d = new Data[amountOfData];
	while (_stateMenu != 0) {

		switch (_stateMenu)
		{
		case 1:
			system("cls"); // очистка консоли
			cout << "Ввод вручную или из Input.txt(1 - вручную, 2 - из Input.txt): ";
			cin >> _actions;
			system("cls");

			if (_actions == 1) {
				//ввод вручную
				DataEntry(d, amountOfData);
			}
			if (_actions == 2){
				//ввод из файла
				/*
				В случае ввода файла с данными
				cout << "" << endl;
				cin >> fileName;//Input.txt
				*/
				ReadingData(d, amountOfData, "Input.txt");
			}

			if (_actions != 1 && _actions != 2) {
				cout << "Данные введены неверно!" << endl;
			}

			system("pause"); // задержка консоли
			system("cls");
			Menu();
			break;
			////////////////////////////////////
		case 2:
			system("cls");

			if (amountOfData != 0) {
				Print(d, amountOfData);
			}
			else
				cout << "Данные пусты!" << endl;

			system("pause");
			system("cls");
			Menu();
			break;
			////////////////////////////////////
		case 3:
			system("cls");

			if (amountOfData != 0) {
				DataChange(d, amountOfData);
			}
			else
				cout << "Данные пусты!" << endl;

			system("pause");
			system("cls");
			Menu();
			break;
			////////////////////////////////////
		case 4:
			system("cls");

			if (amountOfData != 0) {
				DeleteData(d, amountOfData);
			}
			else
				cout << "Данные пусты!" << endl;

			system("pause");
			system("cls");
			Menu();
			break;
			////////////////////////////////////
		case 5:
			system("cls");

			amountOfData = 0;
			d = new Data[amountOfData];

			cout << "Данные удалены!" << endl;
			system("pause");
			system("cls");
			Menu();
			break;
			////////////////////////////////////
		case 6:
			system("cls");

			if (amountOfData != 0) {
				AddDate(d, amountOfData);
				amountOfData++;
			}
			else
				cout << "Данные пусты!" << endl;

			system("pause");
			system("cls");
			Menu();
			break;
			////////////////////////////////////
		case 7:
			system("cls");

			if (amountOfData != 0) {
				DataSorting(d, amountOfData);
			}
			else
				cout << "Данные пусты!" << endl;

			system("pause");
			system("cls");
			Menu();
			break;
			////////////////////////////////////
		case 8:
			system("cls");

			//cout << "Введите название файла: ";
			//cin >> fileName;
			fileName = "Input.txt";

			if (amountOfData != 0) {
				SavingData(d, amountOfData, fileName);
				cout << "Данные сохранены!" << endl;
			}
			else
				cout << "Данные пусты!" << endl;

			system("pause");
			system("cls");
			Menu();
			break;
			////////////////////////////////////
		default:
			cout << "Неверно введен номер действия!" << endl;
			system("pause");
			system("cls");
			Menu();
			break;
		}
	}
}