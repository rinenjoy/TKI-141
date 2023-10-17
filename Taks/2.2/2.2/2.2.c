#include <stdio.h>
#include <stdlib.h> //abort
#include <errno.h> //error
#include <math.h>
#include <float.h> //минимальные значения чисел с плавающей точкой

/* 
* @brief проверяет пользовательский ввод
* @return введеное значение
*/
double getValue();

/*
* @brief считает значение функции
* @param x - переменная
* @return значение функции
*/
double function(double x);


/* 
* @brief является точкой входа в программу
* @return 0, в случае успеха
*/
int main() {
	double x = getValue();
	double y = function(x);
	printf_s("Значение функции = %.3lf", y);
	return 0;
}

double getValue(){
	printf_s("Введите значение переменной\n");
	double value;
	int res = scanf_s("%lf", &value);
	if (res != 1)
	{ 
		errno = EIO;
		perror("ERROR");
		abort();
	} 
	return value;
}

double function(double x) 
{
	const double a = 2.5;
	double y;
	if (abs(x - a) > DBL_MIN) 
	{
		y = x * pow(sin(x),2);
	}
	else
	{
		y = x * pow(cos(x),2);
	}
	return y;
}