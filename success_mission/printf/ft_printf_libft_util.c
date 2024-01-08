/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_libft_util.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juha <juha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 03:00:15 by juha	           #+#    #+#             */
/*   Updated: 2022/05/25 15:21:29 by juha             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_strlen(const char	*s)
{
	size_t	cnt;

	cnt = 0;
	while (s[cnt])
		cnt++;
	return (cnt);
}

void	ft_putnbr_fd(long long n, int fd)
{
	long long	l;

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

void	write_num(int fd, long long l)
{
	int			cnt;
	size_t		temp;
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
