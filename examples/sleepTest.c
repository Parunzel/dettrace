#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <unistd.h>

int i;

void sigalrm() {
  printf("%d\n", i);
  exit(0);
}

int main() {
  signal(SIGALRM, sigalrm);
  setitimer(ITIMER_REAL, &(struct itimerval){{}, {1}}, 0);
  for (;;) {
    i++;
    getpid();
  }
}
