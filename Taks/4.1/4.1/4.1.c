#include <stdio.h>
#include <stdlib.h>
#include <float.h>
#include <errno.h>
#include <time.h>
#include <stdbool.h>
#include <assert.h>

/*
* @brief Выбор пользователя
* @brief fill_random - Заполнение массива пользователем
* @brief fill_by_my_self - Заполнение массива рандомными числами
*/
enum fill_in{fill_randomm, fill_by_my_self};

/*
* @brief Выбор пользователя
* @brief sum_10 - Найти сумму отрицательных элементов, значения которых кратно 10
* @brief exchange - Заменить первые k элементов массива на те же элементы в обратном порядке
* @brief para - Определить, есть ли пара соседних элементов с произведением, pавным заданном числу
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
* @brief Заняет первые k элементов на те же элементы, записанные в обратном порядке
* @param array - массив 
* @param size - размер массива
* @return изменённый массив
*/
void exchange_array(int* array,size_t size);

/*
* @brief меняет переменные
* @param a - переменная
* @param b - переменная
*/
void swap(int* a, int* b);

/*
* @brief определяет существует ли такая пара элементов с произедением, равным заданному числу
* @param array - массив
* @param size - размер массива
* @return True/False
*/
bool is_exist_para(int* array, size_t size);

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
size_t get_size_t(int value);

/*
* @brief проверяет или введенный диапазон соответствует действительности
* @param range_right - правая граница диапазона
* @param range_left - левая граница диапазона
*/
void check_range(int range_right, int range_left);

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
* @param range_right - правая граница диапазона
* @param range_left - левая граница диапазона
* @return 0 - в случае успеха
*/
int fill_random(const size_t size, int* array, int range_right, int range_left);

/*
* @brief Пользователь заполняет массив
* @param size - размер массива
* @param array - массив
* @param range_right - правая граница диапазона
* @param range_left - левая граница диапазона
* @return 0 - в случае успеха
*/
int fill_by_your_self(const size_t size, int* array, int range_right, int range_left);

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
	const size_t size = get_size_t(get_value("Введите размер массива\t"));
	int* array = get_array(size);
	int range_left = get_value("\nВведите левую границу диапозона\t");
	int range_right = get_value("\nВведите правую границу диапозона\t");
	check_range(range_right, range_left);
	int choice_1 = get_choice_fill();
	enum fill_in fill_in = (enum fill_in)choice_1;
	switch (fill_in)
	{
		case (fill_randomm):
			fill_random(size, array, range_right, range_left);
			puts("\nМассив заполнен рандомными числами:\n");
			break;
		case (fill_by_my_self):
			fill_by_your_self(size, array, range_right, range_left);
			puts("\nВы заполнили массив:\n");
			break; 
		default:
			printf_s("Вы ввели неправильное значение\n");
			errno = EIO;
			return 1;
	}
	print_array(array, size);
	int choice_2 = get_choice_action();
	enum action action = (enum action)choice_2;
	switch (action)
	{
		case (sum_10):
			printf_s("Сумма отрицательных чисел, кратных 10 = %d\n", get_sum_10(array, size));
			break;
		case (exchange):
			printf_s("\nМассив до:\t");
			print_array(array, size);
			printf_s("\nМассив после:\t");
			exchange_array(array, size);
			print_array(array, size);
			break;
		case (para):
			if (is_exist_para(array, size))
			{
				puts("\nСуществует такая пара элементов с произедением, равным заданному числу\n");
			}
			else
			{
				puts("\nНе существует такой пары элементов с произедением, равным заданному числу\n");
			}
			break;
		default:
			errno = EIO;
			perror("Вы ввели неверное значение");
			return 1;
	}
	free_array(array);
	puts("\nGame over");
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
	size_t k = get_size_t(get_value("Сколко элементов хотите поменять?\t"));
	assert(k < size);
	size_t l = k / 2;
	for (int i = 0; i < l; i++)
	{
		swap(&(array[i]), &(array[k - i - 1]));
	}
}

void swap(int* a, int* b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

bool is_exist_para(int* array, size_t size)
{
	int number = get_value("Введите число\t");
	for (size_t i = 0; i < size; i++)
	{
		if (array[i] * array[i + 1] == number)
		{
			return true;
		}
	}
	return false;
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

size_t get_size_t(int value)
{
	if (value <= 0)
	{
		errno = ENOMEM;
		perror("wrong size");
		abort();
	}
	return (size_t)value;
}

void check_range(int range_right, int range_left)
{
	if (range_left > range_right)
	{
		errno = EIO;
		perror("ERROR");
		abort();
	}
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

int fill_random(const size_t size, int* array, int range_right, int range_left)
{
	unsigned int ttime = time(NULL);
	srand(ttime);
	for (size_t i = 0; i < size; i++) {
		array[i] = rand() % (range_right - range_left + 1) + range_left;
	}
	return 0;	
}

int fill_by_your_self(const size_t size, int* array, int range_right, int range_left)
{
	for (size_t i = 0; i < size; i++)
	{
		int element = get_value("Введите элемент массива в введенном диапазоне:\t");
		if (element > range_right || element < range_left)
		{
			perror("ERROR");
			errno = EIO;
			abort();
		}
		array[i] = element;
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