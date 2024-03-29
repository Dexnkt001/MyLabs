// Задание :  Определите следующие функции: Add() – добавление нового элемента в начало или конец 
//списка (предусмотреть обе возможности), PrintList() – вывод содержимого списка на экран и 
//Delete() – удалить i-й элемента из списка. 

#include "pch.h"
#include <iostream>

using namespace std;

struct sp {
    char  *data;
	sp * next;
} *head;

class spisok {
private :

public :
	sp * init() {
		sp *head = new sp;
		char *x = new char;
		cout << "Введите значение первого элемента : ";
		cin >> new char;
		head->data = x;
		head -> next = NULL;
		return head;
	}
	sp * Add(sp *& h) {
		sp *temp = new sp;
		char *a = new char;
		cout << "Введите значение элемента : ";
		cin >> *a;
		cout << endl;
		temp->data = a;
		temp->next = NULL;
		h->next = temp;
		h = temp;
		return h;
	}
	void show(sp *s) {
		sp *t = s;
		while (t != NULL) {
			cout << "значение данного элемента : " << *t->data << endl;
			t = t->next;
		}
	}
	void dell(sp * s) {
		sp *t;
		while (s != NULL) {
			t = s;
			s = s->next;
			delete t;
		}
	}
	sp * dell_element(int i, sp *s) {
		int t = 0;
		sp *q = s;
		sp * r = s;
		while (t != i && s != NULL) {
			r = s;
			s = s->next;
			t++;
			if (s == NULL) {
				cout << "Вы вышли за пределы стека!!!" << endl;
			}
		}
		if (t == 0) {
			sp *u = s->next;
			delete s;
			return u;
		}
		else if (s->next != NULL) {
			r->next = s->next;
			delete s;
			return q;
		}
		else {
			r->next = NULL;
			return q;
		}
	}
	sp * begining_stack(sp *p) {
		sp *t = new sp;
		char *y = new char;
		cin >> *y;
		t->data = y;
		t->next = p;
		return t;
	}
	void Add(int i, sp * s) {
		int t = 0;
		sp * y = new sp;
		sp * z = s;
		char *r = new char;
		cin >> *r;
		y->data = r;
		if (i == 0) {
			y->next = s->next;
			s->next = y;
		}
		if (i == 1) {
			y->next = s->next->next;
			s->next->next = y;
		}
		else if (i >= 2) {
			while (t != i && s->next != NULL) {
				s = s->next;
				t++;
			}
			y->next = s->next;
			s->next = y;
		}
	}
}stack;




int main()
{
	setlocale(LC_ALL, "ru");
	sp * p = stack.init();
	sp * q = p;
	bool z;
	char b;
	cout << "Хотите ли вы добавить элемент в конец списк? Если да то нажмите Y, если нет, нажмите N: ";
	cin >> b;
	if (b == 'Y' || b == 'y') {
		z = true;
	}
	else z = false;
	while (z) {
		q = stack.Add(q);
		cout << "Хотетие добавить еще элемент ? - введиет Y , в противном случае введите N : ";
		cin >> b;
		if (b == 'Y' || b == 'y') {
			z = true;
		}
		else z = false;
	}
	cout << "Может быть вы хотите добавить элемет в начало стека? Если да то нажмите Y, если нет то нажмите N :";
	char o;
	cin >> o;
	while (o == 'Y' || o == 'y') {
		p = stack.begining_stack(p);
		cout << "Если вы хотите добавить еще элемент в начало списка то  нажмите : Y в противном случае N : ";
		cin >> o;
	}
	stack.show(p);
	cout << "Может быть вы хотите добавить элемент в удобное вам место? если да то введите Y если нет то N: ";
	cin >> o;
	if (o == 'Y' || o == 'y') {
		sp *b = new sp;
		b->next = p;
		int m;
		cout << "Введите номер позиции на которую вы хотиете установить элемнт : ";
		cin >> m;
		cout << endl;
		stack.Add(m, b);
	}
	bool u = false;
	cout << "Если вы хотите удалить элемент списка, нажмите : Y в противном случае N : ";
	char e;
	cin >> e;
	while (e == 'Y' || e == 'y') {
		int i;
		cout << "Введите номер элемента который хотете удалить(помните что нумирация элементов начинается с 0) : ";
		cin >> i;
		p = stack.dell_element(i, p);
		cout << "Если вы хотите удалить элемент списка, нажмите : Y в противном случае N : ";
		cin >> e;
	}
	stack.show(p);
	stack.dell(p);
	return 0;
}

