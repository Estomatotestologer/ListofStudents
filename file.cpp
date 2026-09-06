#include "definitions.h"
#include "print.h"
#include <fstream>
#include <iostream>
#include <sstream>
using namespace std;
void saveFile(Students* spisok, int col){
	ofstream output("data.txt");
	if (!output.is_open()) {
		cout << "Ошибка открытия файла для записи\n";
		system("pause");
		return;
	}
	output << col << endl;
	for (int i = 0; i < col; i++) {
		output << spisok[i].secondName << ";" << spisok[i].firstName << ';' << spisok[i].group << ';';
		for (int j = 0; j < N; j++) {
			output << spisok[i].marks[j];
		}
		output << "\n";
	}
	output.close();
	cout << "Файл сохранен!\n";
}

void parsing(string stroka, Students& element) {
	stringstream stream(stroka);
	string str;
	getline(stream, str, ';');
	element.secondName = str;
	getline(stream, str, ';');
	element.firstName = str;
	getline(stream, str, ';');
	element.group = str;
	getline(stream, str, ';');
	int marks = stoi(str);
	for (int i = N - 1; i >= 0; i--) {
		element.marks[i] = marks % 10;
		marks /= 10;
	}
}

void loadFile(Students* &spisok, int &col){
	ifstream load("data.txt");
	if (!load.is_open()) {
		cout << "Ошибка открытия файла для загрузки\n";
		return;
	}
	int load_col;
	load >> load_col;
	Students *load_spisok = new Students[load_col];
	for (int i = 0; i < load_col; i++) {
		string str;
		load >> str;
		parsing(str, load_spisok[i]);
	}
	delete[] spisok;
	spisok = load_spisok;
	col = load_col;
	system("cls");
	cout << "Список успешно загружен из файла: \n";
	for (int i = 0; i < col; i++) printStudent(load_spisok[i]);
	
}