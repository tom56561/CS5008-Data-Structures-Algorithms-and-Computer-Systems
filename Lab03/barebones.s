# Build an executable using the following:
#
# clang barebones.s -o barebones  # clang is another compiler like gcc
#
.text
_barebones:

.data
	
.globl main

main:
				# (1) What are we setting up here?
				# Ans: Setting up the stack frame for main function. "pushq %rbp" => The value of RBP is saved onto the stack so that it can be restored later, preserving the state of the stack for function calls and returns. "movq  %rsp, %rbp" => By copying the value of the stack pointer into the base pointer, the instruction sets up a new stack frame for the function being executed. 
	pushq %rbp		#
	movq  %rsp, %rbp	#

				# (2) What is going on here
				# Ans: Move the value 1 into register %rax, will be like: long t = 1;, Move the value 1 into register %rdi, The %rdi register is used as the first program argument in a function."leaq .hello.str,%rsi" loads the address of the string ".hello.str" into the %rsi register
	movq $1, %rax		# 
	movq $1, %rdi		#
	leaq .hello.str,%rsi	#


			# (3) What is syscall? We did not talk about this
			# in class.
			# Ans: "syscall" is used to make a system call to the operating system's kernel. 
			#
	syscall			# Which syscall is being run?
				# Ans: sys_write will be run (movq  %rsp, %rbp)

				# (4) What would another option be instead of 
				# using a syscall to achieve this?
				# Ans: sysenter or int $0x80

	movq	$60, %rax	# (5) We are again setting up another syscall
	movq	$0, %rdi	# What command is it?
				# Ans:	The second syscall is likely to be the exit system call, with the command code 60 stored in %rax and the exit status 0 stored in %rdi.
	syscall

	popq %rbp		# (Note we do not really need
			 	# this command here after the syscall)

.hello.str:
	.string "Hello World!\n"
	.size	.hello.str,13		# (6) Why is there a 13 here?
					# Ans:	The value "13" is the length of the string ".hello.str".
