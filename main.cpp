#include <iostream>
#include <iomanip>
#include <string>
#include <Windows.h>
#include <fstream>
#include <sstream>
#include "definitions.h"
#include "print.h"
#include "students.h"
#include "file.h"
using namespace std;


int menu() {
	cout << endl;
	cout << "\nВыберите вариант:\n";
	cout << "1 - добавить студента\n";
	cout << "2 - удалить студента\n";
	cout << "3 - вывести список отличников(> 75 % отличных оценок)\n";
	cout << "4 - вывести список двоечников(> 50 % оценок 2 и 3)\n";
	cout << "5 - вывести список студентов, отсортированный по фамилии\n";
	cout << "6 - вывести список студентов определенной группы, отсортированный по фамилии\n";
	cout << "7 - вывести список студентов, отсортированный по среднему баллу(отличники первые)\n";
	cout << "8 - поиск по фамилии студента\n";
	cout << "9 - сохранить данные в файл\n";
	cout << "10 - загрузить данные из файла\n";
	cout << "11 - выход\n";
	int choice;
	cout << "Ваш вариант: ";
	cin >> choice;
	while (choice > 11 || choice < 1) {
		cout << "Неверный вариант. Повторите ввод: ";
		cin >> choice;
	}
	cout << endl;
	return choice;
}



void end(Students* spisok, int col){
	char choice;
	cout << "Завершение работы...Желаете ли сохранить изменения в файл (Y/N?): ";
	cin >> choice;
	if (choice == 'Y' || choice == 'y' || choice == 'У' || choice == 'у') saveFile(spisok, col);
}

int main(){
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	ifstream input("data.txt");
	if (!input.is_open()) { 
		cout << "Ошибка открытия файла\n";
		system("pause");
		return 0;
	}
	int n;
	input >> n;
	Students* list = new Students[n];
	for (int i = 0; i < n; i++) {
		string str;
		input >> str;
		parsing(str, list[i]);
		printStudent(list[i]);
	}
	input.close();
	while (true) {
		int choice = menu();
		switch (choice) {
			case 1:addStudent(list, n); break;
			case 2:delStudent(list, n); break;
			case 3:printGoodStudents(list, n); break;
			case 4:printBadStudents(list, n); break;
			case 5:printSortSnameStudents(list, n); break;
			case 6:printGrpStudents(list, n); break;
			case 7:printSortMidMarkStudents(list, n); break;
			case 8:findStudent(list, n); break;
			case 9:saveFile(list, n); break;
			case 10:loadFile(list, n); break;
			case 11:end(list, n); delete[] list; return 0;
		}
	}
	return 0;
}