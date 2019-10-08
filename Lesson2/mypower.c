#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
  int x = atoi(argv[1]);
  int y = 2;

  if (argv[2] != NULL)
  {
    y = atoi(argv[2]);
  }

  printf("入力された数値は: %d \n", x);

  if (y >= 1)
  {
    printf("1以上");
  } else
  {
    printf("1未満");
  }

  return 0;
}
