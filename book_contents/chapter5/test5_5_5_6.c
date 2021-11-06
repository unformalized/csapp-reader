#include <stdio.h>
#include <time.h>

#define SIZE 100000

double poly(double a[], double x, long degree) {
    long i;
    double result = a[0];
    double xwpr = x;

    for (i = 0; i <= degree; i++)
    {
        result += a[i] * xwpr;
        xwpr = x * xwpr;
    }
    
    return result;
}

double polyh(double a[], double x, long degree) {
    long i;
    double result = a[degree];
    for (i = degree - 1; i >= 0; i--)
    {
        result = a[i] + result * x;
    }

    return result;
}


int main() {
    double arr[SIZE] = {};

    for (int i = 0; i < SIZE; i++)
    {
        arr[i] = 1.0;
    }
    
    clock_t t1,t2,t3,t4;

    t1 = clock();
    double r1 = poly(arr, 1.0, SIZE);
    t2 = clock();
    double r2 = polyh(arr, 1.0, SIZE);
    t3 = clock();

    // 在 O0 优化程度下
    printf("poly run result: %f, spend time: %d\n", r1, t2 - t1); // 258
    printf("polyh run result: %f, spend time: %d\n", r2, t3 - t2); // 327

    return 0;
}



