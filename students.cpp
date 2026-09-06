#include <iostream>
#include <string>
#include "definitions.h"
#include "print.h"
using namespace std;
void addStudent(Students* &spisok, int &col){
	Students* add_spisok = new Students[col + 1];
	for (int i = 0; i < col; i++) {
		add_spisok[i] = spisok[i];
	}
	cout << "Введите фамилию студента: ";
	cin >> add_spisok[col].secondName;
	cout << "Введите имя студента: ";
	cin >> add_spisok[col].firstName;
	cout << "Введите группу студента: ";
	cin >> add_spisok[col].group;
	cout << "Введите оценки студента через пробел: ";
	for (int i = 0; i < N; i++) cin >> add_spisok[col].marks[i];
	delete[] spisok;
	spisok = add_spisok;
	col++;
	cout << endl << "Добавлен студент: \n";
	printStudent(spisok[col - 1]);
}

void delCurrentStudent(int del_index, Students* &spisok, int& col) {
	Students* delList = new Students[col - 1];
	for (int i = 0, j = 0; i < col; i++) {
		if (del_index == i) continue;
		delList[j++] = spisok[i];
	}
	delete[] spisok;
	spisok = delList;
	col--;
}

void delStudent(Students* &spisok, int &col){
	string studentSName;
	cout << "Введите фамилию студента: ";
	cin >> studentSName;
	char choice;
	for (int i = 0; i < col; i++) {
		if (studentSName == spisok[i].secondName) {
			printStudent(spisok[i]);
			cout << "Удаляем студента (Y/N?): ";
			cin >> choice;
			if (choice == 'y' || choice == 'Y' || choice == 'у' || choice == 'У') {
				delCurrentStudent(i, spisok, col);
				i--;
				cout << "Студент удален!\n\n";
			}
		}
	}
}

void findStudent(Students* spisok, int col){
	string studentSName;
	cout << "Введите фамилию студента: ";
	cin >> studentSName;
	int colStudents = 0;
	for (int i = 0; i < col; i++) {
		if (studentSName == spisok[i].secondName) {
			printStudent(spisok[i]);
			colStudents++;
		}
	}
	if (colStudents == 0) cout << "Студент с фамилией " << studentSName << " не найден!\n";
}