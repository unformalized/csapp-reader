#define MAXELEMS 1000

long data[MAXELEMS];

int test(int elems, int stride) {
    long i, sx2 = stride * 2, sx3 = stride * 3, sx4 = stride * 4;
    long acc0 = 0, acc1 = 0, acc2 = 0, acc3 = 0;
    long length = elems;
    long limit = length - sx4;

    for (i = 0; i < limit; i += sx4) {
        acc0 = acc0 + data[i];
        acc1 = acc1 + data[i+1];
        acc2 = acc2 + data[i+2];
        acc3 = acc3 + data[i+3];
    }

    for (; i < length;  i += stride) {
        acc0 = acc0 + data[i];
    }

    return ((acc0 + acc1) + (acc2 + acc3));
}

double run(int size, int stride, double Mhz) {
    double cycles;
    int elems = size / sizeof(int);
    test(elems, stride);

    cycles = fcyc2(test, elems, stride, 0);
    return (size / stride) / (cycles / Mhz);
}

