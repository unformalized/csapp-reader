#include "inst.h"
#include "cpu/mmu.h"

static uint64_t decode_od(od_t od)
{
    uint64_t vaddr;
    switch (od.type) {
        case IMM:
            return od.imm;
        case REG:
            return (uint64_t) od.reg1;
        // mm calc
        case MM_IMM:
            vaddr = od.imm;
        case MM_REG:
            vaddr = *(od.reg1);
        case MM_IMM_REG:
            vaddr = od.imm + *(od.reg1);
        case MM_REG1_REG2:
            vaddr = *(od.reg1) + *(od.reg2);
        case MM_IMM_REG1_REG2:
            vaddr = *(od.reg1) + *(od.reg2) + od.imm;
        case MM_REG2_S:
            vaddr = (*(od.reg2)) * od.scale;
        case MM_IMM_REG2_S:
            vaddr = (*(od.reg2)) * od.scale + od.imm;
        case MM_REG1_REG2_S:
            vaddr = *(od.reg1) + (*(od.reg2)) * od.scale;
        case MM_IMM_REG1_REG2_S:
            vaddr = *(od.reg1) + (*(od.reg2)) * od.scale + od.imm;
    }
    return va2pa(vaddr);
}

void inst_cycle()
{
    inst_t *instr = (inst_t *) reg.rip;

    uint64_t src = decode_od(instr->src);
    uint64_t dst = decode_od(instr->dst);


}

