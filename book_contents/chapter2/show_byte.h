
#ifndef SHOW_BYTE
#define SHOW_BYTE
#include <stdio.h>

typedef unsigned char *byte_pointer;
typedef unsigned short *_2_byte_pointer;

void show_bytes(byte_pointer start, size_t len);
void show_int(int);
void show_float(float);
void show_pointer(void *);

#endif
