#include <stdio.h> 
#include <math.h>
#include <errno.h>
#include <stdlib.h>	
#include <float.h>

/*
* @brief Функция считает факторал
* @param n = число, от которого надо вычислить факториал
* @return вычесленное значение 
*/
int factorial(int n);

/*
* @brief Функция считает первое значение ряда
* @param k = 1 - первый член последовательности
* @return вычесленное значение
*/
double doFirst();

/*
* @brief проверяет пользовательский ввод
* @return введеное значение
*/ 
double getValue();

/*
* @brief Вычисляет текущий член ряда
* @param k - Порядковый номер члена ряда
* @return Значение текущего члена ряда
*/
double getRecurrent(int k);

/* 
* @brief Вычисляет сумму ряда до указанного номера члена
* @param n - Номер члена ряда, до которого нужно вычислить сумму
* @return Значение суммы ряда
*/ 
double getSum(int n);

/* 
* @brief Вычисляет сумму всех членов ряда, не меньших заданного числа e
* @param n - Максимальное количество членов ряда для вычисления
* @param e - Точность вычисления ряда последовательности
* @return Значение суммы ряда
*/ 
double getSumNotLessThanE(int n, double e);

/* 
* @brief Основная функция программы
* @return Возвращает 0 в случае успешного выполнения программы
*/ 
int main() { 
	printf_s("Введите количество членов ряда\n");
	int n = getValue();
	printf_s("Задайте число e\n");
	double e = getValue();
	double summ = getSum(n);
	double summNotLessThanE = getSumNotLessThanE(n, e);
	printf_s("Сумма первых членов ряда = %.15lf\n", summ); 
	printf_s("Сумма всех членов последовательности, не меньших заданного числа e = %.15lf\n", summNotLessThanE);
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

int factorial(int n) {
	int fact = 1;
	for (int i = 1; i <= n; i++)
	{
		fact *= i;
	}
	return fact;
}

double doFirst() {
	return (-1.0) * factorial(1) / factorial(5);
}

double getRecurrent(int k)
{
	return (double)(- 1.0 * (k + 1) / (k + 5));
} 

double getSum(int n)
{
	double current = doFirst();
	double sum = current;
	for (int k = 1; k < n; k++) 
	{
		current *= getRecurrent(k);
		sum += current;
	} 
	return sum;	
} 

double getSumNotLessThanE(int n, double e)
{ 
	double current = doFirst();
	double sum = current;
	int k = 1; 
	if (fabs(current) - e >= DBL_MIN)
	{ 
		for (k; k <= n; k++)
		{
			current *= getRecurrent(k);
			sum += current;
			k++;
		}	
	}
	return sum;
}