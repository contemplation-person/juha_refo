/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juha <juha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 10:45:22 by juha              #+#    #+#             */
/*   Updated: 2022/01/25 10:48:52 by juha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	check_minus(char *num)
{
	int	i;

	i = 0;
	while (*num)
	{
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
	while (*str)
	{
		if ((*str == ' ') || (*str == '\f') || (*str == '\n')
			|| (*str == '\r') || (*str == '\t') || (*str == '\v'))
			return (0);
		if (('a' <= *str && *str <= 'z') || ('A' <= *str && *str <= 'Z'))
			break ;
		if ('0' <= *str && *str <= '9')
		{
			num *= 10;
			num += (*str) - '0';
		}
		str++;
	}
	return (num);
}

int	ft_atoi(char *str)
{
	long long int	num;

	while ((*str == ' ') || (*str == '\f') || (*str == '\n')
		|| (*str == '\r') || (*str == '\t') || (*str == '\v'))
		str++;
	num = make_num(str);
	if (check_minus(str))
		return (-num);
	else
		return (num);
}
