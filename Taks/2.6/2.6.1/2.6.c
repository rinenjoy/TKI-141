#include <stdio.h>
#include <math.h>

/**
* @brief это координаты точки а
* @return возвращает координату x и координату y
*/
double give_a(double x_a, double y_a);

/**
* @brief это координаты точки b
* @return возвращает координату x и координату y
*/
double give_b(double x_b, double y_b);

/**
*@brief €вл€етс€ очкой входа в программу
*@return возвращает 0, если программа работает верно
*/
int main() 
{

	return 0;
}

double get()
{
	double get = scanf();
	if (get != 1)
		return get;
	else
		puts("error");
}
double get_a(double x_a, double y_a)
{
	printf_s("¬ведите координату х точки а = ");
	scanf("%lf", &x_a);
	printf_s("¬ведите координату у точки а = ");
	scanf("%lf", &y_a);
}

double get_b(double x_b, double y_b)
{
	printf_s("¬ведите координату х точки b = ");
	scanf("%lf", &x_b);
	printf_s("¬ведите координату у точки b = ");
	scanf("%lf", &y_b);
}

double 