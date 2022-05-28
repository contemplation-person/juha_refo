/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_str_util.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juha <juha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/22 23:03:12 by juha              #+#    #+#             */
/*   Updated: 2022/05/28 16:32:40 by juha             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>

void	write_c(va_list *ap, char c, size_t *form_len)
{
	char	*ret;

	ret = &c;
	if (c == 'c')
	{
		(*form_len)++;
		*ret = (char)va_arg(*ap, int);
		write(1, ret, 1);
	}
	else if (c == '%')
	{
		(*form_len)++;
		write(1, "%", 1);
	}
}

void	write_str(va_list *ap, char str, size_t *form_len)
{
	char	*c;
	int		i;

	c = &str;
	c = va_arg(*ap, char *);
	i = 0;
	if (!c)
	{
		write(1, "(null)", 6);
		*form_len += 6;
		return ;
	}
	while (c[i])
		i++;
	(*form_len) += i;
	write(1, c, i);
}
