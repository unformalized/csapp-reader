#include "sys_call_error_handle.h"
#include <sys/wait.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int main() {
    if (Fork() == 0) {
        printf("a");
        fflush(stdout);
    } else {
        printf("b");
        fflush(stdout);
        waitpid(-1, NULL, 0);
    }
    printf("c");
    fflush(stdout);
    exit(0);
}


// 可能的输出结果, p 代表父进程，s 代表子进程
/**
 * 
 *             -> print a -> print c -> exit
 *             |               -----<----|         
 *             |              |
 *  -> -> Fork -> print b -> wait -> print c
 * 
 *  a b c c
 *  b a c c
 *  a c b c
 */


