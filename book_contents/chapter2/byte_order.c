#include <stdio.h>
#include "show_byte.h"

void test_show_bytes(int val) {
    int ival = val;
    float fval = (float) ival;
    int *pval = &val;
    show_int(ival);
    show_float(fval);
    show_pointer(pval);
}

void test_small_cast_large() {
    int i = 12345;
    char c = 3;
    char *cp = &c;
    int  *ip = &c;

    printf("address i: %x\n", &i);
    printf("cp: %x, ip: %x\n", cp, ip);
    show_bytes((byte_pointer) &i, 4);
    show_bytes((byte_pointer) ip, 4);
    show_bytes((byte_pointer) cp, 4);
}

void test_small_cast_large_sign() {
    short sx = -12345;
    unsigned short usx = sx;
    int x = sx;
    unsigned ux = usx;
    printf("sx = %d\t", sx);
    printf("usx = %d\t", usx);
    printf("x = %d\t", x);
    printf("ux = %d\n", ux);
    printf("address - sx: %x, usx: %x, sx: %x, ux: %x\n", &sx, &usx, &x, &ux);
    show_bytes((byte_pointer) &sx, sizeof(short));
    show_bytes((byte_pointer) &usx, sizeof(unsigned short));
    show_bytes((byte_pointer) &x, sizeof(int));
    show_bytes((byte_pointer) &ux, sizeof(unsigned));
}

int main() {
    test_small_cast_large();
    test_small_cast_large_sign();
    return 0;
}