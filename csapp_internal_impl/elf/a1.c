#include <stdio.h>
#include <stdlib.h>
static int a = 1;

__attribute__((weak)) int add(int a, int b) { return a + b; }

__attribute__((weak)) int f() { return -1; }

int main() {
    if (f() == -1) {
        printf("f() not found");
        exit(0);
    } else {
    }
}
