#include <asm/unistd_64.h>

	.section .bss
char:
	.word

	.section .text
	.global print_char
print_char:
	push	%rsi
	push	%rdx
	push	%rdi
	push	%rax
	
	
	mov	$__NR_write, %rax
	mov	$1, %rdi
	mov	%rsp, %rsi
	mov	$1, %rdx
	syscall

	pop	%rax
	pop	%rdi
	pop	%rdx
	pop	%rsi

	ret
