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
* @brief функция считает скалярное произведение одной из координат
* @param x1 координата х первой точки
* @param x2 координата х второй точки
* @param x3 координата x третей точки
* @return значение, равное скалярному произведению координат векторов
*/
double scalr(double xy1, double xy2, double xy3);

/*
* @brief функция считает модуль вектора
* @param x1 координата х первой точки
* @param x2 координата х второй точки
* @param y1 координата у первой точки
* @param y2 координата у второй точки
* @return значение, равное модулю вектора
*/
double distance(double x1, double x2, double y1, double y2);

/*
* @brief Функция считает значение угла между векторами, составленными из точек
* @param x1 координата х первой точки
* @param x2 координата х второй точки
* @param x3 координата х третей точки
* @param y1 координата у первой точки
* @param y2 координата у второй точки
* @param y3 координата у третей точки
* @return величинa угла В
*/
double corner(double x1, double x2, double x3, double y1, double y2, double y3);

/*
* @brief Функция определяет лежат ли 3 точки на одной линии
* @param x1 координата х первой точки
* @param x2 координата х второй точки
* @param x3 координата х третей точки
* @param y1 координата у первой точки
* @param y2 координата у второй точки
* @param y3 координата у третей точки
* @return если точки лежат на одной прямой, то пишет ответ и завершает программу, в противном случае обращается к функции lieOnSameLine2
*/
double lieOnSameLine(double x1, double x2, double x3, double y1, double y2, double y3);

/*
* @brief структура данных, позволяющая обозначить сразу две координаты точки
* @param x - координата x
* @param y - координата y
*/
struct point {
	double x;
	double y;
};

/* 
* @brief является точкой входа в программу
* @return 0, в случае успеха 
*/
int main() {
	struct point A;
	struct point B;
	struct point C;
	printf_s("Введите значение x точки A\n");
	A.x = getValue();
	printf_s("Введите значение y точки A\n");
	A.y = getValue();
	printf_s("Введите значение x точки B\n");
	B.x = getValue();
	printf_s("Введите значение y точки B\n");
	B.y = getValue();
	printf_s("Введите значение x точки C\n");
	C.x = getValue();
	printf_s("Введите значение y точки C\n");
	C.y = getValue();
	lieOnSameLine(A.x, B.x, C.x, A.y, B.y, C.y);
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

double corner(double x1, double x2, double x3, double y1, double y2, double y3) {
	double scalrx = scalr(x1,x2,x3);
	double scalry = scalr(y1, y2, y3);
	double distanceAB = distance(x1, x2, y1, y2);
	double distanceAC = distance(x2, x3, y2, y3);
	double B; 
	if (distanceAB >= DBL_MIN || distanceAC >= DBL_MIN) { 
		B = acos((scalrx + scalry) / (distanceAB * distanceAC));
	}
	else
	{
		errno = EIO;
		perror("ERROR");
		abort();
	}
	B = B * 180 / M_PI; //пеевод из радиан в градусы
	return B;
}

double lieOnSameLine(double x1, double x2, double x3, double y1, double y2, double y3) {
	if (distance(x1,x2,y1,y2) + distance(x2, x3, y2, y3) == distance(x1, x3, y1, y3)) {
		printf_s("Точки лежат на одной прямой");
		return 0.0;
	}
	else {
		double B = corner(x1, x2, x3, y1, y2, y3);
		printf_s("Точки не лежат на одной прямой\nУгол В = %.2lf\n", B);
		return B;
	}
}

double scalr(double xy1, double xy2, double xy3) {
	return (xy2 - xy1) * (xy3 - xy1);
}

double distance(double x1, double x2, double y1, double y2) {
	return sqrt(pow((x2 - x1), 2) + pow((y2 - y1), 2));
}