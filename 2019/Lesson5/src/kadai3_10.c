#include <stdio.h>     /* printf, stderr, fprintf */
#include <sys/types.h> /* pid_t */
#include <unistd.h>    /* _exit, fork, getpid */
#include <stdlib.h>    /* exit */
#include <errno.h>     /* errno */

int main(void){
   pid_t  pid;

   pid = fork();
   if (pid == -1){
      fprintf(stderr, "can't fork, error %d\n", errno);
      // Define EXIT_FAILURE 1 for stdlib.h
      exit(EXIT_FAILURE);
   }

   if (pid == 0){
      int j;
      for (j = 0; j <= 10; j++){
         printf("child: %d\n", j);
      }
      _exit(0);
   }
   
   return 0;
}

