#include "syscall.h"
#include "sys/types.h"
#include <sys/wait.h>
#include "errno.h"
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * Unix 系统级函数遇到错误时，通常会返回 -1，并设置全局整数变量 errno
 */

// 错误处理函数
void unix_error(char *msg)
{
    fprintf(stderr, "%s: %s\n", msg, strerror(errno));
}

// fork 错误处理包装函数
pid_t Fork(void) {
    pid_t pid;

    if ((pid = fork()) < 0)
        unix_error("Fork error");
    return pid;
}

pid_t Waitpid(pid_t pid, int *iptr, int options) {
    pid_t retpid;

    if ((retpid = waitpid(pid, iptr, options)) < 0) {
        printf("error retpid: %d\n", retpid);
        fflush(stdout);
        unix_error("Waitpid error");
    }
    return retpid;
}
