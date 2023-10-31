#include <stdio.h> 
#include <stdlib.h> //abort
#include <errno.h> //error

/*
* @brief Функция меняет между собой значения двух переменных при помощи третьей
* @param i - первая переменная
* @param j - вторая переменная
*/
void swap_1(double* i, double* j);

/*
* @brief Функция меняет между собой значения двух переменных
* @param x - первая переменная
* @param y - вторая переменная
*/
void swap_2(double* x, double* y);

/*
* @brief проверяет пользовательский ввод
* @return введеное значение
*/
double getValue();

/*
* @brief Пользовательский ввод
* @param Switch1 действие 1) обмен переменных с помощью 3 переменной
* @param Switch2 действие 2) обмен переменных без помощи 3 переменной
*/
enum Action{Switch1=1, Switch2};

/*
* @brief является точкой входа в программу
* @return 0, в случае успеха
*/
int main() {
	printf_s("Введите переменную 1\n");
	double a = getValue();
	printf_s("Введите переменную 2\n");
	double b = getValue();
	printf_s("Изначальные значения: a = %lf, b = %lf\n", a, b);
	printf_s("%d - Обмен переменных при помощи 3 переменной\n%d - Обмен переменных без помощи 3 переменной\n", Switch1, Switch2);
	printf_s("Выберите действие: ");
	int choice = getValue();
	if (choice == Switch1 || choice == Switch2)
	{
		enum Action action = (enum Action)choice;
		switch (action)
		{
		case Switch1:
			swap_1(&a, &b);
			printf_s("swap_1  a = %.1lf, b = %.1lf\n", a, b);
			break;
		case Switch2:
			swap_2(&a, &b);
			printf_s("swap_2  a = %.1lf, b = %.1lf\n", a, b);
			break;
		default:
			printf_s("Вы ввели непраивльное значение");
			return 1;
			break;
		}
	}
	return 0;
}

double getValue() 
{ 
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

void swap_1(double* i, double* j) {
	double temp = *i;
	*i = *j;
	*j = temp;
}

void swap_2(double *x, double *y){
	*x = *x + *y;
	*y = *x - *y;
	*x = *x - *y;
}