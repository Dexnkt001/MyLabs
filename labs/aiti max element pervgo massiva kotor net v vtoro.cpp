// aiti max element pervgo massiva kotor net v vtoro.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <iostream>
using namespace std;
int main()
{
	int s, l;
	bool r = false;
	cout << "Vvedite razmer pervogo massiva : ";
	cin >> s;
	int *a = new int[s];
	cout << "elementi pervogo : ";
	for (int i = 0; i < s; i++) {
		cin >> a[i];
	}
	cout << endl;
		cout << "Vvedite razmer vtorogo massiva : ";
		cin >> l;
		cout << "Vvedite elementu vtorogo massiva : ";
		int *b = new int[l];
		for (int j = 0; j < l; j++) {
			cin >> b[j];
		}	// Действие с массивами 
		int x;
		for (int j = 0; j < l; j++) {
			for (int i = 0; i < s; i++){
				if (b[j] == a[i]) {
					x = i;
					s--;
					r = true;
					
				}
				else r = false;
				if (r) {
					for (int g = x; g < s; g++) {
						a[g] = a[g + 1];
					}
					i--;
				}
				
			}
		}
        ///
		for (int i = 0; i < s; i++) {
				cout << " " << a[i];
			}
		cout << endl;
		int max = a[0];
		for (int i = 0; i < s; i++) {
			if (a[i] >= max) {
				max = a[i];
			}
		}
		cout << "max element : " << max << endl;

		delete[] a;
		delete[] b;
		return 0;
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
