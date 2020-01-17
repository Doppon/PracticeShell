#include <stdio.h>
#include <ctype.h>

int main(int argc, char **argv){
  int text=0, line=0, word=0, flag=0, str;

  if(argc<=1){ 
    printf("コマンドライン引数がないでござる(´・ω・｀)\n");
    return 0;
  }

  FILE *fp;
  fp=fopen(argv[1],"r");

  if(fp==NULL){
    fprintf(stderr, "ファイルが開けなかったでござる(´・ω・｀)\n");
  }
  
  for(str=fgetc(fp); str!=EOF; str=fgetc(fp)){
    if(isgraph(str)){
      text++;
    }
     
    if(str=='\n'){
      line++; 
    }

    if(isalpha(str)){
      if(flag==0){
        flag=1;
      }
    }

    if(isalpha(str)==0 && flag==1){
      word++;
      flag=0;
    }
  }
  
  printf("文字数%d,行数%d,単語数%d\n", text,line,word);
    
  fclose(fp);
}
