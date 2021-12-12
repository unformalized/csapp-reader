#include "csapp.h"
#include <asm-generic/errno-base.h>

void handler1(int sig)
{
  int olderror = errno;

  if ((waitpid(-1, NULL, 0)) < 0)
    sio_error("waitpid error");
  Sio_puts("Handle reaped child\n");
  Sleep(1);
  errno = olderror;
}

void handler2(int sig)
{
  int olderror = errno;

  while (waitpid(-1, NULL, 0) > 0) {
    Sio_puts("Handler reaped child\n");
  }
  if (errno != ECHILD)
    sio_error("waitpid error");
  Sleep(1);
  errno = olderror;
}

int main()
{
  int i,n;
  char buf[MAXBUF];

  if (signal(SIGCHLD, handler2) == SIG_ERR)
    unix_error("signal error");

  /* Parent create childrens  */
  for (i = 0; i < 3; i++) {
    if (Fork() == 0) {
      printf("hello from child %d\n", (int)(getpid()));
      exit(0);
    }
  }

  /* Parent waits for terminal input and then processes it */
  if ((n = read(STDIN_FILENO, buf, sizeof(buf))) < 0)
    unix_error("read");

  printf("Parent processint input\n");
  while (1)
    ;

  exit(0);
}
