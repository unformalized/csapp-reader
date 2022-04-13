// Dynamic Random Access Memory
#include <headers/cpu.h>
#include <headers/memory.h>
#include <headers/common.h>

/*
Be careful with the x86-64 little endian integer encoding
e.g. write 0x00007fd357a02ae0 to cache, the memory lapping should be:
    e0 2a a0 57 d3 7f 00 00
*/

// memory accessing used in instructions
uint64_t read64bits_dram(uint64_t paddr, core_t *cr)
{
    if (DEBUG_ENABLE_SRAM_CACHE == 1)
    {
        // try to load uint64_t from SRAM cache
        // little-endian
    }
    else
    {
        // read from DRAM directly
        // little-endian
        uint64_t val = 0x0;

        for (int i = 0; i < 8; i++)
        {
            val += (((uint64_t)pm[paddr + i]) << (8 * i));
        }

        return val;
    }
}

void write64bits_dram(uint64_t paddr, uint64_t data, core_t *cr)
{
    if (DEBUG_ENABLE_SRAM_CACHE == 1)
    {
        // try to write uint64_t to SRAM cache
        // little-endian
    }
    else
    {
        // write to DRAM directly
        // little-endian
        for (int i = 0; i < 8; i++)
        {
            /* code */
            pm[paddr + i] = (data >> (i * 8)) & 0xff;
        }
    }
}
