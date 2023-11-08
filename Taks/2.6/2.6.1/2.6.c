#include <stdio.h>
#include <math.h>
#include <stdlib.h>

/**
* @brief Функция получает одну из координат двух точек
* @return возвращает разницу между координатами
*/
double get_difference(double xy_a, double xy_b);


/**
*@brief расчитывает расстояние между двумя заданными точками
*@param функция ожидает два значения, полученные в результате работы функций get_x и get_y 
*@return возвращает длину расстояния между двух точек
*/
double distance(double dx, double dy);

/**
*@brief проверяет на правильность пользовательский ввод 
*/
double get();


/**
*@brief является точкой входа в программу
*@return возвращает 0, в случае успеха
*/
int main()
{
	double x_a, x_b, y_a, y_b;
	puts("Введите координату x точки a: ");
	get(&x_a);
	puts("Введите координату y точки a: ");
	get(&y_a);
	puts("Введите координату x точки b: ");
	get(&x_b);
	puts("Введите координату y точки b: ");
	get(&y_b);
	double a = get_difference(x_a, x_b);
	double b = get_difference(y_a, y_b);
	double res = distance(a,b);
	printf_s("Растояние = %.2lf", res);
	return 0;
}

double get()
{
	int result;
	result = scanf_s("%lf", &value);
	if (result != 1)
	{
		puts("error");
		abort();
	}
	return value;
}

double get_difference(double xy_a, double xy_b)
{
	return xy_b - xy_a;
}


double distance(double dx, double dy)
{
	return sqrt(pow(dx, 2) + pow(dy, 2));
}