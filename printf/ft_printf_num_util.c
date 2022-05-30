/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_num_util.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juha <juha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/22 23:03:12 by juha              #+#    #+#             */
/*   Updated: 2022/05/30 17:21:45 by juha             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	write_unsigned_int(va_list *ap, size_t *form_len)
{
	long long	num;
	long long	len;

	len = 0;
	num = va_arg(*ap, unsigned int);
	if (num < 0)
	{
		len = 1;
		num *= -1;
	}
	else if (num == 0)
		len = 1;
	ft_putnbr_fd(num, 1);
	while (num)
	{
		num /= 10;
		len++;
	}
	*form_len += len;
}

void	write_int(va_list *ap, size_t *form_len)
{
	long long	num;
	long long	len;

	len = 0;
	num = va_arg(*ap, int);
	if (num < 0)
		len = 1;
	else if (num == 0)
		len = 1;
	ft_putnbr_fd(num, 1);
	while (num)
	{
		num /= 10;
		len++;
	}
	*form_len += len;
}

void	write_hexa_num(va_list *ap, char c, size_t *form_len, long long is_last)
{
	long long	num;
	char		*form;

	if (is_last == 0)
		return ;
	num = is_last;
	if (is_last == -1)
		num = va_arg(*ap, unsigned int);
	form = "0123456789abcdef";
	if (c == 'X')
		form = "0123456789ABCDEF";
	write_hexa_num(ap, c, form_len, num / 16);
	write(1, form + num % 16, 1);
	*form_len += 1;
}

void	write_pointer(va_list *ap, size_t *form_len, long long is_last)
{
	unsigned long long	num;
	char				*form;

	if (is_last == 0)
		return ;
	num = is_last;
	if (is_last == -1)
	{
		num = (unsigned long long)va_arg(*ap, void *);
		write(1, "0x", 2);
		*form_len += 2;
		if (!num)
		{
			write(1, "0", 1);
			*form_len += 1;
			return ;
		}
	}
	form = "0123456789abcdef";
	write_pointer(ap, form_len, num / 16);
	if (is_last != 0)
	{
		write(1, form + num % 16, 1);
		*form_len += 1;
	}
}
