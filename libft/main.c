#include "libft.h"
#include <stdio.h>
#include <string.h>

static int	cnt_zero(int n);

char	*ft_itoa(int n)
{
	char	*s;
	int		flag;
	int		cnt;

	flag = 0;
	if (n == 0)
		return (ft_strdup("0"));
	if (0 >= n)
	{
		flag = 1;
		n *= -1;
	}
	cnt = cnt_zero(n) + flag;
	s = (char *)malloc(cnt + 1);
	if (!s)
		return (0);
	s[cnt] = '\0';
	while (--cnt > -1)
	{
		s[cnt] = (n % 10) + 48;
		n /= 10;
	}
	if (flag)
		s[0] = '-';
	return (s);
}

static int	cnt_zero(int n)
{
	int	cnt;

	cnt = 0;
	while (n)
	{
		n /= 10;
		cnt++;
	}
	return (cnt);
}

int	main()
{
	char *s = ft_itoa(-1234);
	printf("%c\n", s[5]);
	printf("%s\n", s);
	return (0);
}
