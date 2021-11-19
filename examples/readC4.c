#include <stdio.h>

int main() {
	char testChar1[10];
	char testChar2[10];

	read(0, &testChar1, 10);
	printf("Read:%*s\n", (int)sizeof(testChar1), testChar1);

	read(0, &testChar2, 10);
	printf("Read:%.*s\n", (int)sizeof(testChar2), testChar2);




	return 0;
}
