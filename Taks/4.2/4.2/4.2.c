#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <time.h>
#include <stdbool.h>

/*
* @brief Выбор пользователя
* @brief fill_random - Заполнение массива пользователем
* @brief fill_by_my_self - Заполнение массива рандомными числами
*/
enum fill_in {fill_randomm, fill_by_my_self};

/*
* @brief Выбор пользователя
* @brief min_middle_change Заменить минимальный элемент массива на средний (количество элементов – нечетно)
* @brief delete_element_with_5 Удалить из массива все элементы, в записи которых есть цифра 5
* @brief new_array Из элементов массива C сформировать массив A той же размерности по правилу: если номер i элемента четный, то Ai=Ci2, если нечетный, то Ai=2Ci.
*/
enum action {min_middle_change, delete_element_with_5, new_array};

/*
* @brief сортирует массив
* @param array - массив
* @param size - размер массива
*/
void bubble_sort(int* array, size_t size);

/*
* @brief меняет два элемента местами
* @param a - элемент массива 
* @param b - элемент массива
*/
void swap(int* a, int* b);

/*
* @brief меняет минимальный элемент на средний
* @param array - массив
* @param size - размер массива
* @return изменённый массив
*/
int* min_middle(int* array, size_t size);

/*
* @brief проверяет число на чётность
* @param value - введенная переменная
* @return true/false
*/
bool check_parity(size_t size);

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
* @brief копирует массив
* @param array - массив
* @param size - размер массива
* @return скопироанный массив
*/
int* copy_array(int* array, size_t size);

/*
* @brief считает сколько элементов с цифрой 5 в числе
* @param array - массив
* @param size - размер массива
* @return кол-во элементов с цифрой 5 в числе
*/
int amount_5(int* array, size_t size);

/*
* @brief Определяет, есть ли цифра пять в числе
* @param а - элемент массива(число)
* @return true, если цифра пять есть в числе
*/
bool is_5(int a);

/*
* @brief создает и заполняет массив элементами без цифры 5
* @param array - массив
* @param size - размер массива
* @param k - кол-во элементов с цифрой 5 в числе
* @return заполненный массив
*/
int* get_array_5(int* array, size_t k, size_t size);

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
* @brief создает и заполняет массив по правилу:  если номер i элемента четный, то Ai=Ci2, если нечетный, то Ai=2Ci
* @param array - массив
* @param size - размер массива
* @return новый массив
*/
int* get_new_array(int* array, const size_t size);

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
	const size_t size = get_size(get_value("Введите размер массива\t"));
	int* array = get_array(size);
	enum fill_in fill_in = (enum fill_in)get_choice_fill();
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
		errno = EIO;
		perror("Вы ввели неверное значение");
		return 1;
	}
	print_array(array, size);
	enum action action = (enum action)get_choice_action();
	switch (action)
	{
	case (min_middle_change):
		printf_s("\n\n%d - Минимальный элемент\n%d - Средний элемент\n", min_element(array, size), middle_element(array, size));
		puts("\nМассив после:\t");
		print_array(min_middle(array, size), size);
		break;
	case (delete_element_with_5):
		puts("\nМассив до:\t");
		print_array(array, size);
		puts("\nМассив после:\t");
		print_array(get_array_5(array, amount_5(array, size), size), (size - amount_5(array, size)));
		break;
	case (new_array):
		print_array(get_new_array(array, size), size);
		break;
	default:
		errno = EIO;
		perror("Вы ввели неверное значение");
		return 1;
	}
	free_array(array);
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
	printf_s("\n%d - Заменить минимальный элемент массива на средний(для выполнения этого задания размер массива должен быть нечетным числом)\n%d - Удалить из массива все элементы, в записи которых есть цифра 5\n%d - Из элементов массива C сформировать массив A той же размерности по правилу: если номер i элемента четный, то Ai=Ci^2, если нечетный, то Ai=2Ci.\n", min_middle_change, delete_element_with_5, new_array);
	int choice = get_value("\nВыберите действие:\t");
	return choice;
}

void bubble_sort(int* array, size_t size)
{
	int* B = copy_array(array, size);
	for (size_t i = 0; i < size - 1; i++)
	{
		for (size_t j = 0; j < size - i - 1; j++)
		{
			if (B[j] > B[j + 1])
			{
				swap(&(B[j]), &(B[j + 1]));
			}
		}
	}
}

void swap(int* a, int* b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

int* min_middle(int* array, size_t size)
{
	if (check_parity(size))
	{
		int* B = copy_array(array, size);
		for (int j = 0; j < size; j++)
		{
			if (B[j] == min_element(B, size))
			{
				B[j] = middle_element(B, size);
				break;
			}
		}
		return B;
	}
}

bool check_parity(size_t size)
{
	size_t a = size;
	if (a % 2 == 0)
	{
		errno = EIO;
		perror("Неверный размер(должен быть нечетным числом)");
		abort();
	}
	return true;
}

int min_element(int* array, size_t size)
{
	int min = array[0];
	for (size_t i = 1; i < size; i++)
	{
		if (array[i] < min)
		{
			min = array[i];
		}
	}
	return min;
}

int middle_element(int* array, size_t size)
{
	int* B = copy_array(array, size);
	bubble_sort(B, size);
	int middle = B[(size / 2)];
	free_array(B);
	return middle;
}

int* copy_array(int* array, size_t size)
{
	int* B = get_array(size);
	for (int i = 0; i < size; i++) 
	{
		B[i] = array[i];
	}
	return B;
}

int amount_5(int* array, size_t size)
{
	int k = 0;
	for (int i = 0; i < size; i++)
	{
		if (is_5(array[i]))
		{
			k++;
		}
	}
	return k;
}

bool is_5(int a)
{
	int b = abs(a);
	while (b > 0)
	{
		if (b % 10 == 5)
		{
			return true;
		}
		b = b / 10;
	}
	return false;
}

int* get_array_5(int* array, size_t k, size_t size)
{
	int* array_without_5 = get_array(size - k);
	int i = 0;
	int j = 0;
	while (i < size)
	{
		if (is_5(array[i]))
		{
			i++;
		}
		else
		{
			array_without_5[j] = array[i];
			i++;
			j++;
		}
	}
	return array_without_5;
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

int* get_new_array(int* array, const size_t size)
{
	int* new_array = get_array(size);
	for (int i = 0; i < size; i++)
	{
		if (i % 2 == 0)
		{
			new_array[i] = array[i] * array[i];
		}
		else
		{
			new_array[i] = 2 * array[i];
		}
	}
	return new_array;
}

int fill_random(const size_t size, int* array)
{
	unsigned int ttime = (unsigned int)time(NULL);
	srand(ttime);
	int A = get_value("Введите левую границу диапозона");
	int B = get_value("Введите правую границу диапозона");
	for (size_t i = 0; i < size; i++) {
		array[i] = rand() % (B - A + 1) + A;
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