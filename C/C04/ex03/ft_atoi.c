/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juha <juha@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 10:45:22 by juha              #+#    #+#             */
/*   Updated: 2022/01/27 17:21:24 by juha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	is_plus(char *str)
{
	int	plus;

	plus = 1;
	while ((9 <= *str && *str <= 13) || 32 == *str
		|| *str == '-' || *str == '+')
	{
		if (*str == '-')
			plus *= -1;
		str++;
	}
	return (plus);
}

int	ft_atoi(char *str)
{
	long long	num;
	int			plus;

	num = 0;
	plus = is_plus(str);
	while ((9 <= *str && *str <= 13) || 32 == *str
		|| *str == '-' || *str == '+')
		str++;
	if (!('0' <= *str && *str <= '9') || *str == '0')
		return (0);
	while ('0' <= *str && *str <= '9')
	{
		num *= 10;
		num += (*str) - '0';
		str++;
	}
	if (plus == 1)
		return (num);
	else
		return (-num);
}
