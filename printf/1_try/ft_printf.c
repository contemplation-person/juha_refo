/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juha <juha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 03:00:07 by conteng           #+#    #+#             */
/*   Updated: 2022/05/25 14:37:02 by juha             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "unistd.h"

int	ft_printf(const char *form, ...)
{
	int			form_len;
	t_format	*stack;
	size_t		va_cnt;
	va_list		ap;

	if (!form)
		return (-1);
	stack = NULL;
	form_len = ft_strlen(form);
	va_cnt = set_va_stack(&stack, (char *)form, form_len - 1);
	if (va_cnt)
	{
		va_start(ap, form);
		return (print_char(&ap, stack, (char *)form, va_cnt));
	}
	if (form)
	{
		write(1, form, form_len);
		return (form_len);
	}
	return (-1);
}

t_format	*write_format(va_list *ap, t_format *top)
{
	t_format	*new_top;
	char		*conversion_c;
	char		input_c;

	input_c = top->change_char;
	conversion_c = "cspdiuxX";
	if (input_c == 'c' || input_c == 's' || input_c == '%')
		write_str(ap, input_c);
	else if (input_c == 'u')
		write_unsigned_int(ap);
	else if (input_c == 'x' || input_c == 'X')
		write_hexa_num(ap, input_c);
	else if (input_c == 'd' || input_c == 'i' \
	|| input_c == 'p')
		write_int(ap);
	new_top = top->bottom;
	free(top);
	return (new_top);
}

int	print_char(va_list *ap, t_format *top, char *form, size_t va_cnt)
{
	size_t	form_len;
//check ap? *ap
	form_len = 0;
	while (*form)
	{
		if (top && form_len == top->idx)
		{
			form_len += 2;
			form += 2;
			top = write_format(ap, top);
			continue ;
		}
		write(1, form++, 1);
		form_len++;
	}
	va_end(*ap);
	return (form_len - (va_cnt * 2));
}

t_success	chk_format(char c)
{
	char	*conversion_c;

	conversion_c = "cspdiuxX%";
	while (*conversion_c)
		if (c == *conversion_c++)
			return (inclusion);
	return (exclusion);
}

size_t	set_va_stack(t_format	**stack, char *form, size_t form_len)
{
	t_format	*top_node;
	size_t		va_cnt;
	size_t		max;

	top_node = *stack;
	max = form_len;
	va_cnt = 0;
	while (0 < --form_len + 1)
	{
		if (form_len != max && form[form_len] == '%' \
		&& chk_format(form[form_len + 1]))
		{
			top_node = push_node(top_node, form[form_len + 1], form_len);
			if (!top_node)
				return (free_stack(*stack));
			va_cnt++;
		}
		else
			continue ;
		*stack = top_node;
	}
	return (va_cnt);
}
/*
    1. 문자열에서 %의 위치를 찾는다.
    2. 문자열에서 %뒤의 문자를 확인한다.
    3. 문자열에서 %뒤의 문자가 나타날때마다 문자를 출력.
    4. 문자열에서 

	return value
	문자열의 갯수. \0포함하지 않음.
	출력 실패시 -1;
*/