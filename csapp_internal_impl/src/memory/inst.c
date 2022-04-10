#include "inst.h"
#include "cpu/mmu.h"
#include "cpu/register.h"

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
    return va2pa(vaddr);
}

void inst_cycle()
{
    inst_t *instr = (inst_t *)reg.rip;

    uint64_t src = decode_od(instr->src);
    uint64_t dst = decode_od(instr->dst);

    handler_t handler = handler_table[instr->op];
    handler(src, dst);
}

void init_handler_table()
{
    handler_table[ADD_REG_REG] = &add_reg_reg_handler;
    handler_table[MOV_REG_REG] = &move_reg_reg_handler;
}

void add_reg_reg_handler(uint64_t src, uint64_t dst)
{
    *(uint64_t *)dst = *(uint64_t *)src;
    reg.rip = reg.rip + sizeof(inst_t);
}

void move_reg_reg_handler(uint64_t src, uint64_t dst)
{
    *(uint64_t *)dst = *(uint64_t *)dst + *(uint64_t *)src;
    reg.rip = reg.rip + sizeof(inst_t);
}
