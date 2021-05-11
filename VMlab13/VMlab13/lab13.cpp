#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <math.h>
#include <iostream>
#include <vector>
#define eps 0.001
using namespace std;

double Func(double x, double y)
{
	return pow(x,2)-2*y;
}

int main()
{
	system("chcp 1251");
	system("cls");
	int i = 0, q = 0, k = 0;
	double a = 0, b = 0, h = 0, a1 = 0;
	vector<double> ycor, ycor1;
	vector<double> funcamount, funcamount1;
	cout << "¬ведите начальное условие: " << endl << "y от ";
	cin >> a;
	cout << "равно  ";
	cin >> b;
	cout << "¬ведите шаг разбиени€: ";
	cin >> h;
	a1 = a;
	
	do
	{
		ycor.push_back(b);
		ycor1.push_back(b);
		do
		{
			funcamount.push_back(Func(a1, ycor[i]));
			ycor.push_back(ycor[i] + (h / 2) * (funcamount[i] + Func(a1 + h, ycor[i] + (h / 2) * funcamount[i])));
			funcamount1.push_back(Func(a1, ycor1[k]));
			ycor1.push_back(ycor1[k] + (h / 4) * (funcamount1[k] + Func(a1 + h / 2, ycor1[k] + (h / 4) * funcamount1[k])));
			funcamount1.push_back(Func(a1+h, ycor1[k + 1]));
			ycor1.push_back(ycor1[k + 1] + (h / 4) * (funcamount1[k + 1] + Func(a1 + h, ycor1[k + 1] + (h / 4) * funcamount1[k + 1])));

			i++;
			if (abs(ycor[i] - ycor1[i*2]) < 3 * eps)
				q = 1;
			k += 2;
			a1 += h;
		} while (a1 < b);
		a1 = a;
		h = h / 2;
		i = 0;
		k = 0;
		if (q == 0)
		{
			ycor.clear();
			ycor1.clear();
			funcamount.clear();
			funcamount1.clear();
		}
		else
			funcamount1.push_back(Func(a, ycor1[ycor1.size()-1]));

	} while (q == 0);

	for (int j = 0; j < funcamount1.size(); j++)
	{
		cout << "i = " << j << "	x = " << a1 << "	y = " << ycor1[j] << "	func(x,y) = " << funcamount1[j] << endl;
		a1 += h;
	}


	return 0;
}