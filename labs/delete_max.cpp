

#include "pch.h"
#include <iostream>
using namespace std;

struct tl {
	int x;
	tl *next;
};
tl *Add(tl *&ml, int x) {
	tl *t = new tl;
	t->x = x;
	t->next = ml;
	ml = t;
	return ml;
}
void show(tl *&ml) {
	tl *s = ml;
	while (s != NULL) {
		cout << s->x << endl;
		s = s->next;
	}
}

tl *faund(tl *&ml) {
	tl *s = ml;
	int max = s->x;
	tl *t = ml;
	while (s ->next != NULL) {
		if (s->next ->x > max) {
			t= s;
			max = s->next->x;
			s = s->next;
		}
		else s = s->next;
	}
	return t;
}
void Dell_max(tl *s) {
	tl *temp = new tl;
	temp = s->next;
	s->next = s->next->next;
	delete temp;
}
int main()
{
	setlocale(LC_ALL, "ru");
	tl *ml = new tl;
	ml = NULL;
	int n, x;
	cout << "Введите количество элементов стека : ";
	cin >> n;
	tl *head = ml;
	for (int i = 0; i < n; i++) {
		cout << "Введите элемент стека : ";
		cin >> x;
		head = Add(head, x);
		cout << endl;
	}
	show(head);
	Dell_max(faund(head));
	show(head);
	return 0;
}
