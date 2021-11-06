#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>
#include "sys_call_error_handle.h"

int main() {
    int x = 1;
    if (Fork() == 0)
        printf("p1: x=%d\n", ++x);
    printf("p2: x=%d\n", --x);
    exit(0);
}
