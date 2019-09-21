// Написать набор функции для следующих заач: Создание бинарного файла, запись в файл данных, открытие файла и чтение из него данных,
//вывод результат на экран, вывод текста в текстовый файл, для вызова необходимых функций использоватть меню, задание взять из
//соответствующего варианта в лабаратоной работе №8.


#include "pch.h"
#include <iostream>
#include <string>
#include<conio.h>
#include<stdlib.h>
#include<io.h>
using namespace std;

struct train {
	float time;
	char place[50];
	int free_place;
};
char fname[20] = "";
char *nnf() {
	if (strlen(fname)) return fname;
	cout << "Введите имя файла : ";
	cin >> fname;
	return fname;
}

void infile(int n, train *a) {
	if ((fl = fopen(nnf(), "ab")) == NULL)
		if ((fl = fopen(nnf(), "wb")) == NULL) {
			cout << "Ошибка при создании !!!" << endl; return;
		}
	for (int i = 0; i < n; i++) {
		cout << "Введите время отправления " << i + 1 << "- го " << " поезда : ";
		cin >> a[i].time;
		cout << "Время отправления поезда под номером " << i + 1 << " -- " << a[i].time << endl;
		cout << endl << "Введите место прибытия " << i + 1 << " - го " << " поезда : ";
		cin >> a[i].place;
		cout << "Место прибывания поезда под номером " << i + 1 << " -- " << a[i].place;
		cout << endl << "Введите количество свободных мест " << i + 1 << " - го " << " поезда : ";
		cin >> a[i].free_place;
		cout << endl << "Количество свобожных мест в поезде под номером -- " << i + 1 << a[i].free_place;
		cout << endl << "------------------------" << endl;
	}
	fwrite(a, sizeof(train), 1, fl);
	fclose(fl);
}
///////////////////////////////////////////
void outfile(int n, train *a) {
	if ((fl = fopen(nnf(), "ab")) == NULL)
	{
		cout << "Ошибка при открытии файла !!!" << endl;
		return;
	}
	//char buff[50];
	fread(a, sizeof(train), n, fl);

	for (int i = 0; i < n; i++) {
		cout << "Время прибытия " << i + 1 << " - го поезда :" << a[i].time << endl;
		cout << "место прибытя " << i + 1 << " - го поезда :" << a[i].place << endl;
		cout << "количество свобожных мест " << i + 1 << " - го поезда :" << a[i].free_place << endl;
	}

	fclose(fl);
}
///////////////////////////////////////////
void result(int n, train *a) {
	if ((fl = fopen(nnf(), "ab")) == NULL)
	{
		cout << "Ошибка при открытии файла !!!" << endl;
		return;
	}
	//char buff[50];
	fread(a, sizeof(train), 1, fl);

	for (int i = 0; i < n; i++) {
		cout << "Время прибытия " << i + 1 << " - го поезда :" << a[i].time << endl;
		cout << "место прибытя " << i + 1 << " - го поезда :" << a[i].place << endl;
		cout << "количество свобожных мест " << i + 1 << " - го поезда :" << a[i].free_place << endl;
	}
	//char buff[50];
	train *buf = new train;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n - i - 1; j++) {
			if (a[j].free_place < a[j + 1].free_place) {
				*buf = a[j];
				a[j] = a[j + 1];
				a[j + 1] = *buf;
			}
		}
	}delete[] buf;
	for (int i = 0; i < n; i++) {
		if (a[i].place == "Brest" || a[i].place == "brest") {
			cout << "Время прибытия поезда номер " << i + 1 << " : " << a[i].time << endl;
			cout << "Количество свободных мест поезда под номером " << i + 1 << " : " << a[i].free_place << endl;
			cout << "------------------------------" << endl;
		}
	}
	fclose(fl);
}

/////////////////////////////////////////
void result_file(int n, train *a) {
	char fnamef[20];
	FILE*ff;
	cout << "Введите название файла : ";
	cin >> fnamef;

	if ((ff = fopen(fnamef, "w")) == NULL)
	{
		cout << "Ошибка при создании файла !!!" << endl;
		return;
	}
	if ((fl = fopen(nnf(), "rb")) == NULL)
	{
		cout << "Ошибка при открытии файла !!!" << endl;
		return;
	}
	fread(a, sizeof(train), 1, fl);
	for (int i = 0; i < n; i++) {
		cout << "Время прибытия " << i + 1 << " - го поезда :" << a[i].time << endl;
		cout << "место прибытя " << i + 1 << " - го поезда :" << a[i].place << endl;
		cout << "количество свобожных мест " << i + 1 << " - го поезда :" << a[i].free_place << endl;
	}
	//char buff[50];
	train *buf = new train;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n - i - 1; j++) {
			if (a[j].free_place < a[j + 1].free_place) {
				*buf = a[j];
				a[j] = a[j + 1];
				a[j + 1] = *buf;
			}
		}
	}delete[] buf;
	fread(a, sizeof(train), 1, fl);
	for (int i = 0; i < n; i++) {
		if (a[i].place == "Brest" || a[i].place == "brest") {
			cout << "Время прибытия поезда номер " << i + 1 << " : " << a[i].time << endl;
			cout << "Количество свободных мест поезда под номером " << i + 1 << " : " << a[i].free_place << endl;
			cout << "------------------------------" << endl;
		}
	}
	fclose(fl);
}
/////////////////////////////////////////
int menu()
{
	cout << "1 - Ввести данные в файл " <<"2 - Открытие файла и чтение из него информации" << endl << "3 - Вывод результата на экран"
		<< endl << "4 - Вывод текта в текстовый файл" << endl << "5 - Выход" << endl; int k; cin >> k;
	return k;
}

int main()
{
	FILE*fl;
	setlocale(LC_ALL, "ru");
	int  n;
	cout << "Введите количество поездов" << endl;
	cin >> n;
	train *a = new train[n];
	while (true) {
		switch (menu()) {
		case 1: infile(n, a);
			break;
		case 2: outfile(n, a);
			break;
		case 3: result(n, a);
			break;
		case 4: result_file(n, a);
			break;
		case 5: return 0;
			break;
		default: cout << "Вы выбрали неизвестную функцию" << endl;
		}
	}
	delete[] a;
	return 0;
}
