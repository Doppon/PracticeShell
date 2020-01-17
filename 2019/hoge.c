#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
extern char **environ;

void do_child()
{
  printf("");
  exit(2);
}

main()
{
  int child, status;
}