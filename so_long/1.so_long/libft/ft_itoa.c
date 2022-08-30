/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: conteng <conteng@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 18:50:25 by juha              #+#    #+#             */
/*   Updated: 2022/04/02 11:00:42 by conteng          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	cnt_zero(size_t l);
static char	*change_string(char *s, int cnt, size_t n, int is_minus);

char	*ft_itoa(int n)
{
	char	*s;
	int		is_minus;
	int		cnt;
	long	l;

	if (n == 0)
		return (ft_strdup("0"));
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

static int	cnt_zero(size_t l)
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

static char	*change_string(char *s, int cnt, size_t n, int is_minus)
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
