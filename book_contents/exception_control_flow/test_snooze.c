#include "csapp.h"

void sigint_handler(int sig)
{
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

  if (signal(SIGINT, sigint_handler) == SIG_ERR)
    unix_error("Signal error\n");
  snooze(seconds);

  return 0;
}



