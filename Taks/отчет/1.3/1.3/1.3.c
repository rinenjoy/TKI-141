#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*
* @brief Функция получет пользовательское значение
*/
double get_value();

/*
* @brief Функция вычисляет силу force
* @param m - масса бетонной плиты [кг]
* @return сила force [Н]
*/
double get_force(double m);

/*
* @brief Функция вычисляет давление, производимое бетонной плитой
* @param force - сила давления бетонной плиты
* @param square - площадь опоры
* @return давление pressure [Па]
*/
double get_pressure(double force, double square);

/*
* @brief является точкой входа в программу
* @return 0, в случае успеха
*/
int main() {
	puts("Введите массу (m) бетонной плиты [кг]: ");
	double m = get_value();
	puts("Введите площадь опоры [кв.м] : ");
	printf_s("Давление, производимое бетонной плитой = %.2lf [Па]", get_pressure(get_force(m), get_value()));
	return 0;
}

double get_value()
{
	double value;
	double res = scanf_s("%lf", &value);
	if (res != 1)
	{
		puts("Error");
		abort();
	}
	return value;

}

double get_force(double m)
{
	const double g = 9.81;
	return (m * g);
}

double get_pressure(double force, double square)
{
	return (force / square);
}