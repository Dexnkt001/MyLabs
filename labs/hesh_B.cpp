// Оюъявить и ввести массив структур из n элементов. Создать хнш-таблицу из M элементов. Осуществить поиск элемента по ключу в хеш-таблице.
//Вывеси на экран исходный массив, хеш-таблицу и все поля найденной структуры. через квадратну Адресацию.

#include "pch.h"
#include <iostream>
#include <string>
#include <stdio.h>
using namespace std;

struct nkt {
	char fam[30];
	int points;
	int plaes;
};

void sv_add(nkt inf, int m, nkt *H) {
	int i = inf.points % m;
	if (H[i].points != -1) {
		int p = 0;
		while (H[i].points != -1) {
			i = i + p * p;
			if (i == m) i = 0;
			p++;
		}
	}
	H[i] = inf;
}
int sv_seach(int inf, int m, nkt H[]) {
	int i = abs(inf % m);
	int p = 0;
	while (H[i].points != -1) {
		if (H[i].points == inf)return i;
		i = i + p * p;
		if (i > m)i = 0;
	}
	return -1;
}
 

int main()
{
	setlocale(LC_ALL, "ru");
	int n = 9;
	nkt a[9];
	cout << "Введите массив структур : " << endl;
	for (int i = 0; i < 9; i++) {
		cout << "Введите фамилию" << i + 1 << "- го человека : ";
		cin >> a[i].fam;
		cout << endl;
		cout << "Введите количетсво очков " << i + 1 << "- го человека : ";
		cin >> a[i].points;
		cout << endl;
		cout << "Введите место" << i + 1 << "- го человека : ";
		cin >> a[i].plaes;
		cout << endl;
	}
	int m = 15;
	nkt H[15];
	int i;
	for (i = 0; i < m; i++) H[i].points = -1;
	for (i = 0; i < n; i++)sv_add(a[i], m, H);
	int ss = 0, ii;
	cout << "исходный массив : " << endl;
	for (i = 0; i < 9; i++) {
		cout << "фамилия : " << i + 1 << " - го " << a[i].fam << endl;
		cout << "количество очков  : "<< i + 1 << " - го" << a[i].points << endl;
		cout << "место : " << i + 1 << " - го" << a[i].plaes << endl;
	}
	cout << "Хеш-таблица : " << endl;
	for (i = 0; i < 15; i++) {
		if (H[i].points == -1) {
			cout << "значение элемента : " << "a [ " << i + 1 << " ]" << H[i].points << endl;
		}
		else {
			cout << "значение элемента : " << "a [ " << i + 1 << " ]" << H[i].points << endl;
			cout << "значение элемента : " << "a [ " << i + 1 << " ]" << H[i].fam << endl;
			cout << "значение элемента : " << "a [ " << i + 1 << " ]" << H[i].plaes << endl;
		}
	}
	while (ss != -1) {
		cin >> ss;
		ii = sv_seach(ss, m, H);
		if (ii == -1)cout << "Нет элемента !" << endl;
		else {
			cout << H[ii].fam << endl;
			cout << H[ii].points << endl;
			cout << H[ii].plaes << endl;
		}
	}
	return 0;
}

