#include <headers/common.h>
#include <headers/linker.h>

void print_sh_entry(sh_entry_t *sh) {
    debug_printf(DEBUG_LINKER, "%s\t%x\t%d\t%d\n", sh->sh_name, sh->sh_addr,
                 sh->sh_offset, sh->sh_size);
}

void print_symbol_entry(st_entry_t *ste) {
    debug_printf(DEBUG_LINKER, "%s\t%d\t%d\t%s\t%d\t%d\n", ste->st_name,
                 ste->bind, ste->type, ste->st_shndx, ste->st_value,
                 ste->st_size);
}
