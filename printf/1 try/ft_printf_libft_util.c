/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_libft_util.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juha <juha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 03:00:15 by conteng           #+#    #+#             */
/*   Updated: 2022/05/23 19:29:34 by juha             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_itoa(int n)
{
	char	*s;
	int		is_minus;
	int		cnt;
	long	l;

	if (n == 0)
		return ("0");
	is_minus = 0;
	l = n;
	if (0 >= l)
	{
		is_minus = 1;
		l *= -1;
	}
	cnt = cnt_zero(l) + is_minus;
	s = (char *)malloc(cnt + 1);
	if (!s)
		return (0);
	s = change_string(s, cnt, l, is_minus);
	return (s);
}

int	cnt_zero(size_t l)
{
	int	cnt;

	cnt = 0;
	while (l)
	{
		l /= 10;
		cnt++;
	}
	return (cnt);
}

char	*change_string(char *s, int cnt, size_t n, int is_minus)
{
	s[cnt] = '\0';
	while (--cnt > -1)
	{
		s[cnt] = (n % 10) + 48;
		n /= 10;
	}
	if (is_minus)
		s[0] = '-';
	return (s);
}

size_t	ft_strlen(const char	*s)
{
	size_t	cnt;

	cnt = 0;
	while (s[cnt])
		cnt++;
	return (cnt);
}
