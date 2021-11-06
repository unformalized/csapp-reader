#include "sys_call_error_handle.h"
#include <sys/wait.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#define N 2

int main() {
    int status, i;
    pid_t pid;

    for (i = 0; i < N; i++)
        if ((pid = Fork()) == 0)
            exit(100+i);

    while ((pid = Waitpid(-1, &status, 0)) > 0) {
        if (WIFEXITED(status))
            printf("child %d terminated normally with exit status = %d\n", pid, WEXITSTATUS(status));
        else
            printf("child %d terminated abnormally\n", pid);
    }

    if (errno != ECHILD)
        unix_error("waitpid error");
    exit(0);
}

