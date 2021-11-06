#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[], char *envp[]) {
    printf("Command-line arguments\n");
    int i;
    for (i = 0; i < argc; i++) {
        printf("argv[%d]: %s\n", i, argv[i]);
    }
    i = 0;
    printf("Environment variables\n");
    while (envp[i] != NULL) {
        printf("envp[%d]: %s\n", i, envp[i]);
        i++;
    }

    return 0;
}


