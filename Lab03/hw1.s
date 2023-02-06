	.section	__TEXT,__text,regular,pure_instructions
	.build_version macos, 11, 0	sdk_version 11, 0
	.globl	_main                   ## -- Begin function main
	.p2align	4, 0x90
_main:                                  ## @main
	.cfi_startproc
## %bb.0:
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register %rbp
	pushq	%r15
	pushq	%r14
	pushq	%r13
	pushq	%r12
	pushq	%rbx
	subq	$24, %rsp
	.cfi_offset %rbx, -56
	.cfi_offset %r12, -48
	.cfi_offset %r13, -40
	.cfi_offset %r14, -32
	.cfi_offset %r15, -24
	movl	$0, -44(%rbp)
	callq	_rand
	cltq
	imulq	$1717986919, %rax, %rcx ## imm = 0x66666667
	movq	%rcx, %rdx
	shrq	$63, %rdx
	sarq	$34, %rcx
	addl	%edx, %ecx
	addl	%ecx, %ecx
	leal	(%rcx,%rcx,4), %ecx
	movl	%eax, %r14d
	subl	%ecx, %r14d
	negl	%ecx
	leal	1(%rax,%rcx), %r15d
	leaq	L_str.14(%rip), %rbx
	movq	%rbx, %rdi
	callq	_puts
	leaq	L_str.13(%rip), %rdi
	callq	_puts
	movq	%rbx, %rdi
	callq	_puts
	leaq	L_.str.3(%rip), %r12
	leaq	-44(%rbp), %r13
	xorl	%ebx, %ebx
	.p2align	4, 0x90
LBB0_1:                                 ## =>This Inner Loop Header: Depth=1
	leaq	L_.str.2(%rip), %rdi
	xorl	%eax, %eax
	callq	_printf
	movq	%r12, %rdi
	movq	%r13, %rsi
	xorl	%eax, %eax
	callq	_scanf
	incl	%ebx
	movl	-44(%rbp), %eax
	cmpl	%r15d, %eax
	leaq	L_str.15(%rip), %rdi
	leaq	L_str.16(%rip), %rcx
	cmovgq	%rcx, %rdi
	cmpl	%r14d, %eax
	leaq	L_str.17(%rip), %rax
	cmovleq	%rax, %rdi
	callq	_puts
	cmpl	%r15d, -44(%rbp)
	jne	LBB0_1
## %bb.2:
	callq	_rand
	cltq
	imulq	$1717986919, %rax, %rcx ## imm = 0x66666667
	movq	%rcx, %rdx
	shrq	$63, %rdx
	sarq	$34, %rcx
	addl	%edx, %ecx
	addl	%ecx, %ecx
	leal	(%rcx,%rcx,4), %ecx
	movl	%eax, %r12d
	subl	%ecx, %r12d
	negl	%ecx
	leal	1(%rax,%rcx), %r13d
	leaq	L_str.14(%rip), %r14
	movq	%r14, %rdi
	callq	_puts
	leaq	L_str.13(%rip), %rdi
	callq	_puts
	movq	%r14, %rdi
	callq	_puts
	leaq	-44(%rbp), %r14
	xorl	%r15d, %r15d
	.p2align	4, 0x90
LBB0_3:                                 ## =>This Inner Loop Header: Depth=1
	leaq	L_.str.2(%rip), %rdi
	xorl	%eax, %eax
	callq	_printf
	leaq	L_.str.3(%rip), %rdi
	movq	%r14, %rsi
	xorl	%eax, %eax
	callq	_scanf
	incl	%r15d
	movl	-44(%rbp), %eax
	cmpl	%r13d, %eax
	leaq	L_str.15(%rip), %rdi
	leaq	L_str.16(%rip), %rcx
	cmovgq	%rcx, %rdi
	cmpl	%r12d, %eax
	leaq	L_str.17(%rip), %rax
	cmovleq	%rax, %rdi
	callq	_puts
	cmpl	%r13d, -44(%rbp)
	jne	LBB0_3
## %bb.4:
	callq	_rand
	cltq
	imulq	$1717986919, %rax, %rcx ## imm = 0x66666667
	movq	%rcx, %rdx
	shrq	$63, %rdx
	sarq	$34, %rcx
	addl	%edx, %ecx
	addl	%ecx, %ecx
	leal	(%rcx,%rcx,4), %ecx
	movl	%eax, %r14d
	subl	%ecx, %r14d
	negl	%ecx
	leal	1(%rax,%rcx), %r13d
	leaq	L_str.14(%rip), %r12
	movq	%r12, %rdi
	callq	_puts
	leaq	L_str.13(%rip), %rdi
	callq	_puts
	movq	%r12, %rdi
	callq	_puts
	xorl	%r12d, %r12d
	.p2align	4, 0x90
LBB0_5:                                 ## =>This Inner Loop Header: Depth=1
	leaq	L_.str.2(%rip), %rdi
	xorl	%eax, %eax
	callq	_printf
	leaq	L_.str.3(%rip), %rdi
	leaq	-44(%rbp), %rsi
	xorl	%eax, %eax
	callq	_scanf
	incl	%r12d
	movl	-44(%rbp), %eax
	cmpl	%r13d, %eax
	leaq	L_str.15(%rip), %rdi
	leaq	L_str.16(%rip), %rcx
	cmovgq	%rcx, %rdi
	cmpl	%r14d, %eax
	leaq	L_str.17(%rip), %rax
	cmovleq	%rax, %rdi
	callq	_puts
	cmpl	%r13d, -44(%rbp)
	jne	LBB0_5
## %bb.6:
	movl	%ebx, -52(%rbp)         ## 4-byte Spill
	callq	_rand
	cltq
	imulq	$1717986919, %rax, %rcx ## imm = 0x66666667
	movq	%rcx, %rdx
	shrq	$63, %rdx
	sarq	$34, %rcx
	addl	%edx, %ecx
	addl	%ecx, %ecx
	leal	(%rcx,%rcx,4), %ecx
	movl	%eax, %edx
	subl	%ecx, %edx
	movl	%edx, -48(%rbp)         ## 4-byte Spill
	negl	%ecx
	leal	1(%rax,%rcx), %ebx
	leaq	L_str.14(%rip), %r13
	movq	%r13, %rdi
	callq	_puts
	leaq	L_str.13(%rip), %rdi
	callq	_puts
	movq	%r13, %rdi
	callq	_puts
	xorl	%r13d, %r13d
	leaq	L_str.16(%rip), %r14
	.p2align	4, 0x90
LBB0_7:                                 ## =>This Inner Loop Header: Depth=1
	leaq	L_.str.2(%rip), %rdi
	xorl	%eax, %eax
	callq	_printf
	leaq	L_.str.3(%rip), %rdi
	leaq	-44(%rbp), %rsi
	xorl	%eax, %eax
	callq	_scanf
	incl	%r13d
	movl	-44(%rbp), %eax
	cmpl	%ebx, %eax
	leaq	L_str.15(%rip), %rdi
	cmovgq	%r14, %rdi
	cmpl	-48(%rbp), %eax         ## 4-byte Folded Reload
	leaq	L_str.17(%rip), %rax
	cmovleq	%rax, %rdi
	callq	_puts
	cmpl	%ebx, -44(%rbp)
	jne	LBB0_7
## %bb.8:
	callq	_rand
	cltq
	imulq	$1717986919, %rax, %rcx ## imm = 0x66666667
	movq	%rcx, %rdx
	shrq	$63, %rdx
	sarq	$34, %rcx
	addl	%edx, %ecx
	addl	%ecx, %ecx
	leal	(%rcx,%rcx,4), %ecx
	movl	%eax, %edx
	subl	%ecx, %edx
	movl	%edx, -48(%rbp)         ## 4-byte Spill
	negl	%ecx
	leal	1(%rax,%rcx), %r14d
	leaq	L_str.14(%rip), %rbx
	movq	%rbx, %rdi
	callq	_puts
	leaq	L_str.13(%rip), %rdi
	callq	_puts
	movq	%rbx, %rdi
	callq	_puts
	xorl	%ebx, %ebx
	.p2align	4, 0x90
LBB0_9:                                 ## =>This Inner Loop Header: Depth=1
	leaq	L_.str.2(%rip), %rdi
	xorl	%eax, %eax
	callq	_printf
	leaq	L_.str.3(%rip), %rdi
	leaq	-44(%rbp), %rsi
	xorl	%eax, %eax
	callq	_scanf
	incl	%ebx
	movl	-44(%rbp), %eax
	cmpl	%r14d, %eax
	leaq	L_str.15(%rip), %rdi
	leaq	L_str.16(%rip), %rcx
	cmovgq	%rcx, %rdi
	cmpl	-48(%rbp), %eax         ## 4-byte Folded Reload
	leaq	L_str.17(%rip), %rax
	cmovleq	%rax, %rdi
	callq	_puts
	cmpl	%r14d, -44(%rbp)
	jne	LBB0_9
## %bb.10:
	leaq	L_str.11(%rip), %r14
	movq	%r14, %rdi
	callq	_puts
	leaq	L_str.10(%rip), %rdi
	callq	_puts
	movq	%r14, %rdi
	callq	_puts
	leaq	L_.str.9(%rip), %r14
	movq	%r14, %rdi
	xorl	%esi, %esi
	movl	-52(%rbp), %edx         ## 4-byte Reload
	xorl	%eax, %eax
	callq	_printf
	movq	%r14, %rdi
	movl	$1, %esi
	movl	%r15d, %edx
	xorl	%eax, %eax
	callq	_printf
	movq	%r14, %rdi
	movl	$2, %esi
	movl	%r12d, %edx
	xorl	%eax, %eax
	callq	_printf
	movq	%r14, %rdi
	movl	$3, %esi
	movl	%r13d, %edx
	xorl	%eax, %eax
	callq	_printf
	movq	%r14, %rdi
	movl	$4, %esi
	movl	%ebx, %edx
	xorl	%eax, %eax
	callq	_printf
	xorl	%eax, %eax
	addq	$24, %rsp
	popq	%rbx
	popq	%r12
	popq	%r13
	popq	%r14
	popq	%r15
	popq	%rbp
	retq
	.cfi_endproc
                                        ## -- End function
	.section	__TEXT,__cstring,cstring_literals
L_.str.2:                               ## @.str.2
	.asciz	"Make a guess:"

L_.str.3:                               ## @.str.3
	.asciz	"%d"

L_.str.9:                               ## @.str.9
	.asciz	"Game %d took you %d guesses\n"

L_str.10:                               ## @str.10
	.asciz	"|Here are the results of your guessing abilities|"

L_str.11:                               ## @str.11
	.asciz	"==============================================="

L_str.13:                               ## @str.13
	.asciz	"CPU Says: Pick a number 1-10"

L_str.14:                               ## @str.14
	.asciz	"============================"

L_str.15:                               ## @str.15
	.asciz	"You got it!"

L_str.16:                               ## @str.16
	.asciz	"No guess lower!"

L_str.17:                               ## @str.17
	.asciz	"No guess higher!"

.subsections_via_symbols
