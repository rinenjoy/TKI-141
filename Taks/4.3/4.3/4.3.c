#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <time.h>

/*
* @brief Выбор пользователя
* @brief fill_random - Заполнение массива пользователем
* @brief fill_by_my_self - Заполнение массива рандомными числами
*/
enum fill_in {fill_randomm, fill_by_my_self};

/*
* @brief Выбор пользователя
* @brief change_max_zero Заменить максимальный элемент каждой строки нулем
* @brief put_str_0 Вставить перед всеми строками, первый элемент которых делится на 3, строку из нулей
*/
enum action {change_max_zero, put_str_0};

/*
* @brief Вставляет перед всеми строками, первый элемент которых делится на 3, строку из нулей
* @param array - массив
* @param line - кол-во строк
* @param column - кол-во столбцов
* @return изменённый массив
*/
int** new_array_str_0(int** array, const size_t line, const size_t column);

/*
* @brief Считает строки, первый элемент которых делится на 3
* @param array - массив
* @param line - кол-во строк
* @return кол-во строк
*/
int line_amount_3(const int** const array, const size_t line);

/*
* @brief Заменяет максимальный элемент каждой строки нулем
* @param array - массив
* @param line - кол-во строк
* @param column - кол-во столбцов
* @return изменённый массив
*/
int** max_zero(const int** const array, const size_t line, const size_t column);

/*
* @brief Ищет максимальный элемент массива
* @param array - массив
* @param column - размер массива
* @return максимальный элемент
*/
int max_element(int* array, size_t column);

/*
* @brief Предлагает пользователю выбрать действие
* @return введенный номер действия
*/
int get_choice_fill();

/*
* @brief Предлагает пользователю выбрать действие
* @return введенный номер действия
*/
int get_choice_action();

/*
* @brief Проверяет введенное значение
* @param massage - сообщение для пользователя
* @return переменную
*/
int get_value(const char* massage);

/*
* @brief Проверяет чтобы введенное значение было > 0 и нечетное
* @param value - введенное значение
* @return размер массива
*/
size_t get_size(int value);

/*
* @brief Создает двумерный массив
* @param line - кол-во строк
* @param column - кол-во столбцов
* @return двумерный массив
*/
int** get_array(const size_t line, const size_t column);

/*
* @brief Создает одномерный массив(строку)
* @param column - кол-во элементов в строке
* @return строку
*/
int* get_line_0(const size_t column);

/*
* @brief Копирует массив
* @param array - массив
* @param line - кол-во строк
* @param column - кол-во столбцов
* @return копированный массив
*/
int** copy_array(const int** const array, const size_t line, const size_t column);

/*
* @brief Заполняет массив рандомными числами
* @param array - массив
* @param line - кол-во строк
* @param column - кол-во столбцов
* @return 0 - в случае успеха
*/
int fill_random(int** array, const size_t line, const size_t column);

/*
* @brief Пользователь заполняет массив
* @param array - массив
* @param line - кол-во строк
* @param column - кол-во столбцов
* @return 0 - в случае успеха
*/
int fill_by_your_self(int** array, const size_t line, const size_t column);

/*
* @brief Чистит использованную память
* @param array - массив
* @param line - кол-во строк
* @param column - кол-во столбцов
*/
void free_array(int** array, size_t line);

/*
* @brief Печатает массив
* @param array - массив
* @param line - кол-во строк
* @param column - кол-во столбцов
*/
void print_array(const int** const array, const size_t line, const size_t column);

/*
* @brief Точка входа в программу
* @return 0, в случае успешного завершения программы
*/
int main() {
	size_t line = get_size(get_value("Введите кол-во строк:\t"));
	size_t column = get_size(get_value("Введите кол-во столбцов:"));
	int** array = get_array(line, column);
	enum fill_in fill_in = (enum fill_in)get_choice_fill();
	switch (fill_in)
	{
	case (fill_randomm):
		fill_random(array, line, column);
		puts("\nМассив заполнен рандомными числами:\n");
		break;
	case (fill_by_my_self):
		fill_by_your_self(array, line, column);
		puts("\nВы заполнили массив:\n");
		break;
	default:
		errno = EIO;
		perror("\nВы ввели неверное значение\n");
		return 1;
	}
	print_array(array, line, column);
	enum action action = (enum action)get_choice_action();
	int k = line_amount_3(array, line);
	int** new_array = NULL;
	switch (action)
	{
	case (change_max_zero):
		puts("\nИзменённый массив:\n");
		print_array(max_zero(array, line, column), line, column);
		free_array(max_zero(array, line, column), line);
		break;
	case (put_str_0):
		puts("\nИзменённый массив:\n");
		new_array = new_array_str_0(copy_array(array, line, column), line, column);
		print_array(new_array, line + k, column);
		free_array(new_array, line + k);
		break;
	default:
		errno = EIO;
		perror("\nВы ввели неверное значение");
		return 1;
	}
	free_array(array, line);
	puts("\n\nGame over");
	return 0;
}

int get_choice_fill()
{
	printf_s("\n\n%d - Заполнить массив рандомными числами\n%d - заполнить массив самостоятельно\n", fill_randomm, fill_by_my_self);
	int choice = get_value("\nВыберите действие:\t");
	return choice;
}

int get_choice_action()
{
	printf_s("\n%d - Заменить максимальный элемент каждой строки нулем\n%d - Вставить перед всеми строками, первый элемент которых делится на 3, строку из нулей\n", change_max_zero, put_str_0);
	int choice = get_value("\nВыберите действие:\t");
	return choice;
}

int** new_array_str_0(int** array, const size_t line, const size_t column)
{
	int k = line_amount_3(array, line);
	int** new_array = get_array(line + k, column);
	int i = 0;
	int j = 0;
	while (i < line && j < line + k)
	{
		if (array[i][0] % 3 == 0)
		{
			new_array[j] = get_line_0(column);
			new_array[j + 1] = array[i];
			i++;
			j+=2;
		}
		else
		{
			new_array[j] = array[i];
			i++;
			j++;
		}
	}
	return new_array;
}

int line_amount_3(const int** const array, const size_t line)
{
	int k = 0;
	for (size_t i = 0; i < line; i++)
	{
		if (array[i][0] % 3 == 0)
		{
			++k;
		}
	}
	return k;
}

int** max_zero(const int** const array, const size_t line, const size_t column)
{
	int** max_zero_array = copy_array(array, line, column);
	for (size_t i = 0; i < line; i++)
	{
		int max = max_element(max_zero_array[i], column);
		for (size_t j = 0; j < column; j++)
		{
			if (max_zero_array[i][j] == max)
			{
				max_zero_array[i][j] = 0;
				break;
			}
		}
	}
	return max_zero_array;
}

int max_element(int* array, size_t column)
{
	int max = array[0];
	for (size_t i = 1; i < column; i++)
	{
		if (array[i] > max)
		{
			max = array[i];
		}
	}
	return max;
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

int** get_array(const size_t line, const size_t column)
{
	int** array = (int**)malloc(line * sizeof(int*));
	for (int i = 0; i < line; i++)
	{
		array[i] = (int*)malloc(column * sizeof(int));
	}
	return array;
}

int* get_line_0(const size_t column)
{
	int* line = (int*)malloc(column * sizeof(int));
	for (int i = 0; i < column; i++)
	{
		line[i] = 0;
	}
	return line;
}

int** copy_array(const int** const array, const size_t line, const size_t column)
{
	int** cop_array = get_array(line, column);
	for (size_t i = 0; i < line; i++)
	{
		for (size_t j = 0; j < column; j++)
		{
			cop_array[i][j] = array[i][j];
		}
	}
	return cop_array;
}

int fill_random(int** array, const size_t line, const size_t column)
{
	unsigned int ttime = (unsigned int)time(NULL);
	srand(ttime);
	for (size_t i = 0; i < line; i++) {
		for (size_t j = 0; j < column; j++)
		{
			array[i][j] = rand() % 201 - 100;
		}
	}
	return 0;
}

int fill_by_your_self(int** array, const size_t line, const size_t column)
{
	for (size_t i = 0; i < line; i++)
	{
		for (size_t j = 0; j < column; j++)
		{
			array[i][j] = get_value("Введите элемент массива\t");
		}
	}
	return 0;
}

void free_array(int** array, size_t line)
{
	for (size_t i = 0; i < line; i++)
	{
		if (NULL != array[i])
		{
			free(array[i]);
		}
	}
	if (NULL != array)
	{
		free(array);
	}
}

void print_array(const int** const array, const size_t line, const size_t column)
{
	for (size_t i = 0; i < line; i++)
	{
		puts("\n");
		for (size_t j = 0; j < column; j++)
		{
			printf_s("%d\t", array[i][j]);
		}
	}
	puts("\n");
}