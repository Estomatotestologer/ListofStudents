#include "definitions.h"
#include <iostream>
using namespace std;

void printStudent(Students element) {
	cout << element.secondName << " " << element.firstName << " " << "гр." << element.group;
	cout << endl << "Оценки: ";
	for (int i = 0; i < N; i++) cout << element.marks[i] << " ";
	cout << endl;
}

void printGoodStudents(Students* spisok, int col){
	system("cls");
	int colOfGood = 0;
	for (int i = 0; i < col; i++) {
		int exc_mark = 0;
		for (int j = 0; j < N; j++) {
			if (spisok[i].marks[j] == 5 || spisok[i].marks[j] == 4) exc_mark++;
		}
		if (exc_mark > 0.75 * N) {
			if (colOfGood == 0) cout << "Список отличников: \n";
			printStudent(spisok[i]);
			colOfGood++;
		}
	}
	if (colOfGood == 0) cout << "Отличники отсутствуют! \n";
}

void printBadStudents(Students* spisok, int col){
	system("cls");
	int colOfBad = 0;
	for (int i = 0; i < col; i++) {
		int bad_mark = 0;
		for (int j = 0; j < N; j++) {
			if (spisok[i].marks[j] == 2 || spisok[i].marks[j] == 3) bad_mark++;
		}
		if (bad_mark > 0.5 * N) {
			if (colOfBad == 0) cout << "Список двоечников: \n";
			printStudent(spisok[i]);
			colOfBad++;
		}
	}
	if (colOfBad == 0) cout << "Двоечники отсутствуют! \n";
}


void printSortSnameStudents(Students* spisok, int col){
	system("cls");
	Students** bufSpisok = new Students * [col];
	for (int i = 0; i < col; i++) {
		bufSpisok[i] = &spisok[i];
	}
	for (int j = col - 1; j > 0; j--) {
		for (int i = 0; i < j; i++) {
			if (bufSpisok[i]->secondName > bufSpisok[i + 1]->secondName) {
				Students* tmp = bufSpisok[i];
				bufSpisok[i] = bufSpisok[i + 1];
				bufSpisok[i + 1] = tmp;
			}
		}
	}
	cout << "Отсортированный по фамилии список студентов: \n";
	for (int i = 0; i < col; i++) printStudent(*bufSpisok[i]);
	delete[] bufSpisok;
}

void printGrpStudents(Students* spisok, int col){
	system("cls");
	cout << "Введите название группы студентов: ";
	string grp;
	cin >> grp;
	int col_grp = 0;
	for (int i = 0; i < col; i++) {
		if (grp == spisok[i].group) col_grp++;
	}
	if (col_grp == 0) {
		cout << "Группа не найдена в списке!\n";
		return;
	}
	Students** list_grp = new Students * [col_grp];
	for (int i = 0, j = 0; i < col; i++) {
		if (grp == spisok[i].group) list_grp[j++] = &spisok[i];
	}
	for (int j = col_grp - 1; j > 0; j--) {
		for (int i = 0; i < j; i++) {
			if (list_grp[i]->secondName > list_grp[i + 1]->secondName) {
				Students* tmp = list_grp[i];
				list_grp[i] = list_grp[i + 1];
				list_grp[i + 1] = tmp;
			}
		}
	}
	cout << "Список группы " << grp << ": \n";
	for (int i = 0; i < col_grp; i++) printStudent(*list_grp[i]);
	delete[] list_grp;
}

double midMark(Students element) {
	double sum = 0;
	for (int i = 0; i < N; i++) {
		sum += element.marks[i];
	}
	return sum / N;
}

void printSortMidMarkStudents(Students* spisok, int col){
	system("cls");
	Students** list_grp = new Students * [col];
	for (int i = 0; i < col; i++) {
		list_grp[i] = &spisok[i];
	}

	for (int j = col - 1; j > 0; j--) {
		for (int i = 0; i < j; i++) {
			if (midMark(*list_grp[i]) < midMark(*list_grp[i + 1])) {
				Students* tmp = list_grp[i];
				list_grp[i] = list_grp[i + 1];
				list_grp[i + 1] = tmp;
			}
		}
	}
	cout << "Список студентов, отсортированный по среднему баллу: \n";
	for (int i = 0; i < col; i++) printStudent(*list_grp[i]);
	delete[] list_grp;
}