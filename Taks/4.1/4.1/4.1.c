#include <stdio.h>
#include <stdlib.h>
#include <float.h>
#include <errno.h>
#include <time.h>

/*
* @brief Выбор пользователя
* @param fill_1 - Заполнение массива пользователем
* @param fill_2 - Заполнение массива рандомными числами
*/
enum fill_in{fill_1, fill_2};

/*
* @brief Заполняет массив рандомными числами
* @param size - размер массива
* @param array - указатель на массив
* @return 0 - в случае успеха
*/
int fill_random(const int size, int* array);

/*
* @brief Точка входа в программу
* @return 0, в случае успешного завершения программы
*/
int main() {
	const int size = 10;
	int a = (int*)malloc(size * sizeof(int));
	fill_random(size, a);
	for (int j = 0; j < size; j++) {
		printf_s("%d",(*a + j)
	}
	return 0;
}

int fill_random(const int size, int* array) {
	srand(time(NULL));
	for (size_t i = 0; i < size; i++) {
		*array + i = rand();
	}
	return 0;
}