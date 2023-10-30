#include <stdio.h>
#include <math.h>
#include <float.h>
#include <stdbool.h>

/*
* @brief Существует ли функция в точке x
* @param x - Аргумент функции
* @return true, если существует
*/
bool isExist(const double x);

/*
* @brief Расчет функции в точке x
* @param x - Аргумент функции
* @return Значение функции в точке x
*/
double getY(const double x);

/*
* @brief является точкой входа в программу 
* @return 0, в случае успеха
*/ 
int main() {
	double const xStart = 2.0;
	double const xFinish = 4.0;
	double const step = 0.2;
	double x = xStart;
	while (x - xFinish <= DBL_MIN)
	{
		if (isExist(x))
		{
			const double y = getY(x);
			printf_s("y = %lf, при x = %lf\n", y, x);
		}
		else
		{
			printf_s("Решений нет при x = %lf\n", x);
		}
		x += step;
	}
	return 0;
}

bool isExist(const double x) {
	return x > DBL_MIN;
}

double getY(const double x) {
	return 3*x - 4*log(x) - 5;
}