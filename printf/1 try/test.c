#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "ft_printf.h"

int	main(void)
{
	int	cnt;

	cnt = ft_printf("%c", 'd');
	printf("\nprintf : %d", cnt);
	return (0);
}
    /*test(1, -1 , 0Xf, 0xffff);//longlong범위가 넘어가면 break;*/