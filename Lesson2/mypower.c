#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
  int x = atoi(argv[1]);
  if (argv[2] != NULL)
  {
    int y = atoi(argv[2]);
  }

  printf("入力された数値は: %d \n", x);

  if (x >= 1)
  {
    printf("1以上");
  } else
  {
    printf("1未満");
  }

  return 0;
}
