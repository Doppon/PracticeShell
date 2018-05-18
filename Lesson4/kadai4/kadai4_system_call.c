#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>

int main(){
  char c;
  int src, dst;
  int count;

  src = open("src.txt", O_RDONLY);
  if(src < 0){
    perror("src");
    close(src);
    exit(1);
  }

  dst = open("dst.txt", O_WRONLY | O_CREAT | O_TRUNC, 0666);
  if(dst < 0){
    perror("dst");
    close(dst);
    exit(1);
  }

  while((count = read(src, &c, 1)) > 0){
    if(write(dst, &c, count) < 0){
      perror("write");
      exit(1);
    }
  }

  if(count < 0){
    perror("read");
    exit(1);
  }

  close(src);
  close(dst);
}

