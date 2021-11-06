#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>
#include "sys_call_error_handle.h"

int main() {
    Fork();
    Fork();
    printf("hello\n");
    exit(0);
}

