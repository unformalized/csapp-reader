#include <stdio.h>

void f(void);

int x;
int y = 1;

int main() {
    x = 12345;
    f();
    printf("x = %d\n", x);
    printf("y = %d\b", y);
    return 0;
}



