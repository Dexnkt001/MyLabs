
#include "pch.h"
#include <iostream>
#include <io.h>
using namespace std;
struct pep {
	char i[10];
	char f[10];
};

char *names(char name[]) {
	cout << "Vvedite imia : ";
	cin >> name;
	return name;
}
void creating_fiile(char name[], FILE *fl) {
	fopen_s(&fl, names(name), "wb");
		if (fl == NULL) {
			cout << "error on creating file." << endl;
		}
		fclose(fl);
}
void recording_file(char name[], FILE *fl, pep &p) {
	fopen_s(&fl, names(name), "ab");
	if (fl == NULL) {
		cout << "error on recording file." << endl; return;
	}
	char ch;
	do {
		cout << "Vvedite imia : "; cin >> p.i; cout << endl;
		cout << "Vvedite familiu : "; cin >> p.f; cout << endl;
		fwrite(&p, sizeof(pep), 1, fl);
		cout << "if you wont to creat more pepole? enetr the 'y' else 'n' ";
		cin >> ch;
	} while (ch = 'y');
	fclose(fl);
}
void reading_file(char name[], FILE *fl, pep &p) {
	fopen_s(&fl, names(name), "rb");
	if (fl == NULL) {
		cout << "error in open function" << endl; return;
	}
	int n = _filelength(_fileno(fl)) / sizeof(pep);
	for (int i = 0; i < n; i++) {
		fread(&p, sizeof(pep), 1, fl);
		cout << p.i << " : imia; " << p.f << " : fomilia;" << endl;
	}
	fclose(fl);
}

int main()
{
	FILE *fl;
	char name[30];
	pep p;
}
