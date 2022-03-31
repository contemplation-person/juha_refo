/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juha <juha@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 17:18:30 by juha              #+#    #+#             */
/*   Updated: 2022/03/31 22:09:27 by juha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	unsigned long long	cnt;
	int					is_minus;

	if (!str)
		return (0);
	is_minus = 1;
	while (*str == 32 || (9 <= *str && *str <= 13))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			is_minus = -1;
		str++;
	}
	cnt = 0;
	while (*str && ft_isdigit(*str))
	{
		cnt = cnt * 10;
		cnt = cnt + ((*str) - '0');
		str++;
	}
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
	return ((int)cnt * is_minus);
}
