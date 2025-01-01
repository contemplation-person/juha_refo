section .text
	global ft_strlen

ft_strlen:
	xor rax,rax

start_loop:
	cmp byte [rdi + rax], 0
	je return_len
	inc rax
	jmp start_loop

return_len:
	ret


