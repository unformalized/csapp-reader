#include "csapp.h"

void sigint_handler(int sig)
{
  printf("Caught SIGINT!\n");
  exit(0);
}

int main() {
  if (signal(SIGINT, sigint_handler) == SIG_ERR)
    unix_error("signal error");
  
  // 休眠进程，直到接受一个信号
  pause();

  return 0;
}
