#include <stdio.h>

int main() {
	char testChar[5];

	printf("Enter a char: ");
	scanf("%c%c%c%c%c", &testChar[1], &testChar[2], &testChar[3], &testChar[4], &testChar[5]);
	printf("Next char = %.*s\n", (int)sizeof(testChar), testChar);

	return 0;
}

