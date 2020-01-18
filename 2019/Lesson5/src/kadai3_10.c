#include <stdio.h>     /* printf, stderr, fprintf */
#include <sys/types.h> /* pid_t */
#include <unistd.h>    /* _exit, fork, getpid */
#include <stdlib.h>    /* exit */
#include <errno.h>     /* errno */

#define P_MAX 10

int main(){
  int i, val;
	int pid[P_MAX];

	// 子プロセス生成。子プロセスは次の行から始まるため、
	// このような記述をすると、子プロセスが子プロセスを生成しないで済む。
	for( i=0 ; i < P_MAX && (pid[i] = fork()) > 0 ; i++ );

  //親プロセスはすべての子プロセスの終了を待つ
	if( i == P_MAX ){
		for(  i = 0 ; i < P_MAX ; i++ ){
			wait(&val);
		}
  // 子プロセス
	}else if( pid[i] == 0)
  {
		printf("child:%d\n",i);
		exit(0);
	}else
  {
    perror("child process") ;
    exit(0);
	}
	return 0;
}

