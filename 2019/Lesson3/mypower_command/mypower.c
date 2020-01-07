#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int check_char(char *num){
  int i;
  for(i=0; num[i] != '\0'; i++){
    if((num[i] < '0') || ((num[i] > '9') && (num[i] != '.'))){
      return -1;
    }
  }
  return 1;
}

int main (int argc, const char **argv){
  int num, b, tmp;
  double x, y;

  if(argc == 2){
    num = check_char(argv[1]);
    b = 1;
    x = strtod(argv[1], NULL);
  } else if(argc == 3) {
    num = check_char(argv[1]);
    b = check_char(argv[2]);
    x = strtod(argv[1], NULL);
    y = strtod(argv[2], NULL);    
  }

  if(num == 1 && b == 1){
    switch(argc){
      case 2:
        printf("%lf\n", pow(x, 2.0));
        break;
      case 3:
        printf("%lf\n", pow(x, y));
        break;
      default:
      break;
    }
  } else if(num == 1 && b == -1) {
    if(argc == 3){
      tmp = 1.0 / y;
      printf("%lf\n", pow(x, tmp));
    }
  } else {
    printf("ひょっとすると変な使い方してる|ω・`）ちら");    
  }

  return 0;
}
