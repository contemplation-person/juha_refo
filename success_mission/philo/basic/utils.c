/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juha <juha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 14:38:02 by juha              #+#    #+#             */
/*   Updated: 2022/11/11 14:23:12 by juha             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

static size_t	change_size_t(const char *str)
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

int	ft_atoi(const char *str)
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
		return (-1);
	else
	{
		if (cnt > 2147483647)
			return (-1);
	}
	return ((int)cnt * is_minus);
}

size_t	ft_strlen(const char	*s)
{
	size_t	cnt;

	cnt = 0;
	while (s[cnt])
		cnt++;
	return (cnt);
}

t_bool	is_error(char *str, char *file)
{
	write(STDERR_FILENO, str, ft_strlen(str));
	write(STDERR_FILENO, file, ft_strlen(file));
	return (TRUE);
}

void	*ft_calloc(size_t count, size_t size)
{
	unsigned char	*p;

	p = (unsigned char *)malloc(count * size);
	if (!p)
		return (0);
	memset(p, 0, size * count);
	return ((void *)p);
}
