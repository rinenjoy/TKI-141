#include <stdio.h>
#include <math.h>

/**
*@brief формула для получения переменной а
*@return возвращает значение a
*/
double get_a(double const x, double const y, double const z);

/**
*@brief формула для получения переменной b
*@return возвращает значение b
*/
double get_b(double const x, double const y, double const z);

/**
*@brief точка входа в программу
*@return 0 в случае работы программы
*/
int main()
{
	double const x = 0.61;
	double const y = 3.4;
	double const z = 16.5;
	printf_s("x = %lf\ny = %lf\nz = %lf", x, y, z);
	printf_s("\na = %lf", get_a(x, y, z));
	printf_s("\nb = %lf", get_b(x, y, z));
	return 0;
}

double get_a(double const x, double const y, double const z)
{
	return pow(x, 3) * pow(tan(pow(x + y, 2)), 2) + z / sqrt(x + y);
}

double get_b(double const x, double const y, double const z)
{
	return (y * pow(x, 2) - z) / (exp(x * z) - 1);
}