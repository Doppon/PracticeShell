#include <stdio.h>
int main(int argc, char *argv[]){
  FILE *origin_file;
  FILE *copy_file;
  char line[1000];

  if(argc != 1){
    printf("コマンドライン引数にちゃんとファイルを指定してなd(´・ω・｀)\n");
    printf("第一引数：コピー元ファイル名, 第二引数：コピー先ファイル名\n");
    return -1;
  }

  origin_file = fopen(argv[1], "r");
  if(origin_file == NULL){
    printf("%sが開けませんでした。\n", argv[1]);
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
