#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>
#include "sys_call_error_handle.h"

int main() {
    pid_t pid;
    int x = 1;
    printf("before fork\n");

    pid = Fork();
    // child process
    if (pid == 0) {
        printf("child x = %d\n", ++x);
        exit(0);
    }

    printf("parent: x = %d\n", --x);
    exit(0);
}

