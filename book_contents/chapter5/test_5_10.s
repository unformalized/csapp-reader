	.file	"test_5_10.c"
	.text
	.globl	copy_array
	.type	copy_array, @function
copy_array:
.LFB0:
	.cfi_startproc
	testq	%rdx, %rdx
	jle	.L1
	movl	$0, %eax
.L3:
	movq	(%rdi,%rax,8), %rcx
	movq	%rcx, (%rsi,%rax,8)
	addq	$1, %rax
	cmpq	%rax, %rdx
	jne	.L3
.L1:
	ret
	.cfi_endproc
.LFE0:
	.size	copy_array, .-copy_array
	.ident	"GCC: (GNU) 11.1.0"
	.section	.note.GNU-stack,"",@progbits
