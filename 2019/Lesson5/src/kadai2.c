#include <stdio.h>     /* printf, stderr, fprintf */
#include <sys/types.h> /* pid_t */
#include <unistd.h>    /* _exit, fork, getpid */
#include <stdlib.h>    /* exit */
#include <errno.h>     /* errno */

void do_child()
{
  printf("This is child  (pid = %d)\n", getpid());
}

int main(void)
{  
  int child, status;

  child = fork();

  if(child == 0)
  {
    do_child();
  } else
  {
    if (wait(&status) < 0)
    {
      perror("wait");
      // Define EXIT_FAILURE 1 for stdlib.h
      exit(EXIT_FAILURE);
    }
    printf("This is parent (pid = %d)\n", getpid());  
  }
}
