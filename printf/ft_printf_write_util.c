/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_write_util.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juha <juha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/22 23:03:12 by juha              #+#    #+#             */
/*   Updated: 2022/05/25 16:52:17 by juha             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>

void	write_str(va_list *ap, char c_or_str, size_t *form_len)
{
	char	*str;
	char	c;
	int		i;

	str = NULL;
	if (c_or_str == '%')
	{
		(*form_len)++;
		write(1, "%", 1);
	}
	else if (c_or_str == 'c')
	{
		(*form_len)++;
		c = (char)va_arg(*ap, int);
		write(1, &c, 1);
	}
	else
	{
		str = va_arg(*ap, char *);
		i = 0;
		while (str[i])
			i++;
		(*form_len) += i;
		write(1, str, i);
	}
}

void	write_unsigned_int(va_list *ap, size_t *form_len)
{
	long long	num;
	char		*str;
	int			i;

	num = va_arg(*ap, unsigned int);
	str = ft_itoa(num);
	i = 0;
	while (str[i])
		i++;
	(*form_len) += i;
	write(1, str, i);
	free(str);
}

void	write_int(va_list *ap, size_t *form_len)
{
	long long	num;
	char		*str;
	int			i;

	num = va_arg(*ap, int);
	str = ft_itoa(num);
	i = 0;
	while (str[i])
		i++;
	write(1, str, i);
	(*form_len) += i;
	free(str);
}

void	write_hexa_num(va_list *ap, char c, size_t *form_len)
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
		(*form_len)++;
		num /= 16;
	}
}
