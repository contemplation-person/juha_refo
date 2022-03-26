/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juha <juha@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 12:27:09 by juha              #+#    #+#             */
/*   Updated: 2022/03/26 13:43:58 by juha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

static void		write_num(int fd, long long l);

void	ft_putnbr_fd(int n, int fd)
{
	long long	l;

	if (fd < 0)
		return ;
	if (n == 0)
	{
		write(fd, "0", 1);
		return ;
	}
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
	}
	while (1 < cnt)
	{
		c = l / cnt + 48;
		write (fd, &c, 1);
		l %= cnt;
		cnt /= 10;
	}
	c = l + 48;
	write(fd, &c, 1);
}
