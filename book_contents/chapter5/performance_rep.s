	.file	"performance_rep.c"
	.text
	.globl	psum1
	.type	psum1, @function
psum1:
.LFB22:
	.cfi_startproc
	movss	(%rdi), %xmm0
	movss	%xmm0, (%rsi)
	cmpq	$1, %rdx
	jle	.L1
	movl	$1, %eax
.L3:
	movss	-4(%rsi,%rax,4), %xmm0
	addss	(%rdi,%rax,4), %xmm0
	movss	%xmm0, (%rsi,%rax,4)
	addq	$1, %rax
	cmpq	%rax, %rdx
	jne	.L3
.L1:
	ret
	.cfi_endproc
.LFE22:
	.size	psum1, .-psum1
	.globl	psum2
	.type	psum2, @function
psum2:
.LFB23:
	.cfi_startproc
	movss	(%rdi), %xmm0
	movss	%xmm0, (%rsi)
	leaq	-1(%rdx), %rcx
	cmpq	$1, %rcx
	jle	.L9
	movl	$1, %eax
.L7:
	movss	-4(%rsi,%rax,4), %xmm0
	addss	(%rdi,%rax,4), %xmm0
	movss	%xmm0, (%rsi,%rax,4)
	addss	4(%rdi,%rax,4), %xmm0
	movss	%xmm0, 4(%rsi,%rax,4)
	addq	$2, %rax
	cmpq	%rcx, %rax
	jl	.L7
	leaq	-3(%rdx), %rax
	andq	$-2, %rax
	addq	$3, %rax
.L6:
	cmpq	%rax, %rdx
	jle	.L5
	movss	-4(%rsi,%rax,4), %xmm0
	addss	(%rdi,%rax,4), %xmm0
	movss	%xmm0, (%rsi,%rax,4)
.L5:
	ret
.L9:
	movl	$1, %eax
	jmp	.L6
	.cfi_endproc
.LFE23:
	.size	psum2, .-psum2
	.globl	genFArr
	.type	genFArr, @function
genFArr:
.LFB24:
	.cfi_startproc
	pushq	%rbx
	.cfi_def_cfa_offset 16
	.cfi_offset 3, -16
	movl	%edi, %ebx
	movslq	%edi, %rdi
	salq	$2, %rdi
	call	malloc@PLT
	testl	%ebx, %ebx
	jle	.L11
	movl	%ebx, %edi
	movl	$0, %edx
.L13:
	pxor	%xmm0, %xmm0
	cvtsi2ssl	%edx, %xmm0
	movss	%xmm0, (%rax,%rdx,4)
	addq	$1, %rdx
	cmpq	%rdi, %rdx
	jne	.L13
.L11:
	popq	%rbx
	.cfi_def_cfa_offset 8
	ret
	.cfi_endproc
.LFE24:
	.size	genFArr, .-genFArr
	.section	.rodata.str1.8,"aMS",@progbits,1
	.align 8
.LC0:
	.string	"per_num = %d, psum1 spend time: %d, psum2 spend time: %d\n"
	.text
	.globl	main
	.type	main, @function
main:
.LFB25:
	.cfi_startproc
	pushq	%r15
	.cfi_def_cfa_offset 16
	.cfi_offset 15, -16
	pushq	%r14
	.cfi_def_cfa_offset 24
	.cfi_offset 14, -24
	pushq	%r13
	.cfi_def_cfa_offset 32
	.cfi_offset 13, -32
	pushq	%r12
	.cfi_def_cfa_offset 40
	.cfi_offset 12, -40
	pushq	%rbp
	.cfi_def_cfa_offset 48
	.cfi_offset 6, -48
	pushq	%rbx
	.cfi_def_cfa_offset 56
	.cfi_offset 3, -56
	subq	$72, %rsp
	.cfi_def_cfa_offset 128
	movq	%fs:40, %rax
	movq	%rax, 56(%rsp)
	xorl	%eax, %eax
	movl	$2000, 16(%rsp)
	movl	$4000, 20(%rsp)
	movl	$10000, 24(%rsp)
	movl	$50000, 28(%rsp)
	movl	$100000, 32(%rsp)
	movl	$500000, 36(%rsp)
	movl	$1000000, 40(%rsp)
	movl	$2000000, 44(%rsp)
	movl	$5000000, 48(%rsp)
	movl	$10000000, 52(%rsp)
	leaq	16(%rsp), %r13
	leaq	56(%rsp), %rax
	movq	%rax, 8(%rsp)
.L17:
	movl	0(%r13), %r14d
	movl	%r14d, %edi
	call	genFArr
	movq	%rax, %rbp
	movslq	%r14d, %r15
	leaq	0(,%r15,4), %rdi
	call	malloc@PLT
	movq	%rax, %r12
	call	clock@PLT
	movq	%rax, (%rsp)
	movq	%r15, %rdx
	movq	%r12, %rsi
	movq	%rbp, %rdi
	call	psum1
	call	clock@PLT
	movq	%rax, %rbx
	movq	%r15, %rdx
	movq	%r12, %rsi
	movq	%rbp, %rdi
	call	psum2
	call	clock@PLT
	movq	%rax, %rcx
	subq	%rbx, %rcx
	subq	(%rsp), %rbx
	movq	%rbx, %rdx
	movl	%r14d, %esi
	leaq	.LC0(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
	addq	$4, %r13
	cmpq	8(%rsp), %r13
	jne	.L17
	movq	56(%rsp), %rax
	subq	%fs:40, %rax
	jne	.L21
	movl	$0, %eax
	addq	$72, %rsp
	.cfi_remember_state
	.cfi_def_cfa_offset 56
	popq	%rbx
	.cfi_def_cfa_offset 48
	popq	%rbp
	.cfi_def_cfa_offset 40
	popq	%r12
	.cfi_def_cfa_offset 32
	popq	%r13
	.cfi_def_cfa_offset 24
	popq	%r14
	.cfi_def_cfa_offset 16
	popq	%r15
	.cfi_def_cfa_offset 8
	ret
.L21:
	.cfi_restore_state
	call	__stack_chk_fail@PLT
	.cfi_endproc
.LFE25:
	.size	main, .-main
	.ident	"GCC: (GNU) 11.1.0"
	.section	.note.GNU-stack,"",@progbits
