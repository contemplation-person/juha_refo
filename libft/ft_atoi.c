/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: conteng <conteng@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 17:18:30 by juha              #+#    #+#             */
/*   Updated: 2022/03/18 22:49:18 by conteng          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	long long	cnt;
	int			is_minus;

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
	while (*str && '0' <= *str && *str <= '9')
	{
		cnt = cnt * 10;
		cnt = cnt + ((*str) - 48);
		str++;
	}
	if (!str)
		return (0);
	return ((int)cnt * is_minus);
}
