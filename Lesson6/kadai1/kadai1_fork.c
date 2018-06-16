#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <errno.h>

void do_child(int x);

int main(int argc,char** argv){
  int child, status,i;
  int val = atoi(argv[1]);
  for(i=0; i<val; i++){
    child = fork();
    if(child == 0){
      do_child(val);
    } else {
      if(wait(&status) < 0){
        perror("wait");
        exit(1);
      }
      printf("This is parent + %d\n", getpid());
    }
  }
}

void do_child(int x){
  int i;
  for(i=0;i<3;i++){
    printf("func(%d): %d\n",x,i);
    printf("pid=%d\n",getpid());
  }
}
