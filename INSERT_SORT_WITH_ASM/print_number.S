	.global print_number
	.extern	print_char
print_number:
	push	%rax
	push	%rbx
	push	%rcx
	push	%rdx
	push	%rdi
	
	xor	%rcx, %rcx
	mov	%rdi, %rax
.Lnext_char:
	mov	$10, %rbx
	xor	%rdx, %rdx
	div	%rbx
	add	$'0', %rdx
	push	%rdx
	inc	%rcx
	test	%rax, %rax
	je	.Lprint_chars
	jmp	.Lnext_char

.Lprint_chars:
	test	%rcx, %rcx
	je	.Lend
	pop	%rax
	push	%rcx
	call	print_char
	pop	%rcx
	dec	%rcx
	jmp	.Lprint_chars
.Lend:
	pop 	%rdi
	pop 	%rdx
	pop	%rcx
	pop	%rbx
	pop	%rax
	ret
