

#include "pch.h"
#include <iostream>
using namespace std;
struct pep {
	int i;
	int p;
};
char *fname(char name[]){
	cout << "Vvedite imia fila : "; cin >> name; cout << endl;
	}

void creat(FILE *fl, char name[]) {
	fopen_s(&fl, fname(name), "ab");
	if (fl == NULL) {
		cout << "error" << endl;
	}
}
void recording(FILE *fl, char name[], pep &a) {
	fopen_s(&fl, fname(name), "wb");
	if (fl == NULL) {
		cout << "Error." << endl; return;
	}
	else {
		char ch;
		do {
			cout << "Vvedite i : "; cin >> a.i; cout << endl;
			cout << "Vvedite p : "; cin >> a.p; cout << endl;
			fwrite(&a, sizeof(pep), 1, fl);
			cout << "if you wont more, enter 'y'";
			cin >> ch;
		} while (ch == 'y');
	}
	fclose(fl);
}
void read(FILE *fl, char name[], pep &a) {
	fopen_s(&fl, fname(name), "ab");
	if (fl == NULL) {
		cout << "Error." << endl; return;
	}
	else {
		int n = filelength(fileno(fl))/sizeof(pep);
		for (int i = 0; i < n; i++) {
			fread(&a, sizeof(pep), 1, fl);
			cout << "i : : " << a.i << endl; cout << " p : " << a.p << endl;
		}
	}
	fclose(fl);
}
int main()
{
	FILE *fl;
	pep a;
	char name[30];
}
