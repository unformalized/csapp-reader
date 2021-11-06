	.file	"swap.i"
	.text
	.globl	swap
	.type	swap, @function
swap:
.LFB0:
	.cfi_startproc
	leaq	4+buf(%rip), %rax
	movq	%rax, bufp1(%rip)
	movq	bufp0(%rip), %rax
	movl	(%rax), %edx
	movl	4+buf(%rip), %ecx
	movl	%ecx, (%rax)
	movq	bufp1(%rip), %rax
	movl	%edx, (%rax)
	ret
	.cfi_endproc
.LFE0:
	.size	swap, .-swap
	.globl	bufp1
	.bss
	.align 8
	.type	bufp1, @object
	.size	bufp1, 8
bufp1:
	.zero	8
	.globl	bufp0
	.section	.data.rel,"aw"
	.align 8
	.type	bufp0, @object
	.size	bufp0, 8
bufp0:
	.quad	buf
	.ident	"GCC: (GNU) 11.1.0"
	.section	.note.GNU-stack,"",@progbits
