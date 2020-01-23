#include <stdio.h>     /* printf, stderr, fprintf */
#include <sys/types.h> /* pid_t */
#include <unistd.h>    /* _exit, fork, getpid */
#include <stdlib.h>    /* exit */
#include <errno.h>     /* errno */

#define P_MAX 10

int main(){
  int count, val;
	int pid[P_MAX];

	// 子プロセス生成。子プロセスは次の行から始まるため、
	// このような記述をすると、子プロセスが子プロセスを生成しないで済む。
	// for( count=0 ; count < P_MAX && (pid[count] = fork()) > 0 ; count++ );
  count = 0;
  while (count < P_MAX)
  {
    // fork()
    //
    // Success :
    //   Parent Pid => Child Pid
    //   Child  Pid => 0
    // Failed  :
    //   Parent Pid => -1
    //   Child  Pid => errno
    if ((pid[count] = fork()) > 0)
    {
      count++;
    } else
    {
      break;
    }
  }

  //親プロセスはすべての子プロセスの終了を待つ
	if( count == P_MAX ){
		for( count = 0 ; count < P_MAX ; count++ )
    {
			wait(&val);
		}
  // 子プロセス
	} else if( pid[count] == 0)
  {
		printf("child No:%d\n",count+1);
    printf("This is child. (pid=%d)\n", getpid());
		exit(0);
	} else
  {
    perror("child process") ;
    exit(0);
	}
	return 0;
}

