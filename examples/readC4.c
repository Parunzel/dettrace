#include <stdio.h>

int main() {
	char testChar1[10] = "";
	char testChar2[10] = "";

	printf("Enter first string: ");
	fflush(stdout);
	int n1 = read(0, &testChar1, 10);
	printf("Return value %d of first string %.*s\n", n1, n1, testChar1);
	// printf("First string: %.*s\n", n1, testChar1);

	printf("Enter second string: ");
	fflush(stdout);
	int n2 = read(0, &testChar2, 10);
	printf("Return Value %d of second string: %.*s\n", n2, n2, testChar2);
	// printf("Second string: %.*s\n", n2, testChar2);

	return 0;
}
