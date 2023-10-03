#include <stdio.h>
#include <math.h>

/**
*@brief формула для получения переменной а
*@return возвращает значение a
*/
double get_a(double x, double y, double z);

/**
*@brief формула для получения переменной b
*@return возвращает значение a
*/
double get_b(double x, double y, double z);

/**
*@brief точка входа в программу
*@return 0 в случае работы программы
*/
int main()
{
	double x = 0.61;
	double y = 3.4;
	double z = 16.5;

	printf_s("x = %lf \ny = %lf \nz = %lf", x, y, z);
	printf_s("\na = %lf", get_a(x, y, z));
	printf_s("\nb = %lf", get_b(x, y, z));
	return 0;
}

double get_a(double x, double y, double z)
{
	double a = pow(x, 3) * pow(tan(pow(x + y, 2)), 2) + z / sqrt(x + y);
	return a;
}

double get_b(double x, double y, double z)
{
	double b = (y * pow(x, 2) - z) / (exp(x * z) - 1);
	return b;
}
