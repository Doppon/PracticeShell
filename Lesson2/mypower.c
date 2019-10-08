#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
  int input = atoi(argv[1]);
  printf("入力された数値は: %d \n", input);

  if (input >= 1)
  {
    printf("1以上");
  } else
  {
    printf("1未満");
  }

  return 0;
}
