// Задание :  Определите следующие функции: Add() – добавление нового элемента в начало или конец 
//списка (предусмотреть обе возможности), PrintList() – вывод содержимого списка на экран и 
//Delete() – удалить i-й элемента из списка. 

#include "pch.h"
#include <iostream>

using namespace std;

struct sp {
	int  *data;
	sp * next;
} *head;

sp * Add(sp *& h) {
	sp *temp = new sp;
	int *a = new int;
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
	else if (s ->next != NULL) {
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
	int *y = new int;
	cin >> *y;
	t->data = y;
	t->next = p;
	return t;
}


int main()
{
	setlocale(LC_ALL, "ru");
	int x;
	cout << "Введите значение первого элемента : ";
	cin >> x;
	cout << endl;
	int *ps = &x;
	head = new sp;
	head -> data = ps;
	head -> next = NULL;
	sp * p = head;
	bool z;
	char b;
	cout << "Хотите ли вы добавить элемент в конец списк? Если да то нажмите Y, если нет, нажмите N: ";
	cin >> b;
	if (b == 'Y' || b == 'y') {
		z = true;
	}
	else z = false;
	while (z) {
		Add(head);
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
		p = begining_stack(p);
		cout << "Если вы хотите добавить еще элемент в начало списка то  нажмите : Y в противном случае N : ";
		cin >> o;
	}
	show(p);
	bool u = false;
	cout << "Если вы хотите удалить элемент списка, нажмите : Y в противном случае N : ";
	char e;
	cin >> e;
	while (e == 'Y' || e == 'y') {
		int i;
		cout << "Введите номер элемента который хотете удалить(помните что нумирация элементов начинается с 0) : ";
		cin >> i;
		 p = dell_element(i, p);
		cout << "Если вы хотите удалить элемент списка, нажмите : Y в противном случае N : ";
		cin >> e;
	}
	show(p);
	dell(p);
	return 0;
}

