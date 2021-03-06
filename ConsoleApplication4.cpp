#include "pch.h"	
#include <iostream>	
#include <cmath>	
using namespace std;
int main()
{
	setlocale(LC_ALL, ".1251");
	double a = 1; //ряд Тейлора
	double y = 0; //стандартная функция
	double an = 1; //н-ый член ряда Тейлора
	int k = 1; //к-тая степень числа 
	int auxiliary_variable = 0;
	int num = 1; //факториал в числителе
	int dem = 1; //факториал в знаменателе
	double x = 0;
	double e = 0;

	cout << "Введите значение x (где -1<x<1 ) : ";
	cin >> x;
	cout << "Введите значение e (где 0<e<10^(-k)) : ";
	cin >> e;

	if (e <= 0 || e >= pow(10, -k) || x <= -1 || x >= 1)
	{
		cout << "Введены неверные значения!";
		exit(0);
	}
	else
	{
		while (abs(an) >= e)
		{
			auxiliary_variable = 2 * k;
			while (auxiliary_variable > 2 * (k - 1))
			{
				num = num * auxiliary_variable;
				auxiliary_variable--;
			}
			an = pow(-1, k)*num*pow(x, k) / ((1 - 2 * k)*pow(dem, 2)*pow(4, k));
			a = a + an;
			k++;
			dem = dem * k;
		}
		cout << "Приближённое значение функции, вычисленное с помощью ряда Тейлора : " << a << endl;
	}
	y = sqrt(1 + x);
	cout << "Приближённое значение функции, вычисленное с помощью стандартной функции : " << y << endl;
	system("pause");
	return 0;
}