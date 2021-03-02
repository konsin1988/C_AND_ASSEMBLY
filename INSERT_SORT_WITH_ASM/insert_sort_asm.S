	.global insert_sort_asm
insert_sort_asm:
	push	%rsi
	push	%rdx
	push	%rdi
	xor	%rcx, %rcx
	inc	%rcx
.first_loop:
	cmp	%rcx, 16(%rsp) 
	je	.break_first
	push	%rcx
.second_loop:
	test	%rcx, %rcx
	jz	.break_second
	push	%rcx
	mov	16(%rsp), %rbx
	mov	(%rbx, %rcx, 4), %rax
	mov	-4(%rbx, %rcx, 4), %rdx
	cmp	%eax, %edx 
	jg	.swap
	pop	%rcx
	jmp	.break_second
.swap:
	push	4(%rbx, %rcx, 4)
	xchg	-4(%rbx, %rcx, 4), %rax
	xchg	(%rbx, %rcx, 4), %rdx
	pop	4(%rbx, %rcx, 4)
	pop	%rcx
	dec	%rcx		
	jmp	.second_loop
.break_second:
	pop	%rcx
	inc	%rcx
	jmp	.first_loop
.break_first:
	pop	%rdi
	pop	%rdx
	pop	%rsi	
	ret
	
