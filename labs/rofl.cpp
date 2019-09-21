//Создать двусвязный список из n элементов, удалить все отрицательные элементы, а четные элементы перенести в другой список. 
#include "pch.h"
#include <iostream>
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
void add(sp *s, int a) {
	sp *p;
	sp *temp = new sp;
	p = s->next;
	s->next = temp;
	temp->x = a;
	temp->next = p;
	temp->prev = s;
	if (p != NULL) {
		p->prev = temp;
	}
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
	//sp*next, *prev;
	//next = s->next;
	//prev = s->prev;
	if (s ->next!= NULL) {
		s ->next ->prev = s->prev;
	}
	if (s ->prev != NULL) {
		s -> prev->next = s->next;
	}
}
void del_o_e(sp *s) {
	//sp *p = s;
	while (s != NULL) {
		if (s->x < 0) {
			del(s);
		}
		s = s->next;
	}
}
sp *initn(sp *s) {
	sp *sm = new sp;
	sp *p = s->next;
	s->next->prev = s->prev;
	s->prev->next = s->next;
	sm = s;
	sm->next = NULL;
	sm->prev = NULL;
	s = p;
	return (sm);
}

void  AddN(sp *s, sp *l) {
	sp *p;
	while (s != NULL) {
		p = s->next;
		if (s->x % 2 == 0) {
			sp *y;
			del(s);
			y = l->next;
			l->next = s;
			s->next = y;
			s->prev = l;

		}s = p;
	}
}
sp* initNn(sp* s) {
	sp *headn = new sp;
	while (s != NULL) {
		if (s->x % 2 == 0) {
			headn = initn(s);
			if (s->next != NULL) {
				s = s->next;
			}
			break;
		}
		s = s->next;
	}
	return headn;
}
//void  AddNn(sp *s, sp *l) {
//	sp *p;
//	int g = 0;
//	while (s != NULL) {
//		p = s->next;
//		if (g % 2 == 0) {
//			sp *y;
//			del(s);
//			y = l->next;
//			l->next = s;
//			s->next = y;
//			s->prev = l;
//			g++;
//		}s = p;
//	}
//}
//
//sp* initNnn(sp* s) {
//	sp *headn = new sp;
//	while (s != NULL) {
//		int i = 0;
//		if (i == 1 ) {
//			headn = initn(s);
//			if (s->next != NULL) {
//				s = s->next;
//			}
//			break;
//			i++;
//		}
//		s = s->next;
//	}
//	return headn;
//}
int main()
{
	setlocale(LC_ALL, "ru");
	int n, z;
	sp *sm = new sp;
	cout << "Введите количество элементво : ";
	cin >> n;
	cout << endl << "Введите элемент : ";
	cin >> z;
	sp*head, *l;
	sp *firs = new sp;
	head = init(z);
	for (int i = 0; i < n - 1; i++) {
		cout << "Введите элемент : ";
		cin >> z;
		add(head, z);
		cout << endl;
	}
	show(head);
	firs->next = head;
	firs->prev = NULL;
	l = initNn(firs);
	AddN(head, l);
	del_o_e(head);
	cout << "---------------------------" << endl;
	show(head);
	cout << "---------------------------" << endl;
	show(l);
	return 0;
}
