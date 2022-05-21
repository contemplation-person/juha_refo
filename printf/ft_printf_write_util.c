/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_write_util.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: conteng <conteng@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 03:00:15 by conteng           #+#    #+#             */
/*   Updated: 2022/05/20 03:01:19 by conteng          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdarg.h>
#include <unistd.h>

void	write_str(va_list *ap, char c_or_str)
{
	int		address;
	char 	*c;
	int		cnt;

	cnt = 1;
	if (c_or_str == 'c')
	{
		*c = va_arg(*ap, int);
		printf("va_c : %c\n", *c);
		write(1, c, cnt);
	}
	else
	{
		while (cnt > 0)
		{
			c = va_arg(*ap, int);
			cnt = 0;
			printf("va_s : %s\n", *c);
			write(1, c, 1);
			cnt++;
		}
	}
}