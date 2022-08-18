/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juha <juha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 03:00:07 by juha	           #+#    #+#             */
/*   Updated: 2022/05/25 16:52:21 by juha             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *form, ...)
{
	int			form_len;
	size_t		va_cnt;
	va_list		ap;

	if (!form)
		return (-1);
	form_len = ft_strlen(form);
	va_cnt = cnt_persent(form, form_len);
	if (va_cnt)
	{
		va_start(ap, form);
		return (print_char(&ap, (char *)form));
	}
	else if (form)
	{
		write(1, form, form_len);
		return (form_len);
	}
	return (-1);
}

t_success	write_format(va_list *ap, char input_c, size_t *form_len)
{
	if (input_c == 'c' || input_c == '%')
		write_c(ap, input_c, form_len);
	if (input_c == 's' )
		write_str(ap, input_c, form_len);
	else if (input_c == 'u')
		write_unsigned_int(ap, form_len);
	else if (input_c == 'x' || input_c == 'X')
		write_hexa_num(ap, input_c, form_len, -1);
	else if (input_c == 'd' || input_c == 'i')
		write_int(ap, form_len);
	else if (input_c == 'p')
		write_pointer(ap, form_len, -1);
	return (SUCCESS);
}

int	print_char(va_list *ap, char *form)
{
	size_t	form_len;
	size_t	i;
	size_t	max;

	i = 0;
	max = ft_strlen(form);
	form_len = 0;
	while (i < max)
	{
		if (form[i] == '%')
		{
			if (form[++i] == ' ')
				i++;
			if (chk_format(form[i]))
				write_format(ap, form[i], &form_len);
		}
		else
		{
			write(1, form + i, 1);
			form_len++;
		}
		i++;
	}
	va_end(*ap);
	return (form_len);
}

t_success	chk_format(char c)
{
	char	*conversion_c;

	conversion_c = "cspdiuxX%";
	while (*conversion_c)
	{
		if (c == *conversion_c++)
			return (INCLUSION);
	}
	return (EXCLUSION);
}

size_t	cnt_persent(const char *form, size_t form_len)
{
	size_t	i;
	size_t	cnt_persent;

	cnt_persent = 0;
	i = 0;
	while (i < form_len)
	{
		if (form[i] == '%')
		{
			i++;
			if (form[i] == ' ')
				i++;
			if (chk_format(form[i]))
				cnt_persent++;
		}
		i++;
	}
	return (cnt_persent);
}
