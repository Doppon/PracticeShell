#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

long long int getFileSize(const char* fileName)
{
  FILE* fp = fopen(fileName, "rb");
  if (fp == NULL) {
    return -1LL;
  }

  if (fseek(fp, 0L, SEEK_END) == 0) {
    fpos_t pos;

    if (fgetpos(fp, &pos) == 0) {
      fclose(fp);
      return (long long int)pos;
    }
  }

  fclose(fp);
  return -1LL;
}

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
    printf("Error01 Usage: search file_name");
    return 0;
  }
 
  const char* file_name = argv[1];

  long long int file_size = getFileSize(file_name);
  printf("文字数(バイト): %lld\n", file_size);

  return 0;
}
