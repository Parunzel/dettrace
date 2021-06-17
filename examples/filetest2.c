#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>

int main()
{
  char ch[2];
  char x[] = "x";
  int f;
  int r;

  // Use your own file here for this program to work.
  f = open("/home/christian/Masterthesis/dettrace/examples/testfile.txt", O_RDWR | O_APPEND);

  while (r = read(f, &ch, 2) != 0) {
    printf("%c%c \n", ch[0], ch[1]);
    fflush(stdout);
  }

  // For writing-test purposes.
  // write(f, &x, 1);

  return 0;
}
