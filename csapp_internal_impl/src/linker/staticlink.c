//
// Created by liubin on 22-8-7.
//

#include "headers/common.h"
#include "headers/linker.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SYMBOL_MAP_LENGTH 64

// internal mapping between source and destination symbol entries
typedef struct {
    elf_t *elf;
    st_entry_t *src;
    st_entry_t *dst;
} smap_t;

static void symbol_process(elf_t **srcs, int num_srcs, elf_t *dst,
                           smap_t *smap_table, int *smap_count);
static void simple_resolution(st_entry_t *sym, elf_t *sym_elf,
                              smap_t *candidate);
static int symbol_precedence(st_entry_t *sym);

void link_elf(elf_t **srcs, int num_srcs, elf_t *dst) {
    // reset dst memory
    memset(dst, 0, sizeof(elf_t));

    int smap_count = 0;
    smap_t smap_table[MAX_SYMBOL_MAP_LENGTH];

    // update smap_table - symbol processing
    symbol_process(srcs, num_srcs, dst, (smap_t *)&smap_table, &smap_count);

    printf("--------------------\n");

    for (int i = 0; i < smap_count; ++i) {
        st_entry_t *ste = smap_table[i].src;
        print_symbol_entry(ste);
    }
}

static void symbol_process(elf_t **srcs, int num_srcs, elf_t *dst,
                           smap_t *smap_table, int *smap_count) {

    // 遍历 ELF 文件
    for (int i = 0; i < num_srcs; ++i) {
        elf_t *elfp = srcs[i];

        // 遍历符号表
        for (int j = 0; j < elfp->symt_count; ++j) {
            st_entry_t *sym = &(elfp->symt[j]);

            if (sym->bind == STB_LOCAL) {
                assert(*smap_count < MAX_SYMBOL_MAP_LENGTH);
                smap_table[*smap_count].src = sym;
                smap_table[*smap_count].elf = elfp;
                // dst 现在还没有值，之后再处理
                (*smap_count)++;
            } else if (sym->bind == STB_GLOBAL) {
                for (int k = 0; k < *smap_count; ++k) {
                    st_entry_t *candidate = smap_table[k].src;
                    if (candidate->bind == STB_GLOBAL &&
                        strcmp(candidate->st_name, sym->st_name) == 0) {
                        simple_resolution(sym, elfp, &smap_table[k]);
                        // 符号解析之后，直接进行下一个符号处理
                        goto NEXT_SYMBOL_PROCESS;
                    }
                }

                assert(*smap_count < MAX_SYMBOL_MAP_LENGTH);
                smap_table[*smap_count].src = sym;
                smap_table[*smap_count].elf = elfp;
                (*smap_count)++;
            }

        NEXT_SYMBOL_PROCESS:;
        }
    }

    // check if there is any undefined symbol in the map table

    for (int i = 0; i < *smap_count; ++i) {
        st_entry_t *s = smap_table[i].src;
        assert(strcmp(s->st_shndx, "SHN_UNDEF") != 0);
        assert(s->type != STT_NOTYPE);

        // the remaining COMMON go to .bss
        if (strcmp(s->st_shndx, "COMMON") == 0) {
            char *bss = ".bss";
            for (int j = 0; j < MAX_CHAR_SECTION_NAME; ++j) {
                if (j < 4) {
                    s->st_shndx[j] = bss[j];
                } else {
                    s->st_shndx[j] = '\0';
                }
            }

            // .bss value
            s->st_value = 0;
        }
    }
}

static void simple_resolution(st_entry_t *sym, elf_t *sym_elf,
                              smap_t *candidate) {
    // sym: symbol from current elf file
    // candidate: pointer to the internal map table slot: src -> dst

    int pre1 = symbol_precedence(sym);
    int pre2 = symbol_precedence(candidate->src);

    // rule1: don't exit multiple strong symbol with same name
    if (pre1 == 2 && pre2 == 2) {
        debug_printf(DEBUG_LINKER,
                     "symbol resolution: strong symbol \"%s\" is redeclared\n",
                     sym->st_name);
        exit(0);
    }

    // rule3: both weak symbol, use the stronger one as the best match
    if (pre1 != 2 && pre2 != 2) {
        if (pre1 > pre2) {
            candidate->src = sym;
            candidate->elf = sym_elf;
        }
        return;
    }

    // rule2: current symbol is strong symbol, update candidate src & elf
    // pointer
    if (pre1 == 2) {
        candidate->src = sym;
        candidate->elf = sym_elf;
    }
}

static inline int symbol_precedence(st_entry_t *sym) {
    /*
     * don't consider weak, it's rare, local don't conflict
     * bind    type     shndx              precedence
     * global  notype   undef              0
     * global  object   common             1 - tentative
     * global  object   data,bss,rodata    2 - defined
     * global  func     text               2 - defined
     */

    assert(sym->bind == STB_GLOBAL);
    if (strcmp(sym->st_shndx, "SHN_UNDEF") == 0 && sym->type == STT_NOTYPE) {
        return 0;
    }

    if (strcmp(sym->st_shndx, "COMMON") == 0 && sym->type == STT_OBJECT) {
        return 1;
    }

    if ((strcmp(sym->st_shndx, ".text") == 0 && sym->type == STT_FUNC) ||
        (strcmp(sym->st_shndx, ".data") == 0 && sym->type == STT_OBJECT) ||
        (strcmp(sym->st_shndx, ".bss") == 0 && sym->type == STT_OBJECT) ||
        (strcmp(sym->st_shndx, ".rodata") == 0 && sym->type == STT_OBJECT)) {
        return 2;
    }

    debug_printf(
        DEBUG_LINKER,
        "symbol resolution: cannot determine the symbol \"%s\" precedence",
        sym->st_name);
    exit(0);
}
