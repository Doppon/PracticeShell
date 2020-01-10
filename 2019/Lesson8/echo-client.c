#include <stdio.h>
#include <sys/types.h>   /* socket() */
#include <sys/socket.h>  /* socket() */
#include <netinet/in.h>  /* struct sockaddr_in */
#include <netdb.h>       /* getaddrinfo() */
#include <stdlib.h>      /* exit() */
#include <string.h>      /* memset */

extern int echo_client (char *server, int portno);
extern int fdopen_sock (int sock, FILE **inp, FILE **outp);

int main (int argc, char *argv[])
{
  char *server;
  int portno;
  if (argc != 3) {
    fprintf(stdout, "Usage: %s host port.\n", argv[0]);
    exit(-1);
  }
  server = argv[1];
  printf("server %s\n", server);
  portno = strtol(argv[2], 0, 10);
  printf("portno %d\n", portno);
  echo_client(server, portno);
}

#define BUFFERSIZE 1024

int echo_client(char *server, int portno)
{
  int sock;
  char sbuf[BUFFERSIZE];
  char rbuf[BUFFERSIZE];
  FILE *in, *out;
  
  sock = tcp_connect (server, portno);
  if (sock < 0) {
    exit (-1);
  }
  
  if (fdopen_sock(sock, &in, &out) < 0) {
    fprintf(stderr, "fdopen()\n");
    exit(1);
  }
  printf("==> ");
  fflush(stdout);
  
  /* gets buffer */
  while (fgets(sbuf, BUFFERSIZE, stdin)) {
    fprintf(stdout, "sending: [%s]\n", sbuf );
    fprintf(out, "%s", sbuf);
    fgets(rbuf, BUFFERSIZE, in);
    printf("received: [%s]\n", rbuf);
    printf("==> ");
    fflush(stdout);
  }
  printf("\n");
  fclose(in);
  fclose(out);
}

int tcp_connect (char *server, int portno)
{
  struct addrinfo hints, *ai;
  struct sockaddr_in addr; /* sockaddr_storage */
  
  int s;
  int err;
  
  if (( s = socket (PF_INET, SOCK_STREAM, 0)) < 0) {
    perror("socket");
    return (-1);
  }
  printf("socket() called\n");
  
  memset(&hints, 0, sizeof(hints));
  hints.ai_family = AF_INET;
  hints.ai_socktype = SOCK_STREAM;
  
  if ((err = getaddrinfo(server, NULL, &hints, &ai))) {
    fprintf(stderr, "sockaddr too large (%d) > (%d)\n",
            ai->ai_addrlen, sizeof(addr));
    
    freeaddrinfo(ai);
    close(s);
    return(-1);
  }
  printf("getaddrinfo() called\n");
  
  memcpy (&addr, ai->ai_addr, ai->ai_addrlen);
  addr.sin_port = htons(portno);
  freeaddrinfo(ai);
  
  printf("freeaddrinfo() called\n");
  
  if (connect(s, (struct sockaddr *)&addr, sizeof(addr)) < 0) {
    perror(server);
    close(s);
    return (-1);
  }
  
  printf("connect() called\n");
  return(s);
}

int fdopen_sock(int sock, FILE **inp, FILE **outp)
{
  int sock2;
  if ((sock2 = dup(sock)) < 0)
  return (-1);
  printf("dup() called\n");
  
  if ((*inp = fdopen(sock2, "r")) == NULL) {
    close (sock2);
    return (-1);
  }
  printf("fdopen() called\n");
  
  if ((*outp = fdopen(sock, "w")) == NULL) {
    fclose (*inp);
    *inp = 0;
    return (-1);
  }
  
  setvbuf(*outp, (char *) NULL, _IOLBF, 0);
  return(0);
}


