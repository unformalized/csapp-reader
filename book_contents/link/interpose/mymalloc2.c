#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <dlfcn.h>

void *malloc(size_t size) {
    void *(*mallocp)(size_t size);
    char *error;

    // get address of libc malloc
    mallocp = dlsym(RTLD_NEXT, "malloc");
    if ((error = dlerror()) != NULL) {
        fputs(error, stderr);
        exit(1);
    }
    // call libc malloc
    char *ptr = mallocp(size);
    printf("malloc(%d) = %p\n", size, ptr);
    return ptr;
}

// free wrapper functions
void free(void* ptr) {
    void (*freep)(void *) = NULL;
    char *error;

    if (!ptr) {
        return;
    }

    freep = dlsym(RTLD_NEXT, "free");
    if ((error = dlerror()) != NULL) {
        fputs(error, stderr);
        exit(1);
    }

    freep(ptr);
    printf("free(%p)\n", ptr);
}