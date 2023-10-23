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
* @brief Функция определяет лежат ли 3 точки на одной линии
* @param x1 координата х первой точки
* @param x2 координата х второй точки
* @param x3 координата х третей точки
* @param y1 координата у первой точки
* @param y2 координата у второй точки
* @param y3 координата у третей точки
* @return если точки лежат на одной прямой, то возвращает true, в противном случае возвращает величину угла В
*/
bool isParallel_1(double x1, double x2, double x3, double y1, double y2, double y3);

/*
* @brief Функция определяет лежат ли 3 точки на одной линии
* @param x1 координата х первой точки
* @param x2 координата х второй точки
* @param x3 координата х третей точки
* @param y1 координата у первой точки
* @param y2 координата у второй точки
* @param y3 координата у третей точки
* @return если точки лежат на одной прямой, то возвращает true, в противном случае возвращает величину угла В
*/
bool isParallel_2(double x1, double x2, double x3, double y1, double y2, double y3);

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
	isParallel_2(A.x, B.x, C.x, A.y, B.y, C.y);
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

bool isParallel_1(double x1, double x2, double x3, double y1, double y2, double y3) {
	double scalr_x = (x2 - x1) * (x3 - x1);
	double scalr_y = (y2 - y1) * (y3 - y1);
	double distance_AB = sqrt(pow((x2 - x1), 2) + pow((y2 - y1), 2));
	double distance_AC = sqrt(pow((x3 - x1), 2) + pow((y3 - y1), 2));
	double B; 
	if (distance_AB != 0 || distance_AC != 0) { 
		B = acos((scalr_x + scalr_y) / (distance_AB * distance_AC));
	}
	else
	{
		errno = EIO;
		perror("ERROR");
		abort();
	}
	double const pi = 3.1415;
	B = B * 180 / pi;
	printf_s("Точки не лежат на одной прямой\nУгол В = %.2lf\n", B);
	return B;
}

bool isParallel_2(double x1, double x2, double x3, double y1, double y2, double y3) {
	if (sqrt(pow((x2 - x1), 2) + pow((y2 - y1), 2)) + sqrt(pow((x3 - x2), 2) + pow((y3 - y2), 2)) == sqrt(pow((x3 - x1), 2) + pow((y3 - y1), 2))){
		printf_s("Точки лежат на одной прямой");
		return true;
	}
	else {
		isParallel_1(x1, x2, x3, y1, y2, y3);
	}
}