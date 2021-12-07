#include <stdio.h>
#include <stdlib.h>

int main () {

	int num1 = 0;
	int num2 = 0;
	int num3 = 0;
	int sum = 0;

	printf("Enter first number: ");
	int n1 = scanf("%d", &num1);
	printf("Entered %d bytes: %d\n", n1, num1);

	printf("Enter second number: ");
	int n2 = scanf("%d", &num2);
	printf("Entered %d bytes: %d\n", n2, num2);

	printf("Enter third number: ");
	int n3 = scanf("%d", &num3);
	printf("Entered %d bytes: %d\n", n3, num3);

	sum = num1 + num2 + num3;
	printf("Result = %d\n", sum);

}
