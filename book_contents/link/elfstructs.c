typedef struct {
    int name; /* String table offset */
    char type:4, /* Function or Data (4 bits)  */
        binding:4; /* Local or global (4 bits) */
    char reversed; /* Unused */
    short section; /* Section head index  */
    long value; /* Section offer or absolute address  */
    long size; /* Object size in bytes */
} Elf64_Symbol;

typedef struct {
    long offset; // Offset of reference to the relocate
    long type:32, // Relocation type
         symbol: 32; // Symbol table index
    long addend; // Constant part of relocation expression
} Elf64_Rela ;

