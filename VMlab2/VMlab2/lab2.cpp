#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <iostream>
#include <math.h>
#include <conio.h>
#include <ctime>
#include <iomanip>
#include <fstream>

using namespace std;

int main()
{
	system("chcp 1251");
	system("cls");
	srand(time(NULL));
	int n = 0;
	float mn = 0, S = 0;
	int row = 0, q = 0;
	int len = 0;

	ifstream fin("MassiveBase.txt");
	if (!fin.is_open())
	{
		cout << "Ошибка чтения" << endl;
		return 0;
	}
	else
	{
		char c;
		while (row == 0)
		{
			fin.read(&c, 1);
			if (c == '\n')
				row = 1;
			else
				if (c != '-')
					len++;
		}
	}
	fin.close();
	row = 0;

	vector<float>Xi;
	vector<float>Xk;

	cout << endl;
	float** mass, **massC;
	mass = new float* [len];
	massC = new float* [len];
	for (int i = 0; i < len; i++)
	{
		mass[i] = new float[len - 1];
		massC[i] = new float[len - 1];
		if (i != len - 1)
		{
			Xi.push_back(0);
			Xk.push_back(0);
		}
	}

	ifstream ffin("MassiveBase.txt");
	if (!ffin.is_open())
	{
		cout << "Ошибка чтения" << endl;
		return 0;
	}
	else
	{
		char c;
		for (int i = 0; i < len - 1; i++)
		{
			for (int j = 0; j < len; j++)
			{
				ffin.read(&c, 1);
				if (c != '\n')
				{
					if (c != '-')
					{
						mass[i][j] = (int)c - 48;
						cout << mass[i][j] << " ";
					}
					else
					{
						ffin.read(&c, 1);
						mass[i][j] = ((int)c - 48) * (-1);
						cout << mass[i][j] << " ";
					}
				}
				else
					j--;

			}
			cout << endl;
		}
		cout << endl;
	}
	ffin.close();

	cout << "Введите k для точности: ";
	cin >> q;
	for (int i = 0; i < len-1; i++)
	{
		mn = mass[i][i];
		for (int j = 0; j < len; j++)
		{
			mass[i][j] = mass[i][j] / mn;

			if (j != len - 1)
				if (j != i)
					massC[i][j] = mass[i][j];
				else
					massC[i][j] = 0;
			else
				Xi[i] = mass[i][j];
		}
	}

	for (int i = 0; i < len - 1; i++)
	{
		for (int j = 0; j < len; j++)
		{
			cout << mass[i][j] << " ";
		}
		cout << endl;
	}
	for (int i = 0; i < Xi.size(); i++)
		cout << Xi[i] << " ";
	cout << endl << endl << endl;

	mn = 0;
	while (mn < q)
	{
		for (int i = 0; i < len - 1; i++)
		{
			for (int j = 0; j < len-1; j++)
			{
					S += massC[i][j] * Xi[j];
			}
			Xk[i] = mass[i][len - 1] - S;
			S = 0;
		}
		for(int i = 0; i < len-1; i++)
			Xi[i] = Xk[i];
		mn++;
	}
	for (int i = 0; i < len - 1; i++)
		cout << "X" << i << " = " << Xk[i] << endl;

	return 0;
}