#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "ft_printf.h"

int	main(void)
{
	int		ft_cnt;
	int		cnt;
//	char	*str;

	cnt = 0;
//	str = "%%p is how you print a pointer in printf";
	// str = "8.%p\n";
	ft_cnt = ft_printf("ft : %c%c%c*\n", '\0', '1', 1);
	cnt = printf("or : %c%c%c*\n", '\0', '1', 1);
	// ft_cnt = ft_printf(str, 0, "\0", 0xfff, 0xfff, 0xfff, (void *)0, 0xfff,0xa1f);
	// cnt = printf(str, 0, "\0", 0xfff, 0xfff, 0xfff, (void *)0, 0xfff, 0xa1f);

	printf("\nft_cnt : %d", ft_cnt);
	printf("\ncnt    : %d", cnt);
	// system("leaks a.out");
	return (0);
} //32 % 33x
    /*test(1, -1 , 0Xf, 0xffff);//longlong범위가 넘어가면 break;*/