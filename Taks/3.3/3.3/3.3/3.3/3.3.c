#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include <float.h>
#include <math.h>

/*
* @brief Функция считает сумму ряда
* @param x - аргумент
* @param e - заданная точность
* @return сумму
*/
double get_sum(double x, double e);

/*
* @brief Заданная функция
* @param x - аргумент функции
* @return Значение функции в заданной точке
*/
double function(double x);

/*
* @brief проверяет правильность ввода
* @return введенное значение в случае успешной проверки, код ошибки в случае неправильного ввода
*/
double get_step();

/*
* @brief Точка входа в программу
* @return 0, в случае успешного завершения программы
*/
int main() {
	double const a = 0.1;
	double const b = 1.0;
	printf_s("Enter step\n");
	double step = get_step();
	double const e = pow(10, -4);
	printf_s("Argument\t\tFunction\t\tSumma\n");
	for (double i = a; i - b <= DBL_EPSILON; i += step)
	{
		//double arg = i;
		double func = function(i);
		double sum = get_sum(i, e);
		printf_s("%lf\t\t%lf\t\t%lf\n", i, func, sum);
	}
	return 0;
}

double get_step() {
	double step;
	int res = scanf_s("%lf", &step);
	if (res != 1 || step - 1.0 > DBL_EPSILON)
	{
		errno = EIO;
		perror ("ERROR");
		abort();
	}
	return step;
}

double get_sum(double x, double e)
{
	double sum = 0.0;
	int n = 1;
	double s_n = (pow(x, 2) * (2 * n + 3)) / ((n + 1) * (2 * n + 1));
	sum += s_n;
	for (int n = 2; n <= 10; n++)
	{
		s_n = (pow(x, 2) * (2 * n + 3)) / ((n + 1) * (2 * n + 1));
		if (s_n - e > DBL_EPSILON) {
			sum += s_n;
		}
	}
	return sum;
}

double function(double x) {
	return ((1 + 2 * pow(x, 2)) * exp(pow(x, 2)));
}