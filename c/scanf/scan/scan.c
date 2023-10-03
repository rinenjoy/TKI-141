#include <stdio.h>
void main() {
	int password;
	printf("Enter your password: ");
	scanf_s("/n%d", &password);
	printf("Your password is : %d", password);
	return 0;
}