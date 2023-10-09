#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*
* @brief Функция проверяет пользовательский ввод
*/
double get();

/*
* @brief Функция вычисляет силу F
* @param m - масса бетонной плиты [кг]
* @param g - ускорение свободного падения, константа равная 9,81 [м/с₂]
* @return сила F [Н]
*/
double get_F(double m);

/*
* @brief Функция вычисляет давление, производимое бетонной плитой
* @param F - сила давления бетонной плиты
* @param S - площадь опоры
* @return давление P [Па]
*/
double get_P(double F, double S);

/*
* @brief является точкой входа в программу
* @return 0, в случае успеха
*/
int main() {
	puts("Введите массу (m) бетонной плиты [кг]: ");
	double m = get();
	double F = get_F(m);
	puts("Введите площадь опоры [кв.м] : ");
	double S = get();
	double P = get_P(F, S);
	printf_s("Давление, производимое бетонной плитой = %.2lf [Па]", P);
	return 0;
}

double get()
{
	double value;
	double res = scanf_s("%lf", &value);
	if (res != 1)
	{
		puts("Error");
		abort();
	}
	return (value);

}

double get_F(double m)
{
	const double g = 9.81;
	double F = m * g;
	return (F);
}

double get_P(double F, double S)
{
	double P = F / S;
	return (P);
}