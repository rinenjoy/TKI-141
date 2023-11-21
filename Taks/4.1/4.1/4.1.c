#include <stdio.h>
#include <stdlib.h>
#include <float.h>
#include <errno.h>
#include <time.h>
#include <stdbool.h>

/*
* @brief Выбор пользователя
* @param fill_random - Заполнение массива пользователем
* @param fill_by_my_self - Заполнение массива рандомными числами
*/
enum fill_in{fill_randomm, fill_by_my_self};

/*
* @brief Выбор пользователя
* @param sum_10 - Найти сумму отрицательных элементов, значения которых кратно 10
* @param exchange - Заменить первые k элементов массива на те же элементы в обратном порядке
* @param para - Определить, есть ли пара соседних элементов с произведением, pавным заданном числу
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
* @brief Меняет положение первых k элементов 
* @param array - массив 
* @param size - размер массива
* @return изменённый массив
*/
void exchange_array(int* array,size_t size, size_t k);

/*
* @brief определяет существует ли такая пара элементов с произедением, равным заданному числу
* @param array - массив
* @param chislo - введенное число
* @param size - размер массива
* @return True/False
*/
bool is_exist_para(int* array,int chislo,size_t size);

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
	int size_0 = get_value("Введите размер массива\t");
	const size_t size = get_size_t(size_0);
	int* array = get_array(size);
	int range_left = get_value("\nВведите левую границу диапозона\t");
	int range_right = get_value("\nВведите правую границу диапозона\t");
	if (range_left > range_right)
	{
		errno = EIO;
		perror("ERROR");
		return 1;
	}
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
	int k_0;
	int k;
	int number;
	switch (action)
	{
		case (sum_10):
			printf_s("Сумма отрицательных чисел, кратных 10 = %d\n", get_sum_10(array, size));
			break;
		case (exchange):
			k_0 = get_value("Сколко элементов хотите поменять?\t");
			k = get_size_t(k_0);
			printf_s("\nМассив до:\t");
			print_array(array, size);
			printf_s("\nМассив после:\t");
			exchange_array(array, size, k);
			print_array(array, size);
			break;
		case (para):
			number = get_value("Введите число\t");
			if (is_exist_para(array, number, size) == true)
			{
				puts("\nСуществует такая пара элементов с произедением, равным заданному числу\n");
			}
			else
			{
				puts("\nНе существует такой пары элементов с произедением, равным заданному числу\n");
			}
			break;
		default:
			perror("ERROR");
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

void exchange_array(int* array, size_t size, size_t k)
{
	int l = k / 2;
	if (l % 2 == 1)
	{
		l++;
	}
	for (int i = 0; i < size && i < l; i++)
	{
		int temp = array[i];
		array[i] = array[k - i - 1];
		array[k - i - 1] = temp;
	}
}

bool is_exist_para(int* array, int number,size_t size)
{
	size_t k = 0; //кол-во пар
	for (size_t i = 0; i < size; i++)
	{
		int p = array[i] * array[i + 1];
		if (p == number)
			k++;
		if (k > 0) 
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
	time_t ttime = time(NULL);
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