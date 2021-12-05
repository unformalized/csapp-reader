#include "csapp.h"
#include <bits/types/sigset_t.h>

// 显示阻塞信号测试

void sigint_handler(int sig)
{
  printf("Catch SIGINT");
  return;
}

unsigned int snooze(unsigned int secs) {
  unsigned int r = sleep(secs);

  printf("Slept for %d of %d secs", secs - r, secs);
  return r;
}

int main(int argc, char const *argv[])
{
  int seconds = 0;
  sigset_t mask, prev_mask;
  if (argc >= 2) {
    seconds = atoi(argv[1]);
  } else {
    seconds = 5;
  }
  Sigemptyset(&mask);
  // 设置 sigint 信号阻塞
  Sigaddset(&mask, SIGINT);
  Sigprocmask(SIG_BLOCK, &mask, &prev_mask);

  // 注册 sigint 信号处理
  if (signal(SIGINT, sigint_handler) == SIG_ERR)
    unix_error("Signal error\n");
  snooze(seconds);

  Sigprocmask(SIG_SETMASK, &prev_mask, NULL);

  return 0;
}



