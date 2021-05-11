#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <math.h>
#include <iostream>
#include <vector>
#define eps 0.000001
using namespace std;

double Func(double x)
{
	return (2 * pow(x, 3) - 3 * pow(x, 2) + 4 * x + 3);
}

double WDiffFunc(double x)
{
	return (12 * x - 6);
}

double maxWDF(double a, double b)
{
	double max = 0;
	while (a < b)
	{
		if (max < abs(WDiffFunc(a)))
			max = abs(WDiffFunc(a));
		a += eps;
	}
	return max;
}

int main()
{
	system("chcp 1251");
	system("cls");
	double a = 0, b = 0, h = 0, a1 = 0;
	double countofstep = 0, E = 0;
	double S1 = 0, S2 = 0;
	cout << "¬ведите левую границу интегрировани€: ";
	cin >> a;
	cout << "¬ведите правую границу интегрировани€: ";
	cin >> b;
	cout << "¬ведите разбиение: ";
	cin >> countofstep;

	h = abs((b - a) / countofstep);
	a1 = a;
	E = maxWDF(a, b);
	E = (pow(b - a, 3) * E / (12 * pow(countofstep, 2)));
	do
	{
		S1 = 0;
		S2 = 0;
		while (a1 < b)
		{
			S1 += Func(a1) * h;
			S2 += Func(a1) * h / 2 + Func(a1 + h / 2) * h / 2;
			a1 += h;
		}
		a1 = a;
		S1 += h * (Func(a) + Func(b)) / 2;
		h = h / 2;
		S2 += h * (Func(a) + Func(b)) / 2;
	} while (S1 - S2 >= 3 * E);
	S1 = S2 + (S2-S1)/3;

	cout << "»нтеграл равен: " << S1 << "     с E усечени€ " << E << endl;
	return 0;
}