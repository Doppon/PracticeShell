#include <stdio.h>     /* printf, stderr, fprintf */
#include <sys/types.h> /* pid_t */
#include <unistd.h>    /* _exit, fork, getpid */
#include <stdlib.h>    /* exit */
#include <errno.h>     /* errno */

void do_child()
{
  printf("This is child.  (pid=%d)\n", getpid());
  exit(2);
}

int main()
{
  int child, status;

  // When Failed to fork()
  if ((child = fork()) < 0)
  {
    perror("fork");
    // Define EXIT_FAILURE 1 for stdlib.h
    exit(EXIT_FAILURE);
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
      // Define EXIT_FAILURE 1 for stdlib.h
      exit(EXIT_FAILURE);
    }
  }
  printf("This is parent. (pid=%d)\n", getpid());
  //   WIFEXITED(status) : 子プロセスが正常に終了した場合に真を返します。「正常」とは、exit関数の呼び出しや、main関数から復帰した場合です。
  // WEXITSTATUS(status) : 子プロセスの終了ステータスを返します。終了ステータスはexit関数やmain関数の引数で指定した値です。なお、このマクロはWIFEXITEDマクロが真を返した場合だけ使用したほうがよいでしょう。
  // WIFSIGNALED(status) : 子プロセスがシグナルにより終了した場合に真を返します。
  //    WTERMSIG(status) : 子プロセス終了の原因となったシグナルの番号を返します。このマクロはWIFSIGNALEDマクロが真を返した場合だけ使用したほうがよいでしょう。
  printf("The child (pid=%d) existed with status(%d). \n", child, WIFEXITED(status));
}
