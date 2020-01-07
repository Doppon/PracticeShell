#include <stdio.h>
#include <pthread.h>

void func1(int x);
void func2(int x);

int shared_total=0;
pthread_mutex_t mutex;

int main (void){
  pthread_mutex_init(&mutex,NULL);
  pthread_t t1;
  pthread_t t2;
  pthread_create(&t1, NULL,(void*)func1,(void *)100000000);
  pthread_create(&t2, NULL,(void*)func2,(void *)100000000);  
  pthread_join(t1, NULL);
  pthread_join(t2, NULL);
  printf("計算結果:%d\n", shared_total);
}

void func1 (int x){
  int i;
  pthread_mutex_lock(&mutex);
  for(i =0;i<x; i++){
    shared_total=shared_total+1;
  }
  pthread_mutex_unlock(&mutex);
}

void func2 (int x){
  int i;
  pthread_mutex_lock(&mutex);
  for (i =0;i<x; i++){
    shared_total=shared_total+1;
  }
  pthread_mutex_unlock(&mutex);
}
