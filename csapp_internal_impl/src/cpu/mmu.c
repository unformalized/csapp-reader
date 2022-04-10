//
// Created by liubin on 2022/1/16.
//

#include "cpu/mmu.h"
#include "memory/dram.h"

uint64_t va2pa(uint64_t vaddr)
{
    return vaddr % MM_LEN;
}
