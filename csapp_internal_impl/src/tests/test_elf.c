#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <headers/common.h>
#include <headers/linker.h>

static char *elf_filename = "./files/exe/sum.elf.txt";

int main()
{
    elf_t elf;
    parse_elf(elf_filename, &elf);
    free_elf(&elf);

    return 0;
}
