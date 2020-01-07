#include <stdio.h>

extern char **environ;
int data0;
int data1 = 10;

int main(int argc, char *argv[]){
  char c;
  printf("environ : %0.8p\n", environ);
  printf("argv : %0.8p\n", argv);
  printf("stack : %0.8p\n", &c);
  printf("bss : %0.8p\n", &data0);
  printf("data : %0.8p\n", &data1);

  return 0;
}
