#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
extern char **environ;

void do_child()
{
  printf("This is childe(pid=%d).\n", getpid());
  exit(2);
}

int main()
{
  int child, status;

  // When Failed to fork()
  if ((child = fork()) < 0)
  {
    perror("fork");
    exit(1);
  }

  // When Success to fork()
  if (child==0)
  {
    do_child();
  } else
  {
    if (wait(&status) < 0)
    {
      perror("wait");
      exit(1);
    }
  }

  printf("This is parent. The child (pid=%d) existed with status(%d). \n", child, WIFEXITED(status));
}