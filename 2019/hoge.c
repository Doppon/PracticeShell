#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
extern char **environ;

void do_child()
{
  printf("This is childe(pid=%d).\n", getpid());
  exit(2);
}

main()
{
  int child, status;

  if ((child = fork()) < 0)
  {
    perror("fork");
    exit(1);
  }

  if (child==0)
  {
    do_child();
  }
}