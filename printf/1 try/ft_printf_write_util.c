/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_write_util.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juha <juha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/22 23:03:12 by juha              #+#    #+#             */
/*   Updated: 2022/05/23 20:52:42 by juha             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>

void	write_str(va_list *ap, char c_or_str)
{
	char	*c;
	int		i;

	c = 0;
	if (c_or_str == '%')
	{
		
	}
	else if (c_or_str == 'c')
	{
		i = 1;
		*c = va_arg(*ap, char);
		write(1, c, i);
	}
	else
	{
		c = va_arg(*ap, char *);
		i = 0;
		while (c[i])
			i++;
		write(1, c, i);
	}
}

void	write_unsigned_int(va_list *ap)
{
	long long	num;
	char		*str;
	int			i;

	num = va_arg(*ap, unsigned int);
	str = ft_itoa(num);
	i = 0;
	while (str[num])
		num++;
	write(1, str, num);
}

void	write_int(va_list *ap)
{
	long long	num;
	char		*str;
	int			i;

	num = va_arg(*ap, int);
	str = ft_itoa(num);
	i = 0;
	while (str[num])
		num++;
	write(1, str, num);
}

void	write_hexa_num(va_list *ap, char c)
{
	long long	num;
	char		*form;

	num = va_arg(*ap, unsigned int);
	if (c == 'x')
		form = "0123456789abcdef";
	else
		form = "0123456789ABCDEF";
	while (1 < num)
	{
		write(1, form + (num % 16), 1);
		num /= 16;
	}
}
