section .text
        global ft_strcpy

ft_strcpy:
        mov rax, rdi

start_loop:
        mov bl, [rsi]
        mov [rdi], bl

        cmp bl, 0
        je return_ret

        inc rdi
        inc rsi
        jmp start_loop

return_ret:
        ret

