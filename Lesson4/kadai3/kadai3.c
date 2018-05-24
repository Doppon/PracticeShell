#include <stdio.h>
int main(int argc, char *argv[]){
  FILE *origin_file;
  FILE *copy_file;
  char line[1000];

  origin_file = fopen(argv[1], "r");
  if(origin_file == NULL){
    printf("ファイルが開けませんでした。\n");
    return -1;
  }

  copy_file = fopen(argv[2], "w");
  
  while((fgets(line, sizeof(line), origin_file)) != NULL){
    fprintf(copy_file, "%s", line);
  }
  printf("[コピー完了しました]\n");

  fclose(origin_file);
  fclose(copy_file);
  return 0;
}
