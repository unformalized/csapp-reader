	.file	"memory_preformance.c"
	.text
	.globl	list_len
	.type	list_len, @function
list_len:
.LFB0:
	.cfi_startproc
	testq	%rdi, %rdi
	je	.L4
	movl	$0, %eax
.L3:
	addq	$1, %rax
	movq	(%rdi), %rdi
	testq	%rdi, %rdi
	jne	.L3
	ret
.L4:
	movl	$0, %eax
	ret
	.cfi_endproc
.LFE0:
	.size	list_len, .-list_len
	.ident	"GCC: (GNU) 11.1.0"
	.section	.note.GNU-stack,"",@progbits
