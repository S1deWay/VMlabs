#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <conio.h>
#include <math.h>
#include <fstream>
#include <iostream>
#include <ctime>

const double eps = 0.00000001;
using namespace std;

double NY(double x)
{
	return pow(x, 2) - 2;
}

double NYP(double x)
{
	return 2 * x;
}

int main()
{

	srand(time(NULL));
	system("chcp 1251");
	system("cls");
	double a = 0, b = 0;
	double c = 0;
	
	while (NY(a) * NY(b) > 0)
	{
		a -= 0.01;
		b += 0.02;
	}

	while (abs(b - a) > eps)
	{
		c = (a + b) / 2;
		if (NY(a) * NY(c) < 0)
			b = c;
		else
			a = c;
	}

	cout << "Метод бисекций: X = " << abs(b + a) / 2 << endl;

	a = 0;
	b = 0;

	while (NY(a) * NY(b) > 0)
	{
		a -= 0.01;
		b += 0.02;
	}

	while (abs(b-a)>eps)
	{
		c = a - ((b-a)*NY(a))/(NY(b)-NY(a));
		if (NY(a) * NY(c) < 0)
			b = c;
		else
			a = c;
	}

	cout << "Метод хорд: X = " << c << endl;

	a = 0;
	b = c;

	while (NY(a) * NY(b) > 0)
	{
		a -= 0.01;
		b += 0.02;
	}

	while (abs(b - c) > eps)
	{
		c = b - (NY(b) / NYP(b));
		b = c;
	}

	cout << "Метод Ньютона: X = " << b << endl;
	return 0;
}