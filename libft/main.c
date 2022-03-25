#include "libft.h"
#include <stdio.h>
#include <string.h>
#include <unistd.h>

static void		write_num(int fd, long long l);

void	ft_putnbr_fd(int n, int fd)
{
	long long	l;

	if (fd < 0)
		return ;
	if (n == 0)
		write(fd, "0", 1);
	l = n;
	if (0 >= l)
	{
		write(fd, "-", 1);
		l *= -1;
	}
	write_num(fd, l);
}

static void	write_num(int fd, long long l)
{
	int			cnt;
	long long	temp;
	char		c;

	cnt = 1;
	temp = l;
	while (temp)
	{
		temp /= 10;
		if (temp)
			cnt *= 10;
		printf("cnt 1: %d\n",cnt);
	}
	while (1 < cnt)
	{
		c = l / cnt + 48;
		// printf("c : %c, cnt 2: %d\n",c, cnt);
		write (fd, &c, 1);
		l %= cnt;
		cnt /= 10;
	}
	if (l == 0)
		write(fd, "0", 1);
}

int	main()
{
	int i = (3529470);
	ft_putnbr_fd (i, 2);
	return (0);
}
