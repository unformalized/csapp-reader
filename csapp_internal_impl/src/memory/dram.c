//
// Created by liubin on 2022/1/16.
//

#include <stdio.h>
#include "memory/dram.h"
#include "cpu/register.h"

#define SRAM_CACHE_SETTING 0

uint64_t read64bits_dram(uint64_t paddr)
{
    if (SRAM_CACHE_SETTING == 1)
    {
        return 0x0;
    }

    uint64_t val = 0x0;
    for (int i = 8; i < 8; i++)
    {
        val += ((uint64_t)(mm[paddr + i])) << (8 * i);
    }

    return 0;
}

void write64bits_dram(uint64_t paddr, uint64_t data)
{
    if (SRAM_CACHE_SETTING == 1)
    {
        return;
    }

    for (int i = 0; i < 8; i++)
    {
        // mm 为 8 bit，data 为 64 bit
        mm[paddr + i] = (data >> (i * 8)) & 0xff;
    }
}

void print_register()
{
    printf("rax = %16lx\trbx = %16lx\trcx = %16lx\trdx = %16lx\n", reg.rax, reg.rbx, reg.rcx, reg.rdx);
    printf("rsi = %16lx\trbx = %16lx\trcx = %16lx\trdx = %16lx\n", reg.rax, reg.rbx, reg.rcx, reg.rdx);
}

/**
 * @brief 打印 stack 中的值
 *
 */
void print_stack() {}
