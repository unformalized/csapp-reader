#include "csapp.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <asm-generic/errno-base.h>
#include <bits/types/sigset_t.h>
#include <stdlib.h>
#include <sys/types.h>

void deletejob(pid_t pid) {
  Sio_puts("delete job\n");
  fflush(stdout);
};
void addjob(pid_t pid) {
  sio_puts("add job\n");
  fflush(stdout);
};
void initjobs() {
  printf("initJobs\n");
  fflush(stdout);
};

void handler(int sig)
{
  int olderror = errno;
  sigset_t mask_all, prev_mask;
  pid_t pid;
  Sio_puts("signal handler");

  Sigfillset(&mask_all);
  while ((pid = waitpid(-1, NULL, 0)) > 0) {
    Sigprocmask(SIG_BLOCK, &mask_all, &prev_mask);
    deletejob(pid);
    Sigprocmask(SIG_SETMASK, &prev_mask, NULL);
  }

  if (errno == ECHILD)
    Sio_puts("waitpid error");
  errno = olderror;
}

int main(int argc, char **argv)
{
  int pid;
  sigset_t mask_all, mask_one, prev_mask, prev_one;

  Sigfillset(&mask_all);
  Sigemptyset(&mask_one);
  Sigaddset(&mask_one, SIGCHLD);
  Signal(SIGCHLD, handler);
  initjobs();

  // while (1) {
    // 设置屏蔽 SIGCHLD 信号
    Sigprocmask(SIG_BLOCK, &mask_one, &prev_one);
    if ((pid = Fork()) == 0) {
      // child process
      // 子进程会继承父进程的阻塞信号
      // 恢复 SIGCHLD 信号处理
      Sigprocmask(SIG_SETMASK, &prev_one, NULL);
      Sio_puts("child process running\n");
      // Execve("/bin/date", argv, NULL);
      exit(0);
    }
    Sigprocmask(SIG_BLOCK, &mask_all, NULL);
    addjob(pid);
    Sigprocmask(SIG_SETMASK, &prev_one, NULL);
  // }

  return 0;
}


