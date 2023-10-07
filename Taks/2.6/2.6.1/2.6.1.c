#include <stdio.h>
#include <math.h>
#include <stdlib.h>

/**
* @brief это координаты x двух точек
* @return возвращает координату x_a и координату x_b
*/
double get_x(double x_a, double x_b);

/**
* @brief это координаты y двух точек
* @return возвращает координату y_a и координату y_b
*/
double get_y(double y_a, double y_b);

/**
*@brief функция расчитывает расстояние между двумя заданными точками
*@return возвращает длинну растояния
*/
double distance(double dx, double dy);

/**
*@brief проверят на правильность пользовательский ввод 
*/
void get(double *value);


/**
*@brief является точкой входа в программу
*@return возвращает 0, если программа работает верно
*/
int main()
{
	double x_a, x_b, y_a, y_b;
	get(&x_a);
	get(&x_b);
	get(&y_a);
	get(&y_b);
	double a = get_x(x_a, x_b);
	double b = get_y(y_a, y_b);
	double res = distance(a,b);
	printf_s("%lf", res);
	return 0;
}

void get(double *value)
{
	int result;
	puts("Введите координату = ");
	result = scanf_s("%lf", value);
	if (result != 1)
	{
		puts("error");
		abort();
	}
}

double get_x(double x_a, double x_b)
{
	double dx = x_b - x_a;
	return (dx);
}

double get_y(double y_a, double y_b)
{
	double dy = y_b - y_a;
	return (dy);
}

/**
*@brief функция считает растояние между двумя точками
*@return возвращает значение растояния
*/
double distance(double dx, double dy)
{
	double AB = sqrt(pow(dx,2) + pow(dy,2));
	return AB;
}