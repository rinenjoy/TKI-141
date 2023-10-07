#include <stdio.h>
#include <math.h>
#include <stdlib.h>

/**
* @brief ��� ���������� x ���� �����
* @return ���������� ���������� x_a � ���������� x_b
*/
double get_x(double x_a, double x_b);

/**
* @brief ��� ���������� y ���� �����
* @return ���������� ���������� y_a � ���������� y_b
*/
double get_y(double y_a, double y_b);

/**
*@brief ������� ����������� ���������� ����� ����� ��������� �������
*@return ���������� ������ ���������
*/
double distance(double dx, double dy);

/**
*@brief �������� �� ������������ ���������������� ���� 
*/
void get(double *value);


/**
*@brief �������� ������ ����� � ���������
*@return ���������� 0, ���� ��������� �������� �����
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
	puts("������� ���������� = ");
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
*@brief ������� ������� ��������� ����� ����� �������
*@return ���������� �������� ���������
*/
double distance(double dx, double dy)
{
	double AB = sqrt(pow(dx,2) + pow(dy,2));
	return AB;
}