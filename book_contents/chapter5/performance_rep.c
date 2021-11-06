#include <stdio.h>
#include <time.h>
#include <stdlib.h>


void psum1(float a[], float p[], long n) {
    long i;
    float prev = a[0];
    p[0] = prev;
    for (i = 1; i < n; i++) {
        prev = prev + a[i];
        p[i] = prev;
    }
}


void psum2(float a[], float p[], long n) {
    long i;
    p[0] = a[0];

    for (i = 1; i < n - 1; i += 2) {
        float mid_val = p[i-1] + a[i];
        p[i] = mid_val;
        p[i+1] = mid_val + a[i+1];
    }

    if (i < n) {
        p[i] = p[i-1] + a[i];
    }
}


float* genFArr(int n) {
    float* arr = malloc(n * sizeof(float));
    for (int i = 0; i < n; i++) {
        arr[i] = (float) i;
    }
    
    return arr;
}

int main() {
    clock_t t1,t2,t3;

    int per[10] = {2000,4000,10000,50000,100000,500000,1000000,2000000,5000000,10000000};
    int n = 10;
    int i = 0;
    int j = 0;
    int *arr;
    float *source;
    float *target;

    for (i = 0; i < n; i++)
    {
        int per_num = per[i];
        source = genFArr(per_num);
        target = malloc(per_num * sizeof(float));

        t1 = clock();
        psum1(source, target, per_num);
        t2 = clock();
        psum2(source, target, per_num);
        t3 = clock();

        printf("per_num = %d, psum1 spend time: %d, psum2 spend time: %d\n", per_num, t2 - t1, t3 - t2);
    }
    
    return 0;
}

