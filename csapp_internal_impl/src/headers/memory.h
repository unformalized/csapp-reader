#include <stdint.h>
#include <headers/cpu.h>

#ifndef MEMORY
#define MEMORY

/**
 * physical memory space is decided by the physical address
 * in this simulator, there are 16 (4 + 6 + 6) bit physical address
 * then the physical space is (1 << 16) = 65536
 * total 16 physical memory
 */

#define PHYSICAL_MEMORY_SPACE 65536
#define MAX_INDEX_PHYSICAL_PAGE 15

// physical memory
// 16 physical memory pages
uint8_t pm[PHYSICAL_MEMORY_SPACE];

/**
 * memory read/write
 */

uint64_t read64bits_dram(uint64_t paddr, core_t *cr);
void write64bits_dram(uint64_t paddr, uint64_t data, core_t *cr);

#endif
