#include <sys/types.h>

pid_t Fork(void);
void unix_error(char *);
pid_t Waitpid(pid_t,int *,int);
