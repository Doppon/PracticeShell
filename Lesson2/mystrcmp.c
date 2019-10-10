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
    printf("Usage: strcmp str str");
    return 0;
  }

  return 0;
}
