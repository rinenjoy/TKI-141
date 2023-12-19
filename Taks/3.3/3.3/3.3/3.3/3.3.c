#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include <float.h>
#include <math.h>

/*
* @brief Функция считает сумму ряда с заданной точностью
* @param x - аргумент
* @param func - посчитанная функция в данной точке
* @param e - заданная точность
* @return сумму
*/
double get_sum(double x, double func, double e);

/*
* @brief проверяет введенное значение
* @param massage - сообщение для пользователя
* @return переменную
*/
double get_value(const char* massage);

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
	//printf_s("Enter step\n");
	double step = 0.1;
		//get_step();
	double const e = 0.001;
		//get_value("Введите е");
	printf_s("Argument\tFunction\tSumma\n");
	for (double i = a; i - b <= DBL_EPSILON; i += step)
	{
		double sum = get_sum(i, function(i), e);
		printf_s("%.2lf\t\t%lf\t\t%lf\n", i, function(i), sum);
	}
	return 0;
}

double get_step() 
{
	double step;
	int res = scanf_s("%lf", &step);
	if (res != 1 || step - 1.0 > - DBL_EPSILON)
	{
		errno = EIO;
		perror ("ERROR");
		abort();
	}
	return step;
}

double get_sum(double x, double func, double const e)
{
	double current = 1.0;
	double sum = current;
	double n = 1;
	while (current - e > - DBL_EPSILON )
	{
		current *= (pow(x,2)*(2*n  + 3))/ ((n + 1) * (2 * n + 1));
		sum += current;
		n = n + 1.0;
		//printf_s("\n%d\n%lf\n", n, current);
	}
	return sum;
}

double get_value(const char* massage)
{
	printf_s("\n%s\t", massage);
	double value = 0.0;
	int res = scanf_s("%lf", &value);
	if (res != 1)
	{
		errno = EIO;
		perror("ERROR");
		abort();
	}
	return value;
}

double function(double x) {
	return ((1 + 2 * pow(x, 2)) * exp(pow(x, 2)));
}