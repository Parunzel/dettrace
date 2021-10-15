#include <stdio.h>

int main() {
  char testChar;

  printf("Enter a char: ");
  testChar = getc(stdin);
  printf("Char = ");
  putc(testChar, stdout);
  printf("\n");

  return 0;
}
