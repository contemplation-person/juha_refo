section .text
        global ft_write
	extern ___error

ft_write:
	mov rax, 0x2000004 
	syscall
	jc set_error
	ret
	
set_error:
	push rax
	call ___error
	pop rdx
	mov rax, -1
	ret

