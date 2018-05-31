#include <stdio.h>   /* printf, stderr, fprintf */
#include <sys/types.h> /* pid_t */
#include <unistd.h>  /* _exit, fork */
#include <stdlib.h>  /* exit */
#include <errno.h>   /* errno */

int main(void){
   pid_t  pid;

   pid = fork();
   if (pid == -1){
      fprintf(stderr, "can't fork, error %d\n", errno);
      exit(EXIT_FAILURE);
   }

   if (pid == 0){
      int j;
      for (j = 0; j <= 100; j++){
         printf("child: %d\n", j);
      }
      _exit(0);
   }
   
   return 0;
}
