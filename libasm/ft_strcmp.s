section .text
        global ft_strcmp

ft_strcmp:
        xor rax, rax   

start_loop:
        mov al, [rdi]   
        mov bl, [rsi]   
        cmp al, bl     

        jne return_ret

        cmp al, 0    
        je return_ret

        inc rdi     
        inc rsi    
        jmp start_loop 

return_ret:
        sub al, bl    
        movzx rax, al
        test al, al 
        jnz .not_zero 
        xor rax, rax 
        ret 

.not_zero:
        cmp al, 0
        jg .positive
        neg rax    
        ret 

.positive:
        ret 

