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
enum fill_in {fill_randomm, fill_by_my_self};

/*
* @brief Выбор пользователя
* @param min_middle Заменить минимальный элемент массива на средний (количество элементов – нечетно)
* @param delete_5 Удалить из массива все элементы, в записи которых есть цифра 5
* @param new_array Из элементов массива C сформировать массив A той же размерности по правилу: если номер i элемента четный, то Ai=Ci2, если нечетный, то Ai=2Ci.
*/
enum action {min_middle; delete_5; new_array};

/*
* @brief Заменяет минимальный элемент массива на средний
* @param array - массив
* @param min - минимальный элемент
* @param middle - средний элемент
* @param size - размер массива
*/
void min_middle(int* array, int min, int middle, size_t size);

/*
* @brief Ищет минимальный элемент массива
* @param array - массив
* @param size - размер массива
* @return минимальный элемент
*/
int min_element(int* array, size_t size);

/*
* @brief Ищет средний элемент массива
* @param array - массив
* @param size - размер массива
* @return средний элемент
*/
int middle_element(int* array, size_t size);

/*
* @brief Удаляет из массива все элементы, в записи которых есть цифра 5
* @param array - массив
* @param size - размер массива
*/
void delete_5(int* array, size_t size);

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
* @brief проверяет чтобы введенное значение было > 0 и нечетное
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
		puts("\nМассив заполнен рандомными числами:\n");
		break;
	case (fill_by_my_self):
		fill_by_your_self(size, array);
		puts("\nВы заполнили массив:\n");
		break;
	default:
		printf_s("Вы ввели неправильное значение\n");
		return errno;
		abort();
	}
	print_array(array, size);
	int choice_2 = get_choice_action();
	enum action action = (enum action)choice_2;

	free_array(array);
	puts("\nGame over");
	return 0;

}

int get_choice_fill()
{
	printf_s("\n\n%d - Заполнить массив рандомными числами\n%d - заполнить массив самостоятельно\n\n", fill_randomm, fill_by_my_self);
	int choice = get_value("Выберите действие:\t");
	return choice;
}

int get_choice_action()
{
	int choice = get_value("Выберите действие:\t");
	return choice;
}

void min_middle(int* array, int min, int middle, size_t size)
{

}

int min_element(int* array, size_t size)
{

	return min;
}

int middle_element(int* array, size_t size)
{
	
	return middle;
}

void delete_5(int* array, size_t size)
{
	for (int i = 0; i < size; i++)
	{
		char str [5];
	}
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
	if (value <= 0 || value % 2 == 0)
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