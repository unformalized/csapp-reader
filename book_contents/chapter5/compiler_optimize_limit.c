#include <stdio.h>


/**
 * 编译器优化的局限性
 * 
 */

void twiddle1(long *xp, long *yp) {
    *xp += *yp;
    *xp += *yp;
}

void twddle2(long *xp, long *yp) {
    *xp += 2 * *yp;
}

void swap(long *xp, long *yp) {
    *xp = *xp + *yp;
    *yp = *xp - *yp;
    *xp = *xp - *yp;
}


int main() {
    long x = 10;

    swap(&x, &x);

    printf("x = %d\n", x);

    return 0;
}