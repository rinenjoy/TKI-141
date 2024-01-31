#include <iostream>

using namespace std;

int main()
{
	/*for (int i = 0; i <= 14; i++)
	{
		if (i == 3)
			continue;
		if (i > 10)
			break;
		cout << "i: " << i << endl;
	}*/

	srand(time(NULL));
	int rand_num = 1 + rand() % 10;
	bool stop = false;
	int a = 0;
	do {
		cout << "Enter number\t";
		cin >> a;
		if (a != rand_num)
		{
			cout << "Wrong number\n";
		}
		else
		{
			stop = true;
		}
	} while (!stop);
	cout << "You are wright";
	return 0;
}