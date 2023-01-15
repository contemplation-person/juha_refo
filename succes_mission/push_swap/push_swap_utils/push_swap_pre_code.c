/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_pre_code.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juha <juha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 10:43:18 by juha              #+#    #+#             */
/*   Updated: 2023/01/10 13:28:00 by juha             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

size_t			change_size_t(const char *str);
size_t			ft_strlen(const char	*s);
long			ft_atoi(const char	*str);
int				ft_memcmp(const void *s1, const void *s2, size_t n);

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*s_temp1;
	unsigned char	*s_temp2;
	size_t			i;

	s_temp1 = (unsigned char *)s1;
	s_temp2 = (unsigned char *)s2;
	i = 0;
	while (i < n)
	{
		if (s_temp1[i] != s_temp2[i])
			return (s_temp1[i] - s_temp2[i]);
		i++;
	}
	return (0);
}

size_t	ft_strlen(const char	*s)
{
	size_t	cnt;

	if (!s)
		return (0);
	cnt = 0;
	while (s[cnt])
		cnt++;
	return (cnt);
}

size_t	change_size_t(const char *str)
{
	size_t	cnt;

	cnt = 0;
	while (*str && '0' <= *str && *str <= '9')
	{
		cnt = cnt * 10;
		cnt = cnt + ((*str) - '0');
		str++;
	}
	return (cnt);
}

long	ft_atoi(const char *str)
{
	size_t	cnt;
	int		is_minus;

	is_minus = 1;
	while (*str == 32 || (9 <= *str && *str <= 13))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			is_minus = -1;
		str++;
	}
	cnt = change_size_t(str);
	if (is_minus == -1)
	{
		if (cnt >= 9223372036854775808U)
			return (0);
	}
	else
	{
		if (cnt >= 9223372036854775807)
			return (-1);
	}
	return (cnt * is_minus);
}

void	write_error(char *error_file)
{
	write(2, error_file, ft_strlen(error_file));
	exit(1);
}
