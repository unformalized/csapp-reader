#include "sys_call_error_handle.h"
#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>
#include <stdlib.h>

int main()
{
    int status;
    pid_t pid;

    printf("Hello\n");
    pid = Fork();
    printf("%d\n", !pid);
    if (pid != 0) {
        if (Waitpid(-1, &status, 0) > 0) {
            if (WIFEXITED(status) != 0) {
                printf("%d\n", WEXITSTATUS(status));
            }
        }
    }

    printf("Bye\n");
    exit(2);
}
