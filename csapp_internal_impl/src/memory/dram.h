//
// Created by liubin on 2022/1/16.
//

#ifndef CSAPP_INTERNAL_IMPL_DRAM_H
#define CSAPP_INTERNAL_IMPL_DRAM_H

#include <stdint.h>

#define MM_LEN 1000

uint8_t mm[MM_LEN];

uint64_t read64bits_dram(uint64_t paddr);
void write64bits_dram(uint64_t paddr, uint64_t data);

#endif // CSAPP_INTERNAL_IMPL_DRAM_H
