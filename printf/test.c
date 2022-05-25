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
	str = "sdf %% sdf%c %s %d %i %u %x %X sadf";
	ft_cnt = ft_printf(str, 'c', "ttt", 0xfff, 0xfff, 0xfff, 0xfff, 0xfff);
	cnt = printf(str, 'c', "ttt", 0xfff, 0xfff, 0xfff, 0xfff, 0xfff);

	printf("\nft_cnt : %d", ft_cnt);
	printf("\ncnt    : %d", cnt);
	return (0);
}
    /*test(1, -1 , 0Xf, 0xffff);//longlong범위가 넘어가면 break;*/