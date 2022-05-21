/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: conteng <conteng@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 03:00:07 by conteng           #+#    #+#             */
/*   Updated: 2022/05/20 03:00:28 by conteng          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdarg.h>

int ft_printf(const char *form, ...)
{
    int 		form_len;
    t_format	*stack;
	size_t		va_cnt;
	va_list		ap;

	if (!form)
		return (-1);
	stack = NULL;
	form_len = ft_strlen(form);
	va_cnt = set_va_arr(&stack, form, form_len - 1);
	if (va_cnt)
	{
		va_start(ap, va_cnt);
		return (print_char(ap, stack, form, va_cnt));
		// 구조체를 return 하면서 free를 해야함. / var_end// form_len - (var_cnt * 2)
	}
	return (-1);
}

t_format	*write_format(va_list ap, t_format *top)
{
	t_format	*new_top;
	char		*conversion_c = "cspdiuxX";

	if (top->change_char == 'c' && top->change_char == 's')
		write_str(ap, top->change_char);
	if (top->change_char == 'p')
		write_ponter(ap);
	if (top->change_char == 'd' && top->change_char == 'i')
		write_int(ap);
	if (top->change_char == 'u')
		write_unsigned_int(ap);
	if (top->change_char == 'x' && top->change_char == 'X')
		write_Hexa_num(ap);
	new_top = top->bottom;
	free(top);
	return (new_top);
}

int	print_char(va_list ap, t_format *top, char *form, size_t va_cnt)
{
	size_t	form_len;

	form_len = 0;
	while (*form)
	{
		if (top && form_len == top->idx)
		{
			form_len += 2;
			form + 2;
			top = write_format(ap, top);
			continue ;
		}
		write(1, form++, 1);
		form_len++;
	}
	return (form_len - (va_cnt * 2));
}

t_success	chk_format(char c)
{
	char	*conversion_c = "cspdiuxX";
	int		size;

	while (*conversion_c)
		if (c == *conversion_c++)
			return (inclusion);
	return (exclusion);
}

size_t	set_va_arr(t_format	**stack, char *form, size_t form_len)
{
	t_format	*top_node;
	size_t		va_cnt;
	size_t		max;

	top_node = stack;
	max = form_len;
	va_cnt = 0;
	while (-1 < --form_len)
	{
		if (form_len != max && form[form_len] == '%' && chk_format(form[form_len + 1]))
		{
			top_node = push_node(top_node, form[form_len + 1], form_len); //top node
			if (!top_node)
				return (free_stack(stack));
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