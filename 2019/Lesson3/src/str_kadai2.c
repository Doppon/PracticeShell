#include <stdio.h>
#include <ctype.h>

int main()
{
  int c;

  // getchar() | get only one character.
  while ((c = getchar()) != EOF) {
    if (islower(c))
    {
      c = toupper(c);
    } 
    else if (isupper(c))
    {
      c = tolower(c);
    }
    putchar(c);
  }
}