#include <stdio.h>
#include <math.h>
/*
* формула для получения а
*/
void get_a(float x, float y, float z)
{
	float a = pow(x, 3) * pow(tan(pow(x + y, 2)), 2) + z / sqrt(x + y);
	printf("a = %f\n", a);
}
/*
* формула для получения b
*/
void get_b(float x, float y, float z)
{
	float b = (y * pow(x, 2) - z) / (exp(x * z) - 1);
	printf("b = %f\n", b);
}
/*
* контрольные значения для получения результата
*/
int main()
{
	get_a(0.61, 3.4, 16.5);
	get_b(0.61, 3.4, 16.5);
}