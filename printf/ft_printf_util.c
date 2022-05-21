/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_util.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: conteng <conteng@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 03:00:15 by conteng           #+#    #+#             */
/*   Updated: 2022/05/20 03:01:19 by conteng          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_strlen(const char	*s)
{
	size_t	cnt;

	cnt = 0;
	while (s[cnt])
		cnt++;
	return (cnt);
}

t_format	*push_node(t_format *bottom_node, char conversion_c, size_t idx)
{
	t_format	*top_node;

	top_node = (t_format *)malloc(sizeof(t_format));
	if (!top_node)
		return (error);
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
{ //check
	t_format *bottom_node;

	while (top)
	{
		bottom_node = top->bottom;
		free(top);
		top = bottom_node;
	}
	return (empty);
}