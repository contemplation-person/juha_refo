/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juha <juha@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 17:18:30 by juha              #+#    #+#             */
/*   Updated: 2022/03/16 20:22:15 by juha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(const char *str)
{
	long int	cnt;
	int			is_minus;

	while (*str == 32 || (9 <= *str && *str <= 13) || *str == '+' )
		str++;
	if (*str == '-')
	{
		str++;
		is_minus = -1;
	}
	cnt = 0;
	while (*str && '0' <= *str && *str <= '9')
	{
		cnt *= 10;
		cnt += ((*str) - 48);
		str++;
	}
	if (!str)
		return (0);
	if (is_minus == -1)
		return ((int)cnt * is_minus);
	else
		return ((int)cnt);
}
