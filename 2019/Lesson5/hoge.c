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

  //   WIFEXITED(status) : 子プロセスが正常に終了した場合に真を返します。「正常」とは、exit関数の呼び出しや、main関数から復帰した場合です。
  // WEXITSTATUS(status) : 子プロセスの終了ステータスを返します。終了ステータスはexit関数やmain関数の引数で指定した値です。なお、このマクロはWIFEXITEDマクロが真を返した場合だけ使用したほうがよいでしょう。
  // WIFSIGNALED(status) : 子プロセスがシグナルにより終了した場合に真を返します。
  //    WTERMSIG(status) : 子プロセス終了の原因となったシグナルの番号を返します。このマクロはWIFSIGNALEDマクロが真を返した場合だけ使用したほうがよいでしょう。
  printf("This is parent. The child (pid=%d) existed with status(%d). \n", child, WIFEXITED(status));
}