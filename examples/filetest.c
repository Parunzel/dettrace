#include <stdio.h>

int main()
{
  char ch;
  FILE *f;
  f = fopen("/home/christian/Masterthesis/dettrace/examples/testfile.txt", "r");
  printf("Content of file:\n");
  while((ch = fgetc(f)) != EOF) printf("%c", ch);
  fclose(f);
  return 0;
}
