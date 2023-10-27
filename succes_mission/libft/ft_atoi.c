/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juha <juha@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 17:18:30 by juha              #+#    #+#             */
/*   Updated: 2022/04/01 19:11:41 by juha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	change_size_t(const char *str);

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
	{
		if (cnt >= LLONG_MIN)
			return (0);
	}
	else
	{
		if (cnt >= LLONG_MAX)
			return (-1);
	}
	return ((int)cnt * is_minus);
}

static size_t	change_size_t(const char *str)
{
	size_t	cnt;

	cnt = 0;
	while (*str && ft_isdigit(*str))
	{
		cnt = cnt * 10;
		cnt = cnt + ((*str) - '0');
		str++;
	}
	return (cnt);
}
