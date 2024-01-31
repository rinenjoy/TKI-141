#include <iostream>
#include <cstdlib>
#include <time.h>

using namespace std;

void chek_out(int a);

int random();

int main()
{
	int a;
	cout << "Введие число\t";
	cin >> a;
	chek_out(a);
	cout << "Good Job\n";

	int b;
	cout << "Введие число\t";
	cin >> b;
	switch (b)
	{
	case 6:
		cout << "double cool\n";
		break;
	case 3:
		cout << "poop\n";
		break;
	default:
		cout << "YOU ARE GAY\n";
		break;
	}

	int back = random();
	cout << "Random number = " << back << endl;
	return 0;
}

void chek_out(int a)
{
	if (a > 3)
	{
		cout << "YOU ARE GAY\n";
		cout << "Введие normal число\t";
		int b;
		cin >> b;
		chek_out(b);
	}
}

int random()
{
	srand(time(NULL));
	return -100 + rand() % 100;
}