//создать список студентов, где я имею доступ к их отметкам, именам, и дате рождения. Выввести студентов с средним балом больше 6.

#include "pch.h"
#include <iostream>
#include <string>
using namespace std;

class student {
private:
	double mark;
	string name;
	string data;
public:
	student (double mark, string name, string data) {
		this->mark = mark;
		this->name = name;
		this->data = data;
	}
	student() {
		this->mark = 0;
		this->name = "0";
		this->data = "0";
	}
	void Set_stud() {
		cout << "Введите бал студента : ";  cin >> mark; 
		cout << endl << "Введите имя студента :"; cin >> name ;
		cout << endl << "Введите дату рождения : "; cin >>data ; cout << endl;
	}
	void Get_stud() {
		cout << "Бал студента : ";  cout << mark;
		cout << endl << "Имя студента :"; cout <<  name;
		cout << endl << "Дату рождения : "; cout << data; cout << endl;
	}
};
class mass {
private:
	int *a;
	int size;
public:
	mass(int size) {
		this->size = size;
		this->a = new int[size];
		for (int i = 0; i < size; i++) {
			a[i] = i;
		}
	}
	mass(const mass &other) {
		this->size = other.size;
		this->a = new int[other.size];
			for (int i = 0; i < other.size; i++) {
				a[i] = other.a[i];
			}
			for (int i = 0; i < other.size; i++) {
				cout << a[i] << "\t";
			}
	}
	mass & operator =(const mass &othere) {
		this->size = othere.size;
		if (this->size != 0) {
			cout << "Удаление первоначального массива" << endl;
			delete[] a;
		}
		this->a = new int[othere.size];
		for (int i = 0; i < othere.size; i++) {
			a[i] = othere.a[i];
		}
		return *this;
	}
	void print () {
		for (int i = 0; i < this -> size; i++) {
			cout << this->a[i] << endl;
	    }
	}

	~mass(){
		cout << "Вызвался диструктор : " << this << endl;
		delete[] a;
	}
};
class point {
private:
	int x;
	int y;
public :
	point() {
		this->x = 0;
		this->y = 0;
	}
	point(int x, int y) {
		this->x = x;
		this->y = y;
    }
	point & operator =(const point othere) {
		this->x = othere.x;
		this->y = othere.y;
		cout << "Вызвался оператор присваивания." << endl;
		return *this;
	}
	point & operator +(const point othere) {
		this->x += othere.x;
		this->y += othere.y;
		return *this;

	}
	void print() {
		cout << " x = " << this->x << " y = " << this->y << endl;
	}

	~point() {
		cout << "вызвался диструктор : " << this << endl;
	}
};

int main() 
{
	setlocale(LC_ALL, "ru");
	int n;
	cout << "Введите количество элементов первого массива : ";
	cin >> n; cout << endl;
	cout << "Введите количество элементов второго массива : ";
	int u;
	cin >> u; cout << endl;
    //копирование
	mass c(n);
	mass d(u);
	d = c;
	d.print();
	int x, y;
	cout << "Введите x : "; cin >> x; cout << " Введите y :"; cin >> y; cout << endl;
	//присваивание
	point m(x, y);
	point b;
	b = m;
	b.print();
	cout << "Введите количество студентов : ";
	int l; cin >> l; cout << endl;
	student *a;
	a = new student [l];
	double vx;
	string vy, vz;
	/*for (int i = 0; i < l; i++) {
		cout << "Введите отметку : "; cin >> vx; cout << endl << "Введите имя :"; cin >> vy; cout << endl << "Ввдите дату рождения :"; cin >> vz; cout << endl;
		a[i](vx, vy, vz);
	}
*/
	//сумма
	point g(2, 4);
	point t(3,8);
	point o = g + t;
	cout << "После суммы :"; o.print();
	cout << endl;
	return 0;
}
