#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, char const *argv[])
{
  double x = atof(argv[1]);
  double y = 2.0;

  if (argv[2] != NULL)
  {
    y = atof(argv[2]);
  }

  if (y >= 1)
  {
    printf("1以上 \n");
    printf("ルートは%lf \n", pow(x, y));
  } else
  {
    printf("1未満 \n");
    printf("ルートは%lf \n", pow(x, y));
  }

  return 0;
}
