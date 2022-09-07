/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juha <juha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 17:38:59 by juha              #+#    #+#             */
/*   Updated: 2022/09/07 15:55:52 by juha             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_stack_node	*pop(t_stack_node **top, int *cnt_stack)
{
	t_stack_node	*ret;

	ret = (*top);
	if (*cnt_stack == 1)
		(*top) = NULL;
	else if (*cnt_stack > 1)
	{
		(*top) = (*top)->next;
		(*top)->prev = ret->prev;
		ret->prev->next = (*top);
		ret->next = ret;
		ret->prev = ret;
	}
	else
		return (NULL);
	(*cnt_stack)--;
	return (ret);
}

t_bool	push(t_stack_node **target, t_stack_node *src, int *size)
{
	if (!src)
		return (FALSE);
	if (*size > 0)
	{
		(*target)->prev->next = src;
		src->next = (*target);
		src->prev = (*target)->prev;
		(*target)->prev = src;
	}
	else
		(*target) = src;
	(*size)++;
	return (TRUE);
}
