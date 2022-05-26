/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_util.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juha <juha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 03:00:15 by juha	           #+#    #+#             */
/*   Updated: 2022/05/25 16:52:16 by juha             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_format	*push_node(t_format *bottom_node, char conversion_c, size_t idx)
{
	t_format	*top_node;

	top_node = (t_format *)malloc(sizeof(t_format));
	if (!top_node)
		return (0);
	if (bottom_node)
	{
		top_node->top = NULL;
		top_node->bottom = bottom_node;
		bottom_node->top = top_node;
		top_node->idx = idx;
		top_node->change_char = conversion_c;
	}
	else
	{
		top_node->top = NULL;
		top_node->bottom = NULL;
		top_node->idx = idx;
		top_node->change_char = conversion_c;
	}
	return (top_node);
}

t_success	free_stack(t_format *top)
{
	t_format	*bottom_node;

	bottom_node = 0;
	while (top)
	{
		bottom_node = top->bottom;
		free(top);
		top = bottom_node;
	}
	return (EMPTY);
}

t_success	chk_persent(const char *form)
{
	int	i;

	i = 0;
	while (form[i])
	{
		if (form[i] == '%')
			return (SUCCESS);
		i++;
	}
	return (ERROR);
}
