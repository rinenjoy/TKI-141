#include <stdio.h>
#include <stdlib.h>
#include <float.h>
#include <errno.h>
#include <time.h>

/*
* @brief Выбор пользователя
* @param fill_random - Заполнение массива пользователем
* @param fill_by_my_self - Заполнение массива рандомными числами
*/
enum fill_in{fill_randomm, fill_by_my_self};

/*
* @brief Выбор пользователя
* @param fill_random - Заполнение массива пользователем
* @param fill_by_my_self - Заполнение массива рандомными числами
*/
enum action {sum_10, exchange, para};

/*
* @brief Считает сумму отрицательных чисел, кратных 10
* @param array - массив 
* @param size - размер массива
* @return sum - сумма отрицательных чисел, кратных 10
*/
int get_sum_10(int* array, size_t size);

/*
* @brief Меняет положение первых 10 элементов 
* @param array - массив 
* @param size - размер массива
* @return изменённый массив
*/
void exchange_array(int* array,size_t size);

/*
* @brief предлагает выбор пользователю
* @return введенный номер действия
*/
int get_choice_fill();

/*
* @brief предлагает выбор пользователю
* @return введенный номер действия
*/
int get_choice_action();


/*
* @brief проверяет введенное значение
* @param massage - сообщение для пользователя
* @return переменную
*/
int get_value(const char* massage);

/*
* @brief проверяет или введенное значение > 0
* @param value введенное значение
* @return размер массива
*/
size_t get_size(int value);

/*
* @brief создает массив
* @param size - размер массива
* @return массив
*/
int* get_array(const size_t size);

/*
* @brief Заполняет массив рандомными числами
* @param size - размер массива
* @param array - массив
* @return 0 - в случае успеха
*/
int fill_random(const size_t size, int* array);

/*
* @brief Пользователь заполняет массив
* @param size - размер массива
* @param array -массив
* @return 0 - в случае успеха
*/
int fill_by_your_self(const size_t size, int* array);

/*
* @brief чистит использованную память
* @param array - массив
*/
void free_array(int* array);

/*
* @brief печатает элементы массива 
* @param array - массив
* @param size - размер массива
*/
void print_array(int* array, size_t size);

/*
* @brief Точка входа в программу
* @return 0, в случае успешного завершения программы
*/
int main() {
	int size_0 = get_value("Введите размер массива\t");
	const size_t size = get_size(size_0);
	int* array = get_array(size);
	int choice_1 = get_choice_fill();
	enum fill_in fill_in = (enum fill_in)choice_1;
	switch (fill_in)
	{
		case (fill_randomm):
			fill_random(size, array);
			puts("\nМассив заполнен рандомными числами\n");
			break;
		case (fill_by_my_self):
			fill_by_your_self(size, array);
			puts("\nВы заполнили массив\n");
			break;
		default:
			printf_s("Вы ввели неправильное значение\n");
			return errno;
			abort();
	}
	print_array(array, size);
	int choice_2 = get_choice_action();
	enum action action = (enum action)choice_2;
	int sum;
	switch (action)
	{
		case (sum_10):
			sum = get_sum_10(array, size);
			printf_s("Сумма отрицательных чисел, кратных 10 = %d\n", sum);
			break;
		case (exchange):
			printf_s("\nМассив до:\t");
			print_array(array, size);
			printf_s("\nМассив после:\t");
			exchange_array(array, size);
			print_array(array, size);
			break;
		case (para):
			puts("LOL");
			break;
		default:
			break;
	}
	free_array(array);
	return 0;

}

int get_sum_10(int* array, size_t size)
{
	int sum = 0;
	for (size_t i = 0; i < size; i++)
	{
		if (array[i] < 0 && abs(array[i]) % 10 == 0)
		{
			sum += array[i];
		}
	}
	return sum;
}

void exchange_array(int* array, size_t size)
{
	for (size_t i = 0; i < size && i < 10; i++)
	{
		int temp = array[i];
		array[i] = array[9 - i];
		array[9 - i] = temp;
	}
}

int get_choice_fill()
{
	printf_s("\n\n%d - Заполнить массив рандомными числами\n%d - заполнить массив самостоятельно\n\n", fill_randomm,fill_by_my_self);
	int choice = get_value("Выберите действие:\t");
	return choice;
}

int get_choice_action()
{
	printf_s("\n\n%d - Найти сумму отрицательных элементов, значения которых кратно 10\n%d - Заменить первые k элементов массива на те же элементы в обратном порядке\n%d - Определить, есть ли пара соседних элементов с произведением, pавным заданном числу\n\n", sum_10, exchange, para);
	int choice = get_value("Выберите действие:\t");
	return choice;
}

int get_value(const char* massage)
{
	int value = 0;
	printf_s("%s", massage);
	int res = scanf_s("%d", &value);
	if (res != 1)
	{
		errno = EIO;
		perror("ERROR");
		abort();
	}
	return value;
}

size_t get_size(int value)
{
	if (value <= 0)
	{
		errno = ENOMEM;
		perror("wrong size");
		abort();
	}
	return (size_t)value;
}

int* get_array(const size_t size)
{
	int* array = (int*)malloc(size * sizeof(int));
	if (NULL == array)
	{
		errno = ENOMEM;
		perror("Память не выделена\n");
		abort();
	}
	return array;
}

int fill_random(const size_t size, int* array) 
{
	time_t ttime = time(NULL);
	srand(ttime);
	for (size_t i = 0; i < size; i++) {
		array[i] = rand() % 2000 - 1000;
	}
	return 0;
}

int fill_by_your_self(const size_t size, int* array)
{
	for (size_t i = 0; i < size; i++)
	{
		array[i] = get_value("Введите элемент массива\t");
	}
	return 0;
}

void free_array(int* array)
{
	if (NULL != array)
	{
		free(array);
	}
}

void print_array(int* array, size_t size)
{
	for (size_t i = 0; i < size; i++)
	{
		printf_s("%d\t", array[i]);
	}
}