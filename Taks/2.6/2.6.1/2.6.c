#include <stdio.h>
#include <math.h>

/**
* @brief ��� ���������� ����� �
* @return ���������� ���������� x � ���������� y
*/
double give_a(double x_a, double y_a);

/**
* @brief ��� ���������� ����� b
* @return ���������� ���������� x � ���������� y
*/
double give_b(double x_b, double y_b);

/**
*@brief �������� ����� ����� � ���������
*@return ���������� 0, ���� ��������� �������� �����
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
	printf_s("������� ���������� � ����� � = ");
	scanf("%lf", &x_a);
	printf_s("������� ���������� � ����� � = ");
	scanf("%lf", &y_a);
}

double get_b(double x_b, double y_b)
{
	printf_s("������� ���������� � ����� b = ");
	scanf("%lf", &x_b);
	printf_s("������� ���������� � ����� b = ");
	scanf("%lf", &y_b);
}

double 