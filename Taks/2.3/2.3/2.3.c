#define _USE_MATH_DEFINES
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <errno.h>
#include <stdbool.h>
#include <float.h>

/* 
* @brief проверяет пользовательский ввод
* @return введеное значение
*/
double getValue();

/*
* @brief Функция считает значение угла между 3 точками
* @param Ax координата х первой точки
* @param Cx координата х третей точки
* @param Ay координата у первой точки
* @param Cy координата у третей точки
* @return величинa угла В
*/
double corner(double x1,double  y1,double x3,double y3);

/*
* @brief Функция определяет лежат ли 3 точки на одной линии
* @param Ax координата х первой точки
* @param Bx координата х второй точки
* @param Cx координата х третей точки
* @param Ay координата у первой точки
* @param By координата у второй точки
* @param Cy координата у третей точки
* @return если точки лежат на одной прямой, то пишет ответ и завершает программу, в противном случае обращается к функции corner
*/
double lieOnSameLine(double x1, double y1, double x2, double y2, double x3, double y3);

/* 
* @brief является точкой входа в программу
* @return 0, в случае успеха 
*/
int main() {
	printf_s("Введите значение x точки A\n");
	double x1 = getValue();
	printf_s("Введите значение y точки A\n");
	double y1 = getValue();
	printf_s("Введите значение x точки B\n");
	double x2 = getValue();
	printf_s("Введите значение y точки B\n");
	double y2 = getValue();
	printf_s("Введите значение x точки C\n");
	double x3 = getValue();
	printf_s("Введите значение y точки C\n");
	double y3 = getValue();
	lieOnSameLine(x1, y1, x2, y2, x3, y3);
	return EXIT_SUCCESS;
}

double getValue() {
	double value;
	int res = scanf_s("%d", &value);
	if (res != 1)
	{
		errno = EIO;
		perror("ERROR");
		abort();
	}
	return value;
}

double corner(double x1,double y1,double x3,double y3) {
	double B = atan((double)(y3 - y1)/(x3 - x1));
	B = B * (180.0 / M_PI); //пеевод из радиан в градусы
	printf_s("Угол В = %.2lf\n", B);
	return B;
}

double lieOnSameLine(double x1, double y1, double x2, double y2, double x3, double y3) {
	double k = (double)(y1 - y2) / (x1 - x2);
	double b = y1 - k * x1;
	if (y3 - k * x3 - b <= DBL_MIN)
	{
		printf_s("Точки лежат на одной прямой\n");
		return 0.0;
	}
	else
	{
		printf_s("Точки не лежат на одной прямой\n");
		return corner(x1, y1, x3, y3);
	}
}