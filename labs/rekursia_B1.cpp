

#include "pch.h"
#include <iostream>
using namespace std;
int fun(int a, int n, int i) {
	i++;
	if (i == n) return a;
	else 
	return a + fun(a, n, i);
}
int funn(int b, int n, int i) {
	i++;
	if (i == n) return 1;
	else
		return b + funn(1, n, i);
}
int pow(int a, int n) {
	int p;
	if (a % 2 == 0) {
		p = 2 * (a *n / 2);
	}
	else
		p = (a + (a*(n - 1));
	return p;
}
int main()
{
	setlocale(LC_ALL, "ru");
	int a, n;
	cout << "Введите первый множитель : ";
	cin >> a;
	cout << endl;
	cout << "Введите втоой множитель : ";
	cin >> n;
	int s = fun(a, n, 0);
	int f = funn(1, a, 0) + funn(1, n, 0);
	cout << f << endl;
	cout << s;
	return 0;
}

