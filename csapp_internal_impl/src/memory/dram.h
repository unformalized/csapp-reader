#include <stdint.h>

#ifndef DRAM_H
#define DRAM_H

#define MM_LEN 1000

uint8_t mm[MM_LEN];

uint64_t read64bits_dram(uint64_t paddr);
void write64bits_dram(uint64_t paddr, uint64_t data);
void print_stack();
void print_register();

#endif
