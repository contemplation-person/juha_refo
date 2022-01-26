/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juha <juha@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 10:45:22 by juha              #+#    #+#             */
/*   Updated: 2022/01/26 12:59:44 by juha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	check_minus(char *num)
{
	int	i;

	i = 0;
	while (*num)
	{
		if ('0' <= *num && *num <= '9')
			return (i % 2);
		if (*num == '-')
			i++;
		num++;
	}
	return (i % 2);
}

int	make_num(char *str)
{
	long long int	num;

	num = 0;
	while ((9 <= *str && *str <= 13) || 32 == *str)
		str++;
	while (!('0' <= *str && *str <= '9'))
	{
		if ((9 <= *str && *str <= 13) || 32 == *str)
			break ;
		str++;
	}
	while (*str)
	{
		if ('0' <= *str && *str <= '9')
		{
			num *= 10;
			num += (*str) - '0';
		}
		else
			break ;
		str++;
	}
	return (num);
}

int	ft_atoi(char *str)
{
	long long int	num;

	while ((9 <= *str && *str <= 13) || 32 == *str)
		str++;
	num = make_num(str);
	if (check_minus(str))
		return (-num);
	else
		return (num);
}
