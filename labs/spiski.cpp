//Удалить второй и предпоследний элемент очереди
#include "pch.h"
#include <iostream>
#define NULL 0
using namespace std;

struct sp {
	int x;
	sp *next;
	sp*prev;
};
struct sp * init(int a) { 
	sp *s = new sp;
	s->x = a;
	s->next = NULL; 
	s->prev = NULL; 
	return (s);
}
//void cre(sp *&s, int a) {
//	sp *t = new sp;
//	t->x = a;
//	t->next = NULL;
//	t->prev = NULL;
//
sp *add(sp *s, int a) {
	//sp *p;
	sp *temp = new sp;
	//p = s->next;
	//s->next = temp;
	s ->next = temp;
	temp->x = a;
	temp->next = NULL;
	temp->prev = s;
	/*if (temp -> next != NULL) {
//	p->prev = temp;
	}*/
	return temp;
}

void show(sp*s) {
	sp *p;
	p = s;
	while (p != NULL) {
		cout << "Элемент : " << p->x << endl;
		p = p->next;
	}
}
void del(sp *s) {
	if (s->next != NULL) {
		s->next->prev = s->prev;
	}
	if (s->prev != NULL) {
		s->prev->next = s->next;
	}
	delete s;
}


void dell(sp*s) {
	sp *c;
	while (s->next != NULL) {
		s = s->next;
	}
	c = s->prev;
	del(c);
}
sp *dellall(sp *s) {
	sp *temp = s;
	while (temp ->next != NULL) {
		s = s->next;
		delete temp;
		s->prev = NULL;
		temp = s;
	}
	return NULL;
}
int main()
{
	setlocale(LC_ALL, "ru");
	//sp *s = new sp;
	int n, z;
	//s->x = z;
	//s->next = NULL;
	//s->prev = NULL;
	bool y = false, t = false;
	cout << "Введите количество элементво : ";
	cin >> n;
	if (n >= 2) t = true;
	if (n > 2) y = true;
	cout << endl << "Введите элемент : ";
	cin >> z;
	sp*head, *cur, *headn;
	head = init(z);
	headn = head;
	for (int i = 0; i < n - 1; i++) {
		cout << "Введите элемент : ";
		cin >> z;
		headn = add(headn, z);
		cout << endl;
	}if (y) {
		show(head);
		cur = head->next;
		del(cur);
		dell(head);
	}
	cout << "---------------------------" << endl;
	show(head);
	dellall(head);
	return 0;
}
