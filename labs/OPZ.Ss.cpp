#include "pch.h"
#include <iostream>
#include <math.h>
using namespace std;
struct stack
{
	double inf;
	stack *next;
};

stack *AddStack(stack* sp, double inf)
{
	stack* spt = new stack;
	spt->inf = inf;
	spt->next = sp;
	return spt;
}

stack *ReadStack(stack* sp, double &inf)	// Прочтение с удалением
{
	stack *spt = sp;
	inf = spt->inf;
	sp = sp->next;
	delete spt;
	return sp;
}

int priority(char ch)	// Вычисление приоритета операции
{
	switch (ch)
	{
	case '(': case ')': return 0;
	case '+': case '-': return 1;
	case '*': case '/': return 2;
	case '^': return 3;
	default: return -1;
	}
}

void AddPostFix(char *strin, char *strout)
{
	stack *sp = NULL;
	int n = 0;
	char ch;
	double inf;
	for (unsigned int i = 0; i < strlen(strin); i++)
	{  
		ch = strin[i];
		if (ch == '^')
		{
			int pr = priority(ch);
			while (sp != NULL && priority((char)sp->inf) >= pr)
			{
				sp = ReadStack(sp, inf);
				strout[n++] = (char)inf;
			}
			sp = AddStack(sp, ch);
			continue;
		}
		// Если это операнд
		if (ch >= 'A')
		{
			strout[n++] = ch;
			continue;
		}
		// Если стек пуст или найдена открывающая скобка
		if (sp == NULL || ch == '(')
		{
			sp = AddStack(sp, ch);
			continue;
		}
		// Если найдена закрывающая скобка
		if (ch == ')')
		{
			while (sp->inf != '(')
			{
				sp = ReadStack(sp, inf);
				strout[n++] = (char)inf;
			}
			sp = ReadStack(sp, inf); // Удаление открывающей скобки
			continue;
		}
		// Если операция
		int pr = priority(ch);
		while (sp != NULL && priority((char)sp->inf) >= pr)
		{
			sp = ReadStack(sp, inf);
			strout[n++] = (char)inf;
		}
		sp = AddStack(sp, ch);
	}
	while (sp != NULL)
	{
		sp = ReadStack(sp, inf);
		strout[n++] = (char)inf;
	}
	strout[n++] = '\0';
}

double rasAV(char *str, double *mz)
{
	stack *sp = NULL;
	char ch;
	double inf, inf1, inf2;
	for (unsigned int i = 0; i < strlen(str); i++)
	{
		ch = str[i];
		// Если найден операнд
		if (ch >= 'A' && ch != '^')
		{
			sp = AddStack(sp, mz[int(ch)]);
			continue;
		}
		// Если найден знак операции
		sp = ReadStack(sp, inf2);
		sp = ReadStack(sp, inf1);
		switch (ch)
		{
		case '+': sp = AddStack(sp, inf1 + inf2); break;
		case '-': sp = AddStack(sp, inf1 - inf2); break;
		case '*': sp = AddStack(sp, inf1 * inf2); break;
		case '/': sp = AddStack(sp, inf1 / inf2); break;
		case '^': sp = AddStack(sp, pow(inf1, inf2)); break;
		}
	}
	sp = ReadStack(sp, inf);
	return inf;
}

int main()
{
	setlocale(LC_ALL, "ru");
	double masz[122];
	char str[100], strp[100], strArguments[100];
	cout << "Введите выражение: "; cin >> str;
	int i = 1;
	int с = 0;
	bool b = true;
	int dlina = strlen(str) - 1;
	//Если начинается с операции (за исключением операций сложения и вычитания)
	if (str[0] == '*' || str[0] == '/' || str[0] == '^') {
		b = false;
	}
	//Если заканчивается на операцию
	else if (str[dlina] == '+' || str[dlina] == '-' || str[dlina] == '*' || str[dlina] == '/' || str[dlina] == '^' || str[dlina] == '(') {
		b = false;
	}
	else {
        // 2 операнда подряд, 2 операции подряд, неправильное количество скобочек
		int count1 = 0, count2 = 0;
		if (str[0] == '(') count1++;
		else if (str[0] == ')') b = false;
		if (str[0] >= 'a' && str[0] <= 'z') {
			strArguments[с] = str[0];
			с++;
		}
		//Если введён левый символ
		if ((str[0] < 'a' || str[0] > 'z') && str[0] != '(') {
			b = false;
		}
		if (b) {
			if (str[i] == '(' && str[i + 1] == ')' || str[i] == ')' && str[i + 1] == '(');
			b = false;
		}
		if (b) {
			for (i; i < strlen(str); i++) {
				if ((str[i] < 'a' || str[i] > 'z') && str[i] != '(' && str[i] != ')' && str[i] != '+' && str[i] != '-' && str[i] != '*' && str[i] != '/' && str[i] != '^') {
					b = false;
					break;
				}
				//проверка на 2 операнда подряд
				if (str[i] >= 'a' && str[i] <= 'z' && str[i - 1] >= 'a' && str[i - 1] <= 'z') {
					b = false;
					break;
				}
				//проверка на 2 операции подряд
				if ((str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '/' || str[i] == '^') && (str[i - 1] == '+' || str[i - 1] == '-' || str[i - 1] == '*' || str[i - 1] == '/' || str[i - 1] == '^')) {
					b = false;
					break;
				}
				if (str[i] == '(') count1++;
				if (str[i] == ')') count2++;
				//Если сначала идёт закрывающая скобка
				if (count2 > count1) {
					b = false;
					break;
				}
				//Если после открывающей скобкой идёт операция или перед закрывающей скобкой
				if ((str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '/' || str[i] == '^') && str[i - 1] == '(') {
					b = false;
					break;
				}
				if (str[i] == ')' && (str[i - 1] == '+' || str[i - 1] == '-' || str[i - 1] == '*' || str[i - 1] == '/' || str[i - 1] == '^')) {
					b = false;
					break;
				}
				if (str[i] >= 'a' && str[i] <= 'z') {
					strArguments[с] = str[i];
					с++;
				}
			}
			if (b) {
                //Проверка на количество скобочек
				if (count1 != count2) b = false;
			}
		}
	}
	if (b) {
		for (int j = 0; j < с; j++) {
			cout << "Введите значение операнда " << strArguments[j] << ": "; cin >> masz[int(strArguments[j])];
		}
		AddPostFix(str, strp);
		cout << endl << strp;
		double s = rasAV(strp, masz);
		if (s == INFINITY) {
			cout << endl << "error /0" << endl;
			return 0;
		}
		else {
			cout << endl << "Результат вычисления: " << s << endl;
			return 0;
		}
	}
	else {
		cout << "Ошибка ввода!!" << endl;
		return 0;
	}
}