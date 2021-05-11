#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <math.h>
#include <iostream>
#include <vector>
#define eps 0.0001
#define fi 1.61803398

using namespace std;

double Func(double x)
{
	return (2 * pow(x, 3) - 10 * pow(x, 2) + 5);
}

int main()
{
	system("chcp 1251");
	system("cls");
	double a = 0, b = 0;
	double x1 = 0, x2 = 0;

	cout << "Введите левую границу: ";
	cin >> a;
	cout << "Введите правую границу: ";
	cin >> b;
	cout << endl;

	x1 = b - (b - a) / fi;
	x2 = a + (b - a) / fi;
	while (abs(b - a) > eps)
	{
		if (Func(x1) <= Func(x2))
		{
			a = x1;
			x1 = x2;
			x2 = a + (b - a) / fi;
		}
		else
		{
			b = x2;
			x2 = x1;
			x1 = b - (b - a) / fi;
		}
	}
	x1 = (a + b) / 2;
	cout << "Точка экстремума функции: " << x1 << endl;
	return 0;
}