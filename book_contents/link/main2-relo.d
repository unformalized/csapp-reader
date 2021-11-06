
main2.o:     file format elf64-x86-64
main2.o
architecture: i386:x86-64, flags 0x00000011:
HAS_RELOC, HAS_SYMS
start address 0x0000000000000000

Sections:
Idx Name          Size      VMA               LMA               File off  Algn
  0 .text         00000055  0000000000000000  0000000000000000  00000040  2**0
                  CONTENTS, ALLOC, LOAD, RELOC, READONLY, CODE
  1 .data         00000010  0000000000000000  0000000000000000  00000098  2**3
                  CONTENTS, ALLOC, LOAD, DATA
  2 .bss          00000008  0000000000000000  0000000000000000  000000a8  2**3
                  ALLOC
  3 .rodata       0000000d  0000000000000000  0000000000000000  000000a8  2**0
                  CONTENTS, ALLOC, LOAD, READONLY, DATA
  4 .comment      00000013  0000000000000000  0000000000000000  000000b5  2**0
                  CONTENTS, READONLY
  5 .note.GNU-stack 00000000  0000000000000000  0000000000000000  000000c8  2**0
                  CONTENTS, READONLY
  6 .note.gnu.property 00000030  0000000000000000  0000000000000000  000000c8  2**3
                  CONTENTS, ALLOC, LOAD, READONLY, DATA
  7 .eh_frame     00000038  0000000000000000  0000000000000000  000000f8  2**3
                  CONTENTS, ALLOC, LOAD, RELOC, READONLY, DATA
SYMBOL TABLE:
0000000000000000 l    df *ABS*	0000000000000000 main2.c
0000000000000000 l    d  .text	0000000000000000 .text
0000000000000000 l    d  .rodata	0000000000000000 .rodata
0000000000000000 g     O .data	0000000000000008 x
0000000000000008 g     O .data	0000000000000008 y
0000000000000000 g     O .bss	0000000000000008 z
0000000000000000 g     F .text	0000000000000055 main
0000000000000000         *UND*	0000000000000000 _GLOBAL_OFFSET_TABLE_
0000000000000000         *UND*	0000000000000000 addvec
0000000000000000         *UND*	0000000000000000 printf



Disassembly of section .text:

0000000000000000 <main>:
   0:	55                   	push   %rbp
   1:	48 89 e5             	mov    %rsp,%rbp
   4:	b9 02 00 00 00       	mov    $0x2,%ecx
   9:	48 8d 05 00 00 00 00 	lea    0x0(%rip),%rax        # 10 <main+0x10>
			c: R_X86_64_PC32	z-0x4
  10:	48 89 c2             	mov    %rax,%rdx
  13:	48 8d 05 00 00 00 00 	lea    0x0(%rip),%rax        # 1a <main+0x1a>
			16: R_X86_64_PC32	y-0x4
  1a:	48 89 c6             	mov    %rax,%rsi
  1d:	48 8d 05 00 00 00 00 	lea    0x0(%rip),%rax        # 24 <main+0x24>
			20: R_X86_64_PC32	x-0x4
  24:	48 89 c7             	mov    %rax,%rdi
  27:	e8 00 00 00 00       	call   2c <main+0x2c>
			28: R_X86_64_PLT32	addvec-0x4
  2c:	8b 15 00 00 00 00    	mov    0x0(%rip),%edx        # 32 <main+0x32>
			2e: R_X86_64_PC32	z
  32:	8b 05 00 00 00 00    	mov    0x0(%rip),%eax        # 38 <main+0x38>
			34: R_X86_64_PC32	z-0x4
  38:	89 c6                	mov    %eax,%esi
  3a:	48 8d 05 00 00 00 00 	lea    0x0(%rip),%rax        # 41 <main+0x41>
			3d: R_X86_64_PC32	.rodata-0x4
  41:	48 89 c7             	mov    %rax,%rdi
  44:	b8 00 00 00 00       	mov    $0x0,%eax
  49:	e8 00 00 00 00       	call   4e <main+0x4e>
			4a: R_X86_64_PLT32	printf-0x4
  4e:	b8 00 00 00 00       	mov    $0x0,%eax
  53:	5d                   	pop    %rbp
  54:	c3                   	ret    
