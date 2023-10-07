#include <stdio.h>
#include <stdlib.h>

int main() {
	get();
	return 0;
}

double get()
{
	double value;
	puts("¬ведите координату = ");
	int result = scanf_s("%lf", &value);
	if (result != 1) 
	{
		puts("error");
		abort();
	}
	double z = value;
	return z;
}
