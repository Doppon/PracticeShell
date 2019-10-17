#include <stdio.h>
#include <stdlib.h>
#include <limits.h>


int main(int argc, char const *argv[])
{
  if (argv[1] == NULL)
  {
    printf("Error01 Usage: search file_name");
    return 0;
  }
 
  const char* file_name = argv[1];

  FILE *fp;
  int num, blank;
  unsigned long character, word, line;
  char buff[1024];
  unsigned char *pntr, *wp;
 
  if ((fp = fopen(file_name, "r")) == NULL) {
    printf("Error02 Could not open the file.");
    return -1;
  }
 
  blank = 0;
  character = word = line = 0;
  while((num = fread(buff, 1, 1024, fp)) > 0)
  {
    for(wp = buff; num > 0; num--,wp++)
    {
      if(*wp <= ' '){
        if(*wp == '\n')
        {
          line++;
          character++;
        }
        if( !blank )
          word++;

        blank = 1;
        character++;
      }
      else{
        blank = 0;
        character++;
      }
    }
  }

  printf("行数: %lu\n", line);
  printf("文字数(バイト): %lu\n", character);
  printf("単語数: %lu", word);

  return 0;
}
