	.file	"load_store.c"
	.text
	.globl	write_read
	.type	write_read, @function
write_read:
.LFB0:
	.cfi_startproc
	testq	%rdx, %rdx
	je	.L1
	movl	$0, %eax
.L3:
	movq	%rax, (%rsi)
	movq	(%rdi), %rax
	addq	$1, %rax
	subq	$1, %rdx
	jne	.L3
.L1:
	ret
	.cfi_endproc
.LFE0:
	.size	write_read, .-write_read
	.ident	"GCC: (GNU) 11.1.0"
	.section	.note.GNU-stack,"",@progbits
