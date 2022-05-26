#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "ft_printf.h"

int	main(void)
{
	int		ft_cnt;
	int		cnt;
	char	*str;

	cnt = 0;
	str = "1.%c 2.%s 3.%d 4.%i 5.%u 6.%p 7.%x 8.%X\n";
	// str = "8.%p\n";
	// ft_cnt = ft_printf(str, str);
	// cnt = printf(str, str);
	ft_cnt = ft_printf(str, 'c', "ttt", 0xfff, 0xfff, 0xfff, 0xfff, 0xfff,0xa1f);
	cnt = printf(str, 'c', "ttt", 0xfff, 0xfff, 0xfff, 0xfff, 0xfff, 0xa1f);

	printf("\nft_cnt : %d", ft_cnt);
	printf("\ncnt    : %d", cnt);
	return (0);
} //32 % 33x
    /*test(1, -1 , 0Xf, 0xffff);//longlong범위가 넘어가면 break;*/