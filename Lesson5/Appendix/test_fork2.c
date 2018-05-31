#include <stdio.h>   /* printf, stderr, fprintf */
#include <sys/types.h> /* pid_t */
#include <unistd.h>  /* _exit, fork */
#include <stdlib.h>  /* exit */
#include <errno.h>   /* errno */

do_child(){
  printf("This is child = %d\n", getpid());
}

int main(void){
  
  int child, status;

  child = fork();

  if(child == 0){
    do_child();
  } else {
    if(wait(&status) < 0){
      perror("wait");
      exit(1);
    }
    printf("This is parent = %d\n", getpid());  
  }
  
}
