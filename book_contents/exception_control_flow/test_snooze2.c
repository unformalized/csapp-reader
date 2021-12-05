#include "csapp.h"
#include <sys/types.h>
#include <unistd.h>

void sigint_handler(int sig)
{
  pid_t pid = getpid();
  printf("current process id: %d\n", pid);
  printf("Catch SIGINT");
  /* wait the SIGTERM signal  */
  return;
}

void sigterm_handler(int sig) {
  printf("Catch SIGTERM");
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
  if (argc >= 2) {
    seconds = atoi(argv[1]);
  }
  pid_t pid = getpid();
  printf("current process id: %d\n", pid);

  if (signal(SIGINT, sigint_handler) == SIG_ERR)
    unix_error("Signal error\n");
  if (signal(SIGTERM, sigterm_handler) == SIG_ERR)
    unix_error("Signal error\n");
  snooze(seconds);

  return 0;
}
