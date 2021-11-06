#include <stdio.h>

// 最小负数转换为正数
void tmin_2_integer() {
    int v = 1 << 31;
    int iv = -v; // 结果不变
    printf("v = %d, iv = %d\n", v, iv);
}

int main() {
    short int v = -12345;
    unsigned short uv = (unsigned short) v;
    printf("v = %d, uv = %u\n", v, uv);

    tmin_2_integer();
    return 0;
}
