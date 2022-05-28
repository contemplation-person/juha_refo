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
	va_cnt = set_va_deque(&stack, (char *)form, form_len - 1);
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

t_format	*write_format(va_list *ap, t_format *rear, size_t *form_len)
{
	t_format	*new_rear;
	char		input_c;

	input_c = rear->change_char;
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
	new_rear = rear->front;
	free(rear);
	return (new_rear);
}

int	print_char(va_list *ap, t_format *top, char *form)
{
	size_t	form_len;
	size_t	i;

	i = 0;
	form_len = 0;
	while (*form)
	{
		if (top && *form == '%' && i + 1 == top->idx)
		{
			top = write_format(ap, top, &form_len);
			form += 2;
		}
		else
		{
			write(1, form++, 1);
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

int	set_va_deque(t_format	**deque, char *form, int form_len)
{
	t_format	*rear_node;
	size_t		va_cnt;
	int			i;

	i = 0;
	va_cnt = 0;
	rear_node = *deque;
	while (i < form_len)
	{
		if (form[i] == '%' && chk_format(form[i + 1]))
		{
			rear_node = insert_deque(rear_node, form[i++ + 1], form_len);
			if (!rear_node)
				return (free_deque(deque));
			va_cnt++;
		}
		else
			i++;
		*deque = rear_node;
	}
	return (va_cnt);
}
