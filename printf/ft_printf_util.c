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

t_format	*insert_deque(t_format *rear_node, char conversion_c, size_t idx)
{
	t_format	*front_node;

	front_node = (t_format *)malloc(sizeof(t_format));
	if (!front_node)
		return (0);
	if (rear_node)
	{
		front_node->front = NULL;
		front_node->rear = rear_node;
		rear_node->front = front_node;
		front_node->idx = idx;
		front_node->change_char = conversion_c;
	}
	else
	{
		front_node->rear = NULL;
		front_node->front = NULL;
		front_node->idx = idx;
		front_node->change_char = conversion_c;
	}
	return (front_node);
}

t_success	free_deque(t_format **front)
{
	t_format	*rear_node;

	if (!*front)
		return (ERROR);
	rear_node = 0;
	while (*front)
	{
		rear_node = (*front)->rear;
		free(*front);
		*front = rear_node;
	}
	*front = NULL;
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
