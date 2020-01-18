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
	for( count=0 ; count < P_MAX && (pid[count] = fork()) > 0 ; count++ );

  //親プロセスはすべての子プロセスの終了を待つ
	if( count == P_MAX ){
		for( count = 0 ; count < P_MAX ; count++ )
    {
			wait(&val);
		}
  // 子プロセス
	} else if( pid[count] == 0)
  {
		printf("child:%d\n",count);
    printf("This is child. (pid=%d)\n", getpid());
		exit(0);
	} else
  {
    perror("child process") ;
    exit(0);
	}
	return 0;
}

