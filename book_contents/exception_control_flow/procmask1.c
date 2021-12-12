#include "csapp.h"
#include <asm-generic/errno-base.h>
#include <bits/types/sigset_t.h>
#include <sys/types.h>

void deletejob(pid_t);
void addjob(pid_t);
void initjobs();

void handler(int sig)
{
  int olderror = errno;
  sigset_t mask_all, prev_mask;
  pid_t pid;

  Sigfillset(&mask_all);
  while ((pid = waitpid(-1, NULL, 0)) > 0) {
    Sigprocmask(SIG_BLOCK, &mask_all, &prev_mask);
    deletejob(pid);
    Sigprocmask(SIG_SETMASK, &prev_mask, NULL);
  }

  if (errno != ECHILD)
    Sio_puts("waitpid error");
  errno = olderror;
}

int main(int argc, char **argv)
{
  int pid;
  sigset_t mask_all, prev_mask;

  Sigfillset(&mask_all);
  Signal(SIGCHLD, handler);
  
  initjobs();

  while (1) {
    /* Child process */
    // 并不清楚，父进程创建一个子进程后，后续的执行情况
    if ((pid = Fork()) == 0) {
      // 若是子进程立即执行完 /bin/data 传递子进程结束消息被程序捕获，deletejob 后再返回父进程，会导致错误
      Execve("/bin/date", argv, NULL);
    }
    // 存在错误，有可能 deletejob 在 addjob 之前执行
    Sigprocmask(SIG_BLOCK, &mask_all, &prev_mask);
    addjob(pid);
    Sigprocmask(SIG_SETMASK, &prev_mask, NULL);
  }

  return 0;
}


