#include <stdio.h>
#include "memory/inst.h"
#include "cpu/mmu.h"
#include "cpu/register.h"
#include "memory/dram.h"

static uint64_t decode_od(od_t od)
{
    uint64_t vaddr = od.imm;
    switch (od.type)
    {
    case EMPTY:
        return 0x0;
    case IMM:
        return *((uint64_t *)&od.imm);
    case REG:
        return (uint64_t)od.reg1;
    case MM_IMM:
        vaddr = od.imm;
        break;
    case MM_REG:
        vaddr = *(od.reg1);
        break;
    case MM_IMM_REG:
        vaddr = od.imm + *(od.reg1);
        break;
    case MM_REG1_REG2:
        vaddr = *(od.reg1) + *(od.reg2);
        break;
    case MM_IMM_REG1_REG2:
        vaddr = *(od.reg1) + *(od.reg2) + od.imm;
        break;
    case MM_REG2_S:
        vaddr = (*(od.reg2)) * od.scale;
        break;
    case MM_IMM_REG2_S:
        vaddr = (*(od.reg2)) * od.scale + od.imm;
        break;
    case MM_REG1_REG2_S:
        vaddr = *(od.reg1) + (*(od.reg2)) * od.scale;
        break;
    case MM_IMM_REG1_REG2_S:
        vaddr = *(od.reg1) + (*(od.reg2)) * od.scale + od.imm;
        break;
    }
    return vaddr;
}

void inst_cycle()
{
    inst_t *instr = (inst_t *)reg.rip;

    uint64_t src = decode_od(instr->src);
    uint64_t dst = decode_od(instr->dst);

    handler_t handler = handler_table[instr->op];
    handler(src, dst);
    printf("    %s\n", instr->code);
}

void init_handler_table()
{
    handler_table[ADD_REG_REG] = &add_reg_reg_handler;
    handler_table[MOV_REG_REG] = &mov_reg_reg_handler;
    handler_table[MOV_REG_MEM] = &mov_reg_mem_handler;
    handler_table[MOV_MEM_REG] = &mov_mem_reg_handler;
    handler_table[PUSH_REG] = &push_reg_handler;
    handler_table[POP_REG] = &pop_reg_handler;
    handler_table[CALL] = &call_handler;
    handler_table[RET] = &ret_handler;
}

// 指令函数实现中，src, dst, 寄存器都是地址，想要获取地址上的值，就必须让 C 将 src 看作为地址 (uint64_t *)，再从地址中取出值 *(uint64_t *)src

void add_reg_reg_handler(uint64_t src, uint64_t dst)
{
    *(uint64_t *)dst = *(uint64_t *)dst + *(uint64_t *)src;
    reg.rip = reg.rip + sizeof(inst_t);
}

void mov_reg_reg_handler(uint64_t src, uint64_t dst)
{
    // dst: reg, src: reg
    *(uint64_t *)dst = *(uint64_t *)src;
    reg.rip = reg.rip + sizeof(inst_t);
}

void mov_reg_mem_handler(uint64_t src, uint64_t dst)
{
    // src: reg, dst: memory virtual address
    write64bits_dram(va2pa(dst), *(uint64_t *)src);
    reg.rip = reg.rip + sizeof(inst_t);
}

void mov_mem_reg_handler(uint64_t src, uint64_t dst)
{
    // src: memory virtual address， dst: reg
    *(uint64_t *)dst = read64bits_dram(va2pa(src));
    reg.rip = reg.rip + sizeof(inst_t);
}

/**
 * @brief call instruction impl
 * @1: add rsp
 * @2: restore next inst addres as return address in stack
 *
 * @param src
 * @param dst
 */
void call_handler(uint64_t src, uint64_t dst)
{
    // src: imm address of called function
    reg.rsp = reg.rsp - 8;
    // return address -> rsp memory
    write64bits_dram(va2pa(reg.rsp), reg.rip + sizeof(inst_t));
    // rip -> call address
    reg.rip = src;
}

void push_reg_handler(uint64_t src, uint64_t dst)
{
    // src: reg, dst: empty
    reg.rsp = reg.rsp - 0x8;
    write64bits_dram(va2pa(reg.rsp), *(uint64_t *)src);
    reg.rip = reg.rip + sizeof(inst_t);
}

void pop_reg_handler(uint64_t src, uint64_t dst)
{
    // src: reg,
    *(uint64_t *)src = read64bits_dram(va2pa(reg.rsp));
    reg.rsp += 0x8;
    reg.rip += sizeof(inst_t);
}

void ret_handler(uint64_t src, uint64_t dst)
{
    uint64_t ret_addr = read64bits_dram(va2pa(reg.rsp));
    reg.rsp += 0x8;
    reg.rip = ret_addr;
}
