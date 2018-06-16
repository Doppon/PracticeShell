#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <sys/types.h>

void func1(int x);

int main (void){
  pthread_t t1;
  pthread_create(&t1,NULL,(void *)func1,(void *)0);
  pthread_join(t1,NULL);
}

void func1(int x){
  int i;
  for(i=0; i<200000000; i++){
    x += 1;
  }
  printf("計算結果:%d\n",x);
}
