#include "csapp.h"
#include <bits/types/sigset_t.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>

volatile sig_atomic_t pid;

void sigchld_handler(int s)
{
  int olderror = errno;
  pid = waitpid(-1, NULL, 0);
  errno = olderror;
}

void sigint_handler(int s) {}

int main(int argc, char **argv)
{
  sigset_t mask, prev;

  Signal(SIGCHLD, sigchld_handler);
  Signal(SIGINT, sigint_handler);
  Sigemptyset(&mask);
  Sigaddset(&mask, SIGCHLD);

  while (1) {
    // 屏蔽子进程结束
    Sigprocmask(SIG_BLOCK, &mask, &prev);
    if (Fork() == 0)
      exit(0);

    pid = 0;
    Sigprocmask(SIG_SETMASK, &prev, NULL);

    // wait for SIGCHLD to be received
    while (!pid)
      // pause(); 当若是在 while 之后和 pause 之前接受到 SIGCHLD 则不能正常结束
      // sleep(1); 太耗时间
      ; // 使用 sigsuspend
    printf(".");
  }

  exit(0);
}


