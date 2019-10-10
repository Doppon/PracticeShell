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

  const char* word1 = argv[1];
  const char* word2 = argv[2];

  if (LengthOf(word1) == LengthOf(word2))
  {
    printf("0");
    return 0;
  }

  return 0;
}
