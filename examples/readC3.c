#include <stdio.h>

int main() {
	char testChar[5];

	printf("Before: %p\n", testChar);

	read(0, &testChar, 5);

	printf("%.*s\n", (int)sizeof(testChar), testChar);

	return 0;
}
