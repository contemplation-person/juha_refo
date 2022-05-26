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
	va_cnt = 0;
	form_len = ft_strlen(form);
	va_cnt = set_va_stack(&stack, (char *)form, form_len - 1);
	if (va_cnt)
	{
		va_start(ap, form);
		return (print_char(&ap, stack, (char *)form));
	}
	else if (chk_persent(form))
		return (-1);
	else if (form)
	{
		write(1, form, form_len);
		return (form_len);
	}
	return (-1);
}

t_format	*write_format(va_list *ap, t_format *top, size_t *form_len)
{
	t_format	*new_top;
	char		*conversion_c;
	char		input_c;

	input_c = top->change_char;
	conversion_c = "cspdiuxX";
	if (input_c == 'c' || input_c == 's' || input_c == '%')
		write_str(ap, input_c, form_len);
	else if (input_c == 'u')
		write_unsigned_int(ap, form_len);
	else if (input_c == 'x' || input_c == 'X')
		write_hexa_num(ap, input_c, form_len);
	else if (input_c == 'd' || input_c == 'i')
		write_int(ap, form_len);
	else if (input_c == 'p')
		write_pointer(ap, form_len);
	new_top = top->bottom;
	free(top);
	return (new_top);
}

int	print_char(va_list *ap, t_format *top, char *form)
{
	size_t	form_len;
	size_t	i;

	i = 0;
	form_len = 0;
	while (*form)
	{
		if (top && i++ == top->idx)
		{
			top = write_format(ap, top, &form_len);
			continue ;
		}
		else if (*form == '%')
		{
			form += 2;
			continue ;
		}
		write(1, form++, 1);
		form_len++;
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

size_t	set_va_stack(t_format	**stack, char *form, int form_len)
{
	t_format	*top_node;
	size_t		va_cnt;
	int			max;

	top_node = *stack;
	max = form_len;
	va_cnt = 0;
	while (-1 < --form_len)
	{
		if (form_len != max && form[form_len] == '%' \
		&& chk_format(form[form_len + 1]))
		{
			top_node = push_node(top_node, form[form_len + 1], form_len);
			if (!top_node)
				return (free_stack(*stack));
			va_cnt++;
		}
		else if (form[max] == '%' || \
		(!form_len && form[form_len] == '%' && form[form_len - 1] == '%'))
			return (free_stack(*stack));
		else
			continue ;
		*stack = top_node;
	}
	return (va_cnt);
}
