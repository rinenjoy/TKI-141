#include <stdio.h>
#include <stdlib.h>
#define _USE_MATH_DEFINES
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
double corner(Ax, Ay, Cx, Cy);

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
double lieOnSameLine(Ax, Ay, Bx, By, Cx, Cy);

/* 
* @brief является точкой входа в программу
* @return 0, в случае успеха 
*/
int main() {
	printf_s("Введите значение x точки A\n");
	double Ax = getValue();
	printf_s("Введите значение y точки A\n");
	double Ay = getValue();
	printf_s("Введите значение x точки B\n");
	double Bx = getValue();
	printf_s("Введите значение y точки B\n");
	double By = getValue();
	printf_s("Введите значение x точки C\n");
	double Cx = getValue();
	printf_s("Введите значение y точки C\n");
	double Cy = getValue();
	lieOnSameLine(Ax, Ay, Bx, By, Cx, Cy);
	EXIT_SUCCESS;
	return 0;
}

double getValue() {
	int value;
	int res = scanf_s("%d", &value);
	if (res != 1)
	{
		errno = EIO;
		perror("ERROR");
		abort();
	}
	return value;
}

double corner(Ax, Ay, Cx, Cy) {
	double B = atan((double)(Cy - Ay)/(Cx - Ax));
	B = B * (180.0 / M_PI); //пеевод из радиан в градусы
	printf_s("Угол В = %.2lf\n", B);
	return B;
}

double lieOnSameLine(Ax, Ay, Bx, By, Cx, Cy) {
	double k = (double)(Ay - By) / (Ax - Bx);
	double b = Ay - k * Ax;
	if (Cy - k * Cx - b <= DBL_MIN)
	{
		printf_s("Точки лежат на одной прямой\n");
		return 0.0;
	}
	else
	{
		printf_s("Точки не лежат на одной прямой\n");
		return corner(Ax, Ay, Cx, Cy);
	}
}