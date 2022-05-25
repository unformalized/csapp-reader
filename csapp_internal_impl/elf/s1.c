#include <stdio.h>
#include <stdlib.h>

// stb_local
static int a = 1;

// stb_weak
__attribute__((weak)) int add(int a, int b)
{
    return a + b;
}

__attribute__((weak)) int f()
{
    return -1;
}

// global notype undef
extern void f1();
extern int a1;

int main()
{
    f1();
    a1 = 2;
    if (f() == -1)
    {
        printf("f not defined\n");
        exit(0);
    }
    else
    {
        printf("f is defined\n");
    }
}
