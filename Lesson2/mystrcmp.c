#include <stdio.h>
#include <stdlib.h>

int LengthOf(const char *s)
{
  int n = 0;

  while (*s++ != '\0')
    n++;
  return (n);
}

int main(int argc, char const *argv[])
{
  if (argv[1] == NULL)
  {
    printf("Error01 Usage: strcmp str str");
    return 0;
  }

  if (argv[2] == NULL)
  {
    printf("Error02 Usage: strcmp str str");
    return 0;
  }

  return 0;
}
