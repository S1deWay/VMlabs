#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <fstream>
#include <math.h>
#include <ctime>
#include <iostream>
#include <vector>
#include <conio.h>

const double h = 0.25;

using namespace std;

double Func(double x)
{
	return tan(x);
}

double Pol(double x, vector<double> m)
{
	double S = 1, L = 0;
	for (int i = 0; i < m.size(); i++)
	{
		for (int j = 0; j < m.size(); j++)
		{
			if (i != j)
				S = S * ((x - m[j]) / (m[i] - m[j]));
		}
		L += S * Func(m[i]);
		S = 1;
	}
	return L;
}

int main()
{
	system("chcp 1251");
	system("cls");

	int pointscount = 0;
	double interpol = 0, p = 0;
	vector<double> points;

	cout << "¬ведите количество узлов: ";
	cin >> pointscount;
	cout << "¬ведите x: ";
	cin >> p;
	cout << endl;

	points.push_back(0);
	for (int i = 1; i < pointscount; i++)
		points.push_back(points[i - 1] + h);

	interpol = Pol(p, points);
	cout << "Pn = " << interpol << endl;

	return 0;

}