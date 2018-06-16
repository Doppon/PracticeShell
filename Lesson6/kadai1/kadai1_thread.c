#include<stdio.h>
#include<stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <sys/types.h>

void func(int x);

int main(int argc,char **argv){
    int i, val = atoi(argv[1]);
    pthread_t td;
    for(i=0;i<val;i++){
      pthread_create(&td,NULL,(void *)func,(void *)val);
      pthread_join(td,NULL);
    }
}

void func(int x){
  int i;
  for(i=0; i<3; i++){
    printf("func(%d): %d\n", x, i);
    printf("tid = %d\n", pthread_self());
  }
}
