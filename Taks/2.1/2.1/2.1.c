#include <stdio.h> 
#include <stdlib.h> //abort
#include <errno.h> //error

/*
* @brief Функция меняет между собой значения двух переменных при помощи третьей
* @param i - первая переменная
* @param j - вторая переменная
*/
void swap_1(int* i, int* j);

/*
* @brief Функция меняет между собой значения двух переменных
* @param x - первая переменная
* @param y - вторая переменная
*/
void swap_2(int* x, int* y);

/*
* @brief проверяет пользовательский ввод
* @return введеное значение
*/
int getValue();

/*
* @brief Пользовательский ввод
* @param Switch1 действие 1) обмен переменных с помощью 3 переменной
* @param Switch2 действие 2) обмен переменных без помощи 3 переменной
*/
enum Action{Switch1, Switch2};

/*
* @brief является точкой входа в программу
* @return 0, в случае успеха
*/
int main() {
	int a = getValue();
	int b = getValue();
	printf_s("Изначальные значения: a = %d, b = %d\n", a, b);
	printf_s("%d - Обмен переменных при помощи 3 переменной\n%d - Обмен переменных без помощи 3 переменной\n", Switch1, Switch2);
	int choice;
	printf_s("Выберите действие: ");
	scanf_s("%d", &choice);
	enum Action action = (enum Action)choice;
	switch (action)
	{
	case Switch1:
		swap_1(&a, &b);
		printf_s("swap_1  a = %d, b = %d\n", a, b);
		break;
	case Switch2:
		swap_2(&a, &b);
		printf_s("swap_2  a = %d, b = %d\n", a, b);
		break;
	}
	return 0;
}

void swap_1(int* i, int* j) {
	int temp = *i;
	*i = *j;
	*j = temp;
}

int getValue() {
	printf_s("Введите значение \n");
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

void swap_2(int *x, int *y){
	*x = *x + *y;
	*y = *x - *y;
	*x = *x - *y;
}